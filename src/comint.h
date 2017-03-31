/******************************************************************************************************
 *
 * Name:    Communication interface
 * Author:  Bjorn Hoffmann
 * Created: 18.03.2017
 * 
 * Description: Communication interface to support fieldbus protocols like
 * CAN, EtherCAT, EthernetIP, J1939
 * 
 * This is an abstract Interface and every protocol implementation needs to implement interface 
 * listed below:
 * init        - initialize instance and virtual function table
 * update      - output of process value on the fieldbus
 * msg_handler - message handler server to process requests from fieldbus clients
 * 
 * Using this interface common code base can be shared with different fieldbus implementations
 *
 * Caller decides about fieldbus timing and so update frequency of process value on the fieldbus
 *
 * Caller can provide a callback function to proceed message
 *
 ******************************************************************************************************
 *                            Copyright 2017 (c) - Bjorn Hoffmann
 *****************************************************************************************************/
 #ifndef __COMINT_H
 #define __COMINT_H
 
/* module scope system includes... */
/* module scope local includes... */


/*****************************************************************************************************
 *                          data interface declarations / type definitions
 *****************************************************************************************************/
/* forward reference for com runtime struct */
typedef struct comint_s comint_t;

/* message handler callback interface */
typedef void (*msg_hdlr) (const void * const msg_data);

/* virtual function interface */ 
typedef void (*comint_init_f) (comint_t * const);
typedef void (*comint_update_f) (comint_t * const, const float);
typedef void (*comint_handler_f) (comint_t * const, msg_hdlr msg_hdlr_func);

/* virtual function table */
typedef struct comint_virtf_s {
   comint_init_f    init;        /* sub class function to init modul */
   comint_update_f  update;      /* sub class function to update process value on fieldbus */
   comint_handler_f handler;     /* sub class function to handle request from fieldbus clients */
} comint_virtf_t;

/* com runtime struct */
struct comint_s {
    void         * sub;          /* pointer to sub class */
    comint_virtf_t virt_funcs;   /* virtual function table */
    unsigned int   mod_id;       /* ID to support type safety */
}; //comint_t


/*****************************************************************************************************
 *                                    function interface 
 *****************************************************************************************************/
comint_t * com_init(comint_t * const self, comint_init_f init_func, comint_update_f update_func, comint_handler_f handler_func);
void com_update(comint_t * const self, const float processval);
void com_msg_handler(comint_t * const self, msg_hdlr msg_hdlr_func);

#endif /* __COMINT_H */

