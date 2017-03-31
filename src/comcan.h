/******************************************************************************************************
 *
 * Name:    CAN Fieldbus Interface
 * Author:  Bjorn Hoffmann
 * Created: 18.03.2017
 * 
 * Description: Implementation of CAN fieldbus protocols. Actually this is just a demo but
 * this modul could be used to abstract interfaces of a third party COTS CAN stack
 * 
 * Every protocol implementation have to feed the interface like listed below:
 * init        - initialize instance and virtual function table
 * update      - output of process value on the fieldbus
 * msg_handler - message handler server to process requests from fieldbus clients
 * 
 * Using this interface common code base can be shared with different fieldbus implementations
 *
 * Caller decides about fieldbus timing and so update frequency of process value on the fieldbus
 * Caller can provide a callback function to proceed message
 *
 ******************************************************************************************************
 *                                  Copyright 2017 (c) - Bjorn Hoffmann
 *****************************************************************************************************/
#ifndef __COMCAN_H
#define __COMCAN_H

/* module scope system includes... */
#include "comint.h"
#include "can.h"

/* module scope local includes... */

/*****************************************************************************************************
 *                          data interface declarations / type definitions
 *****************************************************************************************************/
/* Modul ID "CAN" in Hex */
#define CAN_MOD_ID 0x43414E 

/* CAN protocol run time struct */
typedef struct canprotocol_s {
   can_msg_t msg;
} canprotocol_t;

/* Com Sub class run time */
typedef struct comcan_s {
   comint_t base;          /* base class instance */
      
   canprotocol_t prot;     /* CAN protocol instance */

} comcan_t;


/*****************************************************************************************************
 *                                    function interface 
 *****************************************************************************************************/
void can_init(comint_t * const base);
void can_update(comint_t * const base, const float processval);
void can_msg_handler(comint_t * const base, msg_hdlr msg_hdlr_func);

#endif /* __COMCAN_H */

