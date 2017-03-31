/******************************************************************************************************
 *                                                                                                   
 * Name:    Communication interface Implementation                                                   
 * Author:  Bjorn Hoffmann                                                                           
 * Created: 18.03.2017                                                                               
 *                                                                                                   
 ******************************************************************************************************
 *                            Copyright 2017 (c) - Bjorn Hoffmann
 ******************************************************************************************************/

/* system includes... */
#include <assert.h>

/* local includes... */
#include "comint.h"

/* global data definitions... */

/* local function interface... */


/*****************************************************************************************************
 *                          public function implementation                                          
 *****************************************************************************************************/
/*****************************************************************************************************
 * Brief: Initialize the fieldbus implementation instance and virtual function table
 *
 * Input:
 * self         - com run time instance (maintaining instance and virtual function table)
 * init_func    - function pointer to init interface implementation
 * update_func  - function pointer to init interface implementation  
 * handler_func - function pointer to init interface implementation
 *
 * return       - pointer to com runtime instance
 */ 
comint_t * com_init(comint_t * const self, comint_init_f init_func, comint_update_f update_func, comint_handler_f handler_func) {
   assert(0 != self);
   assert(0 != init_func);
   assert(0 != update_func);
   assert(0 != handler_func);
   
   /* initialize com base class */
   self->sub = self;
   self->virt_funcs.init = init_func;
   self->virt_funcs.update = update_func;
   self->virt_funcs.handler = handler_func;
   
   /* initialize com sub class */
   self->virt_funcs.init(self);
   
   return self;
}


/*****************************************************************************************************
 * Brief: Update the process value on the fiedbus (Producer -> Consumer)
 *
 * Descr.: Caller must provide valid process value which is send on fieldbus acting as producer 
 *
 * Input:
 * self       - com run time instance (maintaining instance and virtual function table)
 * processval - process value
 */ 
void com_update(comint_t * const self, const float processval) {
   assert(0 != self);

   self->virt_funcs.update(self, processval);
}


/*****************************************************************************************************
 * Brief: Handle request messages from fieldbus clients (Server)
 *
 * Descr.: receive request message, proceed request, and send response
 *
 * Input:
 * self          - com run time instace (maintaining instance and virtual function table)
 * msg_hdlr_func - message handler provided by caller to procceed message 
 */ 
void com_msg_handler(comint_t * const self, msg_hdlr msg_hdlr_func) {
   assert(0 != self);
   
   self->virt_funcs.handler(self, msg_hdlr_func);
}

/*****************************************************************************************************
 *                            private function implementation                                          
 *****************************************************************************************************/

