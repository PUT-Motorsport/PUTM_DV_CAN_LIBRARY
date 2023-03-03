#include <iostream>
#include "Inc/putm_can_interface.hpp"

using namespace PUTM_CAN;

int main(int argc, char *argv[]){
    CAN can;
    can.connect();

    Apps_main apps_frame;

    apps_frame = {
        .pedal_position = 0,
        .counter = 1,
        .position_diff = 2,
        .device_state = Apps_states::Power_up
    };

    can.transmit(apps_frame);
    can.receive(apps_frame);
    can.receive_rtr(apps_frame);

    return 0;
}