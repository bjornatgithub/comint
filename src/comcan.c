/******************************************************************************************************
 *
 * Name:    CAN Fieldbus Implementation
 * Author:  Bjorn Hoffmann
 * Created: 18.03.2017
 * 
 ******************************************************************************************************
 *                                  Copyright 2017 (c) - Bjorn Hoffmann
 *****************************************************************************************************/
 
/* system includes... */
#include <stdio.h>
#include <string.h>
#include <assert.h>

/* local includes... */
#include "comcan.h"

/* global data definitions... */

/* local function interface... */

/*****************************************************************************************************
 *                          public function implementation                                          
 *****************************************************************************************************/
/*****************************************************************************************************
 * Brief: Initialize the CAN fieldbus implementation
 *
 * Descr.: Initialze run time structs and call CAN stack init function
 *
 * Note: To provide type safety checks for later calls to modul functions the modul identifier is
 *       copied to the runtime instance provided by the caller
 *
 * Input:
 * base         - can run time instace (maintaining base class and sub class data)
 */ 
void can_init(comint_t * const base) {
   comcan_t * const self = (comcan_t *)base->sub;
   
   assert(0 != base);
   assert(0 != base->sub);
   
   /* initialize module ID to provide type safety */
   base->mod_id = CAN_MOD_ID;
   
   /* initialize sub class data... */  
   can_msg_init(&self->prot.msg);
}


/*****************************************************************************************************
 * Brief: Update the process value on the fiedbus (Producer -> Consumer)
 *
 * Descr.: Caller must provide valid process value which is send on fieldbus acting as producer 
 *
 * Input:
 * base       - can run time instace (maintaining base class and sub class data)
 * processval - process value
 */ 
void can_update(comint_t * const base, const float processval) {
   comcan_t * const self = (comcan_t *)base->sub;
   
   assert(0 != base);
   assert(0 != base->sub);
   assert(CAN_MOD_ID == base->mod_id);
   
   /* send Process data object */
   can_pdo_transmit(processval);
}


/*****************************************************************************************************
 * Brief: Handle request messages from fieldbus clients (Server)
 *
 * Descr.: receive request message, proceed request, and send response
 *
 * Input:
 * base          - com run time instace (maintaining instance and virtual function table)
 * msg_hdlr_func - message handler provided by caller to procceed message 
 */
void can_msg_handler(comint_t * const base, msg_hdlr msg_hdlr_func) {
   comcan_t * const self = (comcan_t *)base->sub;   
   
   assert(0 != base);
   assert(0 != base->sub);
   assert(CAN_MOD_ID == base->mod_id);
   
   /* receive request from can bus client... */
   if (True == can_request_reveive(&self->prot.msg)) {      
   
      /* process can request message... */
      msg_hdlr_func(&self->prot.msg.data);
      
      /* send response to can bus client... */
      can_response_send(&self->prot.msg);
   }   
}
/*****************************************************************************************************
 *                            private function implementation                                          
 *****************************************************************************************************/

