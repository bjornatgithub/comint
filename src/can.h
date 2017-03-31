/******************************************************************************************************
 *
 * Name:    CAN Driver interface
 * Author:  Bjorn Hoffmann
 * Created: 29.03.2017
 * 
 * Description: Implementation of CAN protocol 
 * 
 * Note: This is a pseudo demo implementaion, which in a real world could consist of CAN Stack Software 
 * and HW CAN driver.
 *
 * Like with CANopen it is assumed to have two types of messages:
 * producer/consumer service to deplay process data on CAN bus
 * client/server service to adjust settings in server device (this entity)
 *
 ******************************************************************************************************
 *                            Copyright 2017 (c) - Bjorn Hoffmann
 *****************************************************************************************************/
 #ifndef __CAN_H
 #define __CAN_H
 
/* module scope system includes... */
/* module scope local includes... */


/*****************************************************************************************************
 *                          data interface declarations / type definitions
 *****************************************************************************************************/
#define CAN_DATA_LEN 8U
 
typedef struct can_hdr_s {
   unsigned short identifier;
   unsigned short crc;
} can_hdr_t;

typedef struct can_msg_s {
   can_hdr_t header;
   char      data[CAN_DATA_LEN];
} can_msg_t;

typedef enum {False, True} BOOL;



/*****************************************************************************************************
 *                                    function interface 
 *****************************************************************************************************/
void can_pdo_transmit(const float processval);

BOOL can_request_reveive(can_msg_t * const msg);
void can_response_send(const can_msg_t * const msg);

void can_msg_init(can_msg_t * const msg);


#endif /* __CAN_H */

