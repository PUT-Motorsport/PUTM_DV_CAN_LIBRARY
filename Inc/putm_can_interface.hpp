#ifndef PUTM_CAN_INTERFACE
#define PUTM_CAN_INTERFACE

#include <string>
#include "putm_can_id_templates.hpp"

#include <net/if.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <linux/can.h>
#include <unistd.h>
#include <string.h>
#include <cstring>
#include <linux/can/raw.h>
#include <iostream>


namespace PUTM_CAN
{
    class CAN
    {
    private:
        int private_socket;
    
    public:
        CAN() = default;
        int8_t connect(const char *ifname = "slcan0");
        int8_t disconnect();

        int8_t bytes_transmit(const uint16_t &can_id, const uint8_t &can_dlc, const char *tx_data);
        int8_t bytes_receive(const uint16_t &can_id, const uint8_t &can_dlc, char *rx_data);
        int8_t bytes_receive_rtr(const uint16_t &can_id, const uint8_t &can_dlc, char *rx_data);


        template <typename T>
        int8_t transmit(T const &tx_frame){
            struct can_frame frame;
            frame.can_id = can_id<T>;
            frame.can_dlc = sizeof(T);
            std::memcpy(frame.data, &tx_frame, sizeof(T));
            if (write(private_socket, &frame, sizeof(struct can_frame)) < 0)
            {
                return -1;
            }
            return 0;
        }


        template <typename T>
        int8_t receive(T const &rx_frame);



        template <typename T>
        int8_t receive_rtr(T const &rx_frame);

    };
}

#endif // PUTM_CAN_INTERFACE