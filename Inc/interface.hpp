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

struct __attribute__ ((packed)) Device{
    Device(uint16_t can_id, uint16_t can_dlc) : can_id(can_id), can_dlc(can_dlc) {}
    const uint16_t can_id;
    const uint16_t can_dlc;
};
struct __attribute__ ((packed)) Our_device : Device {
    Our_device() : Device(0x87, sizeof(Our_device)-sizeof(Device)){}
    int16_t speed_x; // rotary speed x
    int16_t speed_y; // rotary speed y
    int16_t speed_z; // rSotary speed z
};


namespace PUTM_CAN
{
    class CAN
    {S
    public:
        CAN() = default;
        int8_t connect(const char *ifname = "slcan0");
        int8_t transmit(const uint16_t &can_id, const uint8_t &can_dlc, const char *tx_data);
        int8_t transmit(Device &dev);

        int8_t receive(const uint16_t &can_id, const uint8_t &can_dlc, char *rx_data);
        int8_t receive_rtr(const uint16_t &can_id, const uint8_t &can_dlc, char *rx_data);
        int8_t disconnect();
    private:
        int private_socket;
    };
}

#endif // INTERFACE