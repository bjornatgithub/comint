/******************************************************************************************************
 *
 * Name:    Operating Software
 * Author:  Bjorn Hoffmann
 * Created: 18.03.2017
 *
 * Description: This software realizes a super loop to frequently update a process value on the fieldbus
 *              Different Fieldbus communication can be used supported by the abstract com interface
 * 
 ******************************************************************************************************
 *                                  Copyright 2017 (c) - Bjorn Hoffmann
 *****************************************************************************************************/
 /* system includes... */
#include <stdio.h>

/* local includes... */
#include "comcan.h"
#include "message.h"

/* global data definitions... */


/*****************************************************************************************************
 *                          public function implementation                                          
 *****************************************************************************************************/
int main() {
   float process_val = 0.0;
   
   comcan_t com_can;     
   comint_t * com = com_init((comint_t *)&com_can, can_init, can_update, can_msg_handler);
   
   while(1) {            
      /* update process value */
      process_val += 0.01;
      
      /* update process val on fieldbus */
      com_update(com, process_val);
            
      /* handle requests of fieldbus clients */
      com_msg_handler(com, msg_handler);
   }

   return 0;
}


/*****************************************************************************************************
 *                            private function implementation                                          
 *****************************************************************************************************/

