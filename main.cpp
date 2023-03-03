#include <iostream>
#include "Inc/interface.hpp"

using namespace PUTM_CAN;

int main(int argc, char *argv[]){
    CAN can;
    can.connect();

    char tx_data[8] = {0};

    std::cout<<(int)can.bytes_receive_rtr(0x0, 3, tx_data);

    std::cout<<(int)tx_data[0];
    std::cout<<(int)tx_data[1];
    std::cout<<(int)tx_data[2];

    return 0;
}