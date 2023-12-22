#include "mqtt_freertos.h"
#include "fsl_debug_console.h"
#include "lwip/tcpip.h"
#include "fsl_silicon_id.h"
#include "mqtt.h"
#include "fsl_lpuart.h"


#define  SERVER_HOST "sems.ses-tech.vn"
#define  TOP_PIC  "SES_topic/10"

/*! @brief MQTT server port number. */

#define  SERVER_PORT 1883


/*! @brief Stack size of the temporary lwIP initialization thread. */
#define  STACKSIZE 1024

/*! @brief Priority of the temporary lwIP initialization thread. */
#define INIT_THREAD_PRIO DEFAULT_THREAD_PRIO

/*! @brief Stack size of the temporary initialization thread. */
#define APP_THREAD_STACKSIZE 1024

/*! @brief Priority of the temporary initialization thread. */
#define APP_THREAD_PRIO DEFAULT_THREAD_PRIO

static char client_id [(SILICONID_MAX_LENGTH * 2) + 5] ;
static ip4_addr_t mqtt_ip ;
static mqtt_client_t *  client ;
static struct mqtt_connect_client_info_t  client_info  = {
	    .client_id   =  client_id ,
	    .client_user = "mqtt-test",
	    .client_pass = "mqtt-test",
	    .keep_alive  = 100,
	    .will_topic  = NULL,
	    .will_msg    = NULL,
	    .will_qos    = 0,
	    .will_retain = 0,

};

static uint8_t connected = 0 ;


static void generate_client_id (void ) ;
static void app_thread (void *) ;
static void connect_to_server (void * )  ;
void  mqtt_connection_cb (mqtt_client_t *client, void *arg, mqtt_connection_status_t status);
void mqtt_sub_topic   () ;
void   incoming_publish_cb_t (void *arg, const char *topic, u32_t tot_len);  // callback , tot_len is Total length of publish data
void   incoming_data_cb_t  (void *arg, const u8_t *data, u16_t len, u8_t flags); //callback with   fragments of data, flags is signal of finish fragment
void sub_cb_t (void *arg, err_t err) ;

void incoming_publish_cb_t  (void *arg, const char *topic, u32_t tot_len)  {
	PRINTF ("received from %s  \n\r " , topic  ) ;
}
void   incoming_data_cb_t  (void *arg, const u8_t *data, u16_t len, u8_t flags){
	//PRINTF ("%s \r\n" ,data) ;
	if (flags == MQTT_DATA_FLAG_LAST ) {
		LPUART_WriteBlocking(LPUART1, data, len ) ;
	}
}
void sub_cb_t (void *arg, err_t err) {
	if (err == ERR_OK) {
		PRINTF ("Subscribed \n\r ") ;
	}else {
		PRINTF (" Err Subscribed \r\n ") ;
	}
}
void mqtt_sub_topic () {
	mqtt_set_inpub_callback (client , incoming_publish_cb_t ,incoming_data_cb_t , NULL ) ;
	err_enum_t err  = mqtt_subscribe  (client , TOP_PIC , 0 , &sub_cb_t , NULL  );
	if (err == ERR_OK) {
		PRINTF ("Subscribing \r\n ") ;
	}else {
		PRINTF (" Err Subscribing %d \r\n  " , err) ;
	}

}
//call when status changes
void mqtt_connection_cb (mqtt_client_t *client, void *arg, mqtt_connection_status_t status) {
	connected = (status == MQTT_CONNECT_ACCEPTED) ? 1 : 0 ;
	switch (status) {

	case MQTT_CONNECT_ACCEPTED :
		PRINTF ("MQTT_CONNECT_ACCEPTED \n\r") ;
		mqtt_sub_topic () ;
		break;
	  /** Refused protocol version */
	case  MQTT_CONNECT_REFUSED_PROTOCOL_VERSION :
		PRINTF ("MQTT_CONNECT_REFUSED_PROTOCOL_VERSION \n\r") ;
		break ;
	  /** Refused identifier */
	case  MQTT_CONNECT_REFUSED_IDENTIFIER :
		PRINTF ("MQTT_CONNECT_REFUSED_IDENTIFIER \n\r") ;
		break ;
	  /** Refused server */
	case MQTT_CONNECT_REFUSED_SERVER :
		PRINTF ("MQTT_CONNECT_REFUSED_SERVER \n\r") ;
		break ;
	  /** Refused user credentials */
	case MQTT_CONNECT_REFUSED_USERNAME_PASS :
		PRINTF ("MQTT_CONNECT_REFUSED_USERNAME_PASS \n\r") ;
		break ;
	  /** Refused not authorized */
	case   MQTT_CONNECT_REFUSED_NOT_AUTHORIZED_:
		PRINTF ("MQTT_CONNECT_REFUSED_USERNAME_PASS \n\r") ;
		break ;
	  /** Disconnected */
	case MQTT_CONNECT_DISCONNECTED :
		PRINTF ("MQTT_CONNECT_DISCONNECTED \n\r") ;
		sys_timeout(1000 ,connect_to_server , arg) ;
		break ;
	  /** Timeout */
	case MQTT_CONNECT_TIMEOUT :
		PRINTF ("MQTT_CONNECT_TIMEOUT \n\r") ;
		sys_timeout(1000 ,connect_to_server , arg) ;
		break ;
	}
}


static void connect_to_server (void * ctx )  {
	PRINTF ("Connecting to %s \r\n" ,ipaddr_ntoa (&mqtt_ip) ) ;
	mqtt_client_connect(client, &mqtt_ip, SERVER_PORT , mqtt_connection_cb, NULL , &client_info) ;


}
void app_thread (void * ) {
	err_enum_t  err = netconn_gethostbyname(SERVER_HOST ,  &mqtt_ip) ;
	if (err == ERR_OK) {
		tcpip_callback(connect_to_server, NULL ) ;
	}


	vTaskDelete(NULL) ;

}
static void generate_client_id(void) {
	uint16_t  idx = 0 ;
	client_id [idx] = 's' ;
	client_id [idx++] = 'e' ;
	client_id [idx++] = 's' ;
	client_id [idx++] =  '_' ;
	uint8_t id_silicon [SILICONID_MAX_LENGTH] ;
	uint8_t id_len = sizeof (id_silicon) ;
	  SILICONID_GetID(id_silicon , SILICONID_MAX_LENGTH-1 );
    for (int i = (int)id_len - 1; i >= 0; i--)
    {
        uint8_t value    = id_silicon [i];
        client_id[idx++] =  value >> 4;
        client_id[idx++] =  value & 0xAA;

    }
	client_id[idx] = '\0' ;
}
void mqtt_freertos_run_sub_thread (void) {
	mqtt_ip.addr = 0 ;
	generate_client_id();
	LOCK_TCPIP_CORE() ;
	client = mqtt_client_new() ;
	UNLOCK_TCPIP_CORE() ;
	if(sys_thread_new("sub thread", app_thread, NULL , STACKSIZE , INIT_THREAD_PRIO) == NULL  ){
		LWIP_ASSERT("mqtt_freertos_run_sub_thread: Task creation failed.", 0);
	}


}
