typedef enum {READ, WRITE} command_e;

typedef struct msg_s {
   short index;
   short cmd;
   unsigned int data;
} msg_t;


/* local function interface... */
void msg_handler(const void * const msg_data);
