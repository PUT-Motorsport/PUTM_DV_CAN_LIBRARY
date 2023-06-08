#include <iostream>
#include "../Inc/putm_can_interface.hpp"

using namespace PUTM_CAN;

int main()
{
    /* CONNECT TO THE CAN INTERFACE */
    CAN can;
    if (can.connect("slcan0") != CanState::CAN_OK)
    {
        std::cout << "Error" << std::endl;
        return 1;
    }
    
    /* RECEIVE DATA */
    Apps_main apps_frame;
    if(can.receive(apps_frame, NO_TIMEOUT) != CanState::CAN_OK)
    {
        std::cout << "Error" << std::endl;
        return 1;
    }
    std::cout << apps_frame.pedal_position << std::endl;
    

    /* TRANSMIT DATA */
    apps_frame = {
        .pedal_position = 1,
        .counter = 2,
        .position_diff = 3,
        .device_state = Apps_states::Sensor_Implausiblity};
    if(can.transmit(apps_frame) != CanState::CAN_OK)
    {
        std::cout << "Error" << std::endl;
        return 1;
    }

    return 0;
}