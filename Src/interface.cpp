#include <net/if.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <linux/can.h>
#include <unistd.h>
#include <string.h>
#include <cstring>
#include <linux/can/raw.h>


#include "../Inc/interface.hpp"


int8_t PUTM_CAN::CAN::connect(const char *ifname)
{
    struct ifreq ifr;
    struct sockaddr_can addr;
    if ((private_socket = socket(PF_CAN, SOCK_RAW, CAN_RAW)) == -1)
    {
        return -1;
    }
    strcpy(ifr.ifr_name, ifname);
    ioctl(private_socket, SIOCGIFINDEX, &ifr);
    addr.can_family = AF_CAN;
    addr.can_ifindex = ifr.ifr_ifindex;
    if (bind(private_socket, (struct sockaddr *)&addr, sizeof(addr)) == -1)
    {
        return -2;
    }
    return 0;
}

int8_t PUTM_CAN::CAN::transmit(const uint16_t &can_id, const uint8_t &can_dlc, const char *tx_data)
{
    struct can_frame frame;
    frame.can_id = can_id;
    frame.can_dlc = can_dlc;

    std::memcpy(frame.data, tx_data, can_dlc);

    write(private_socket, &frame, sizeof(struct can_frame));

    return 0;
}

int8_t PUTM_CAN::CAN::receive(const uint16_t &can_id, const uint8_t &can_dlc, char *rx_data)
{
    struct can_frame frame;
    struct can_filter filter{
        .can_id = can_id,
        .can_mask = CAN_SFF_MASK
    };
    if(setsockopt(private_socket, SOL_CAN_RAW, CAN_RAW_FILTER, &filter, sizeof(filter)) != 0){
        return -1;
    }
	
    if(read(private_socket, &frame, sizeof(struct can_frame)) < 0){
        return -2;
    }

    // CHECK IF DLC == SIZE
 
    std::memcpy(rx_data, frame.data, can_dlc);
 
    return 0;
}

int8_t PUTM_CAN::CAN::receive_rtr(const uint16_t &can_id, const uint8_t &can_dlc, char *rx_data)
{
    struct can_frame frame; 
    frame.can_id = can_id | CAN_RTR_FLAG;
    write(private_socket, &frame, sizeof(struct can_frame));
    receive(can_id, can_dlc, rx_data);
    return 0;
}

int8_t PUTM_CAN::CAN::disconnect()
{
    if (close(private_socket) < 0) {
        return -1;
    }
    return 0;
}