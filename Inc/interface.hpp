#ifndef INTERFACE
#define INTERFACE

#include <string>

#include "CanHeaders/PM08-CANBUS-APPS.hpp"
#include "CanHeaders/PM08-CANBUS-AQ_CARD.hpp"
#include "CanHeaders/PM08-CANBUS-BMS_HV.hpp"
#include "CanHeaders/PM08-CANBUS-BMS_LV.hpp"
#include "CanHeaders/PM08-CANBUS-DASH.hpp"
#include "CanHeaders/PM08-CANBUS-DV.hpp"
#include "CanHeaders/PM08-CANBUS-LAP_TIMER.hpp"
#include "CanHeaders/PM08-CANBUS-SF.hpp"
#include "CanHeaders/PM08-CANBUS-STEERING_WHEEL.hpp"
#include "CanHeaders/PM08-CANBUS-SW_SENSOR.hpp"
#include "CanHeaders/PM08-CANBUS-TC.hpp"
#include "CanHeaders/PM08-CANBUS-TELEMETRY.hpp"
#include "CanHeaders/PM08-CANBUS-WHEELTEMP.hpp"
#include "CanHeaders/PM08-CANBUS-YAWPROBE.hpp"

namespace PUTM_CAN
{
    class CAN
    {
    public:
        CAN() = default;
        int8_t connect(const char *ifname = "slcan0");
        int8_t transmit(const uint16_t &can_id, const uint8_t &can_dlc, const char *tx_data);
        int8_t receive(const uint16_t &can_id, const uint8_t &can_dlc, char *rx_data);
        int8_t receive_rtr(const uint16_t &can_id, const uint8_t &can_dlc, char *rx_data);
        int8_t disconnect();
    private:
        int private_socket;
    };
}

#endif // INTERFACE