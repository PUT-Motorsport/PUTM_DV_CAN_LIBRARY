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

    BMS_HV_main bms_hv_frame;
    BMS_LV_main bms_lv_frame;
    Apps_main apps_frame;
    while (1)
    {
        if (can.receive(apps_frame, NO_TIMEOUT) != CanState::CAN_OK)
        {
            std::cout << "Error" << std::endl;
            return 1;
        }
        if (can.receive(bms_lv_frame, NO_TIMEOUT) != CanState::CAN_OK)
        {
            std::cout << "Error" << std::endl;
            return 1;
        }
        if (can.receive(bms_hv_frame, NO_TIMEOUT) != CanState::CAN_OK)
        {
            std::cout << "Error" << std::endl;
            return 1;
        }
    }

    // /* TRANSMIT DATA */
    // apps_frame = {
    //     .pedal_position = 1,
    //     .counter = 2,
    //     .position_diff = 3,
    //     .device_state = Apps_states::Sensor_Implausiblity};
    // if (can.transmit(apps_frame) != CanState::CAN_OK)
    // {
    //     std::cout << "Error" << std::endl;
    //     return 1;
    // }

    return 0;
}
