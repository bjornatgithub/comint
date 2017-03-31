#include "gtest/gtest.h"

#include "comcan.h"
//#include "message.h"

TEST(com, init_func) {
   
   comcan_t com_can;     
   comint_t * com = com_init((comint_t *)&com_can, can_init, can_update, can_msg_handler);
   
   EXPECT_EQ(com,(comint_t *)&com_can);
}

int main(int argc, char **argv) {
   ::testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}
