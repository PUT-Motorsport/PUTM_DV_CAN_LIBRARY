#include <iostream>
#include "Inc/interface.hpp"

using namespace PUTM_CAN;

int main(int argc, char *argv[]){
    
    CAN can;
    can.connect();

    Apps_main apps_transmit{
        .pedal_position = 1200,
        .counter = 0,
        .position_diff = 0,
        .device_state = Apps_states::Normal_operation,
    };

    char data[8] = {0};

    // Apps_main apps_receive;
    // while(true){
    //     can.transmit(APPS_MAIN_CAN_ID, APPS_MAIN_CAN_DLC, reinterpret_cast<char*>(&apps_transmit));
    // }

    // while(true){
    // can.receive(1U, APPS_MAIN_CAN_DLC, reinterpret_cast<char*>(&apps_receive));
    //     printf("%d: %d\n", APPS_MAIN_CAN_ID, apps_receive.pedal_position);
    //     printf("%d: %d\n", APPS_MAIN_CAN_ID, apps_receive.counter);
    //     printf("%d: %d\n", APPS_MAIN_CAN_ID, apps_receive.position_diff);
    //     printf("%d: %d\n", APPS_MAIN_CAN_ID, apps_receive.device_state);
    // }
    while(true){
    can.receive_rtr(10U, 8U, data);
    printf("%d,%d,%d,%d,%d,%d,%d,%d\n", data[0], data[1], data[2], data[3], data[4], data[5], data[6], data[7]);
    }
    // printf("%d: %d\n", APPS_MAIN_CAN_ID, apps_transmit.counter);
    // printf("%d: %d\n", APPS_MAIN_CAN_ID, apps_transmit.position_diff);
    // printf("%d: %d\n", APPS_MAIN_CAN_ID, apps_transmit.device_state);
    // std::cout<< apps_transmit.counter <<"\n";

    return 0;
}