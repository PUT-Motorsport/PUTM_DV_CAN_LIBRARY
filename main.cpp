#include <iostream>
#include "Inc/putm_can_interface.hpp"

using namespace PUTM_CAN;

int main(int argc, char *argv[])
{
    CAN can;
    can.connect();

    // Apps_main apps_frame;

    // apps_frame = {
    //     .pedal_position = 1,
    //     .counter = 2,
    //     .position_diff = 3,
    //     .device_state = Apps_states::Sensor_Implausiblity
    // };
    
    // can.transmit(apps_frame);
    // can.receive(apps_frame);
    // can.receive_rtr(apps_frame);

    can_frame random_frame;

    can.structure_receive_random(random_frame);

    std::cout<<(int)random_frame.can_id;
    std::cout<<(int)random_frame.data[0];



    return 0;
}