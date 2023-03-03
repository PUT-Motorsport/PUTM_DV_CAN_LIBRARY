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
        int8_t connect(const char *ifname = "slcan0\n");
        int8_t disconnect();

        int8_t bytes_transmit(const uint16_t &can_id, const uint8_t &can_dlc, const char *tx_data);
        int8_t bytes_receive(const uint16_t &can_id, const uint8_t &can_dlc, char *rx_data);
        int8_t bytes_receive_rtr(const uint16_t &can_id, const uint8_t &can_dlc, char *rx_data);

        template <typename T>
        int8_t transmit(T const &tx_frame)
        {
            if(can_id<T> == INVALID_CAN_ID)
            {
                return -1;
            }
            struct can_frame frame;
            frame.can_id = can_id<T>;
            frame.can_dlc = sizeof(T);
            std::memcpy(frame.data, &tx_frame, sizeof(T));
            if (write(private_socket, &frame, sizeof(struct can_frame)) < 0)
            {
                return -2;
            }
            return 0;
        }

        template <typename T>
        int8_t receive(T &rx_frame)
        {
            if(can_id<T> == INVALID_CAN_ID)
            {
                return -1;
            }
            struct can_frame frame;
            struct can_filter filter
            {
                .can_id = can_id<T>, .can_mask = CAN_SFF_MASK
            };
            if (setsockopt(private_socket, SOL_CAN_RAW, CAN_RAW_FILTER, &filter, sizeof(filter)) != 0)
            {
                return -2;
            }
            if (read(private_socket, &frame, sizeof(struct can_frame)) < sizeof(can_frame))
            {
                return -3;
            }
            std::memcpy(&rx_frame, frame.data, sizeof(T));
            return 0;
        }

        template <typename T>
        int8_t receive_rtr(T &rx_frame)
        {
            if(can_id<T> == INVALID_CAN_ID)
            {
                return -1;
            }
            struct can_frame frame;
            frame.can_id = can_id<T> | CAN_RTR_FLAG;
            if(write(private_socket, &frame, sizeof(struct can_frame)) < 0)
            {
                return -2;
            }
            if(receive(rx_frame)!=0)
            {
                return -3;
            }
            return 0;
        }
    };
}

#endif // PUTM_CAN_INTERFACE