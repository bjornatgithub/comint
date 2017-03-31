/******************************************************************************************************
 *                                                                                                   
 * Name:    CAN Driver Implementation
 * Author:  Bjorn Hoffmann                                                                           
 * Created: 18.03.2017
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

/* local function interface... */


/*****************************************************************************************************
 *                          public function implementation                                          
 *****************************************************************************************************/
/*****************************************************************************************************
 * Brief: produce process value updates on can bus
 *
 * Descr: Converts process value in network byte format and encapsulates it into CAN telegram
 *
 * Input:
 * processval - valid process value (caller is responisble for validity)
 */
void can_pdo_transmit(const float processval) {   
   /* TODO: implement... */
   printf("produce %f on can bus\n");
}


/*****************************************************************************************************
 * Brief: server (this entity) receives request message from can bus client
 *
 * Descr: CAN telegram is analysed and converted from network byte order to logical information
 * 
 * Output:
 * msg - logical can telegram (not network byte order) for interpretation by caller 
 */
BOOL can_request_reveive(can_msg_t * const msg) {   
   /* TODO: implement... */
   printf("receive request\n");   
}


/*****************************************************************************************************
 * Brief: server (this entity) sends response message to can bus client
 *
 * Descr: CAN telegram is analysed and converted from logical information to network byte order
 * 
 * Input:
 * msg - logical can telegram (not network byte order) for interpretation by caller 
 */
void can_response_send(const can_msg_t * const msg) {   
   /* TODO: implement... */
   printf("send response\n");
}


/*****************************************************************************************************
 * Brief: initialize message with 0
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

