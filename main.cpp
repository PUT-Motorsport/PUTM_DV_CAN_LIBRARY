#include <iostream>
#include "Inc/putm_can_interface.hpp"

using namespace PUTM_CAN;

int main(int argc, char *argv[]){
    CAN can;
    can.connect();

    AQ_acceleration aq_acceleration;

    aq_acceleration.acc_x = 1;
    aq_acceleration.acc_y = 2;
    aq_acceleration.acc_z = 3;

    can.transmit(aq_acceleration);

    // char tx_data[8] = {0};

    // std::cout<<(int)can.bytes_receive_rtr(0x0, 3, tx_data);

    // std::cout<<(int)tx_data[0];
    // std::cout<<(int)tx_data[1];
    // std::cout<<(int)tx_data[2];

    return 0;
}