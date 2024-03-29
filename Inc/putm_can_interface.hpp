#pragma once

#include <cstring>
#include <iostream>

#include <net/if.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <linux/can.h>
#include <unistd.h>
#include <string.h>
#include <cstring>
#include <linux/can/raw.h>

#include "putm_can_id_templates.hpp"

namespace PUTM_CAN
{
    constexpr time_t NO_TIMEOUT = 0;

    enum class CanState : uint8_t
    {
        CAN_OK,
        CAN_SOCKET_ERROR,
        CAN_BIND_ERROR,
        CAN_IOCTL_ERROR,
        CAN_SET_MASK_ERROR,
        CAN_SET_TIMEOUT_ERROR,
        CAN_WRITE_ERROR,
        CAN_READ_ERROR,
        CAN_CLOSE_ERROR
    };

    class CAN
    {
    public:
        inline CAN() = default;

        inline CanState connect(const char *ifname);
        inline CanState disconnect();

        inline CanState structure_receive_random(can_frame &rx_frame, const time_t timeout_in_seconds);

        template <typename T>
        inline CanState transmit(T const &tx_frame);
        template <typename T>
        inline CanState receive(T &rx_frame, const time_t timeout_in_seconds);
        template <typename T>
        inline CanState receive_rtr(T &rx_frame, const time_t timeout_in_seconds);

        inline CanState bytes_transmit(const uint16_t &can_id, const uint8_t &len, const char *tx_data);
        inline CanState bytes_receive(const uint16_t &can_id, const uint8_t &len, char *rx_data);
        inline CanState bytes_receive_rtr(const uint16_t &can_id, const uint8_t &len, char *rx_data);

    private:
        int private_socket;
    };

}

namespace PUTM_CAN
{
    template <typename T>
    inline CanState CAN::transmit(T const &tx_frame)
    {
        static_assert(can_id<T> != INVALID_CAN_ID, "Can id has not been specified");

        can_frame frame;
        frame.can_id = can_id<T>;
        frame.len = sizeof(T);
        (void)std::memcpy(frame.data, &tx_frame, sizeof(T));
        if (write(private_socket, &frame, sizeof(can_frame)) < 0)
        {
            return CanState::CAN_WRITE_ERROR;
        }
        return CanState::CAN_OK;
    }

    template <typename T>
    inline CanState CAN::receive(T &rx_frame, const time_t timeout_in_seconds)
    {
        static_assert(can_id<T> != INVALID_CAN_ID, "Can id has not been specified");

        can_frame frame;
        can_filter filter = {can_id<T>, (CAN_SFF_MASK | CAN_EFF_FLAG | CAN_RTR_FLAG)};

        timeval tv = {timeout_in_seconds, 0};
        if (setsockopt(private_socket, SOL_SOCKET, SO_RCVTIMEO, (const char *)&tv, sizeof tv) != 0)
        {
            return CanState::CAN_SET_TIMEOUT_ERROR;
        }

        if (setsockopt(private_socket, SOL_CAN_RAW, CAN_RAW_FILTER, &filter, sizeof(filter)) != 0)
        {
            return CanState::CAN_SET_MASK_ERROR;
        }

        if (read(private_socket, &frame, sizeof(can_frame)) < (ssize_t)sizeof(can_frame))
        {
            return CanState::CAN_READ_ERROR;
        }
        (void)std::memcpy(&rx_frame, frame.data, sizeof(T));

        return CanState::CAN_OK;
    }

    template <typename T>
    inline CanState CAN::receive_rtr(T &rx_frame, const time_t timeout_in_seconds)
    {
        static_assert(can_id<T> != INVALID_CAN_ID, "Can id has not been specified");

        can_frame frame;
        frame.can_id = can_id<T> | CAN_RTR_FLAG;

        if (write(private_socket, &frame, sizeof(can_frame)) < 0)
        {
            return CanState::CAN_WRITE_ERROR;
        }

        return receive(rx_frame, timeout_in_seconds);
    }

    inline CanState CAN::connect(const char *ifname)
    {
        ifreq ifr;
        sockaddr_can addr;
        private_socket = socket(PF_CAN, SOCK_RAW, CAN_RAW);
        if (private_socket == -1)
        {
            return CanState::CAN_SOCKET_ERROR;
        }
        (void)std::strncpy(ifr.ifr_name, ifname, sizeof(ifr.ifr_name));
        if (ioctl(private_socket, SIOCGIFINDEX, &ifr) == -1)
        {
            return CanState::CAN_IOCTL_ERROR;
        }
        addr.can_family = AF_CAN;
        addr.can_ifindex = ifr.ifr_ifindex;
        if (bind(private_socket, (sockaddr *)&addr, sizeof(addr)) == -1)
        {
            return CanState::CAN_BIND_ERROR;
        }

        return CanState::CAN_OK;
    }

    inline CanState CAN::disconnect()
    {
        if (close(private_socket) < 0)
        {
            return CanState::CAN_CLOSE_ERROR;
        }

        return CanState::CAN_OK;
    }

    inline CanState CAN::structure_receive_random(can_frame &rx_frame, const time_t timeout_in_seconds)
    {
        timeval tv = {timeout_in_seconds, 0};
        if (setsockopt(private_socket, SOL_SOCKET, SO_RCVTIMEO, (const char *)&tv, sizeof tv) != 0)
        {
            return CanState::CAN_SET_TIMEOUT_ERROR;
        }

        if (read(private_socket, &rx_frame, sizeof(can_frame)) < (ssize_t)sizeof(can_frame))
        {
            return CanState::CAN_READ_ERROR;
        }
        return CanState::CAN_OK;
    }

    inline CanState CAN::bytes_transmit(const uint16_t &can_id, const uint8_t &len, const char *tx_data)
    {
        can_frame frame;
        frame.can_id = can_id;
        frame.len = len;

        (void)std::memcpy(frame.data, tx_data, len);

        if (write(private_socket, &frame, sizeof(can_frame)) < 0)
        {
            return CanState::CAN_WRITE_ERROR;
        }

        return CanState::CAN_OK;
    }

    inline CanState CAN::bytes_receive(const uint16_t &can_id, const uint8_t &len, char *rx_data)
    {
        can_frame frame;
        can_filter filter = {can_id, (CAN_SFF_MASK | CAN_EFF_FLAG | CAN_RTR_FLAG)};

        if (setsockopt(private_socket, SOL_CAN_RAW, CAN_RAW_FILTER, &filter, sizeof(filter)) != 0)
        {
            return CanState::CAN_SOCKET_ERROR;
        }

        if (read(private_socket, &frame, sizeof(can_frame)) < (ssize_t)sizeof(can_frame))
        {
            return CanState::CAN_READ_ERROR;
        }

        (void)std::memcpy(rx_data, frame.data, len);

        return CanState::CAN_OK;
    }

    inline CanState CAN::bytes_receive_rtr(const uint16_t &can_id, const uint8_t &len, char *rx_data)
    {
        can_frame frame;
        frame.can_id = can_id | CAN_RTR_FLAG;

        if (write(private_socket, &frame, sizeof(can_frame)) < 0)
        {
            return CanState::CAN_WRITE_ERROR;
        }

        return bytes_receive(can_id, len, rx_data);
    }
}