#include <iostream>
#include "Inc/putm_can_interface.hpp"

using namespace PUTM_CAN;

int main(int argc, char *argv[]){
    CAN can;
    can.connect();

    Apps_main apps_frame;

    can.receive(apps_frame);

    // char tx_data[8] = {0};

    std::cout<<(int)apps_frame.counter;

    // std::cout<<(int)tx_data[0];
    // std::cout<<(int)tx_data[1];
    // std::cout<<(int)tx_data[2];

    return 0;
}