/******************************************************************************************************
 *                                                                                                   
 * Name:    CAN Driver Mock                                                   
 * Author:  Bjorn Hoffmann                                                                           
 * Created: 18.03.2017
 *
 * Description: Stubs of real implementation for testing                                                                               
 *                                                                                                   
 ******************************************************************************************************
 *                            Copyright 2017 (c) - Bjorn Hoffmann
 ******************************************************************************************************/

/* system includes... */
#include <stdio.h>

/* local includes... */
#include "can.h"

/* global data definitions... */

/* test input */
unsigned int tstin_msg_data = 0;

/* test results */
unsigned int tstres_msg_data = 0;
float tstres_process_val = 0.0;

/* local function interface... */


/*****************************************************************************************************
 *                          public function implementation                                          
 *****************************************************************************************************/
/*****************************************************************************************************
 * Brief: Stub for pdo transmit
 */ 
void can_pdo_transmit(const float processval) {
   tstres_process_val = processval;
   printf("produce %f on can bus\n");
}


/*****************************************************************************************************
 * Brief: Stub for request receive
 */ 
BOOL can_request_reveive(can_msg_t * const msg) {   
   //msg->data = tstin_msg_data;
   printf("receive request ");
   
   for (int i; i < CAN_DATA_LEN; i++) {
      printf("%x", msg->data[i]);
   }
   
   printf("\n");
   
   return True;
}


/*****************************************************************************************************
 * Brief: Stub for response send
 */ 
void can_response_send(const can_msg_t * const msg) {
   //tstres_msg_data = msg->data
   
   printf("send response ");
   
   for (int i; i < CAN_DATA_LEN; i++) {
      printf("%x", msg->data[i]);
   }
   
   printf("\n");
}


/*****************************************************************************************************
 * Brief: Stub to initialize message
 *
 * Input:
 * msg - logical can telegram 
 */
void can_msg_init(can_msg_t * const msg) {
   /* TODO: implement... */
   printf("initialize message\n");
}

/*****************************************************************************************************
 *                            private function implementation                                          
 *****************************************************************************************************/

