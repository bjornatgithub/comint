#include <stdio.h>

#include "message.h"

void msg_handler(const void * const msg_data) {
   msg_t * msg = (msg_t *)msg_data;
     
   /* TODO: implement */
     
   if (READ == (command_e)msg->cmd) {
         printf("read concrete message here...\n");
   }
   
   if (WRITE == (command_e)msg->cmd) {
         printf("write concrete message here...\n");
   }
}

