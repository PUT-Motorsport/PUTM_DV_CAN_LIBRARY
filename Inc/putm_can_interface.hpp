#ifndef PUTM_CAN_INTERFACE
#define PUTM_CAN_INTERFACE

#include <string>
#include "putm_can_id_templates.hpp"


namespace PUTM_CAN
{
    class CAN
    {
    public:
        CAN() = default;
        int8_t connect(const char *ifname = "slcan0");
        int8_t disconnect();

        template <typename T>
        int8_t transmit();
        template <typename T>
        int8_t receive();
        template <typename T>
        int8_t receive_rtr();

        int8_t bytes_transmit(const uint16_t &can_id, const uint8_t &can_dlc, const char *tx_data);
        int8_t bytes_receive(const uint16_t &can_id, const uint8_t &can_dlc, char *rx_data);
        int8_t bytes_receive_rtr(const uint16_t &can_id, const uint8_t &can_dlc, char *rx_data);

    private:
        int private_socket;
    };
}

#endif // PUTM_CAN_INTERFACE