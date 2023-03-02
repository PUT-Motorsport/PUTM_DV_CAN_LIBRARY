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
#include "Inc/interface.hpp"

using namespace PUTM_CAN;


// struct Device{
//     Device(uint16_t can_id, uint16_t can_dlc) : can_id(can_id), can_dlc(can_dlc) {}
//     const uint16_t can_id;
//     const uint16_t can_dlc;
// };
// struct __attribute__ ((packed)) Our_device : Device {
//     Our_device() : Device(0x87, sizeof(Our_device)-sizeof(Device)){}
//     int16_t speed_x; // rotary speed x
//     int16_t speed_y; // rotary speed y
//     int16_t speed_z; // rotary speed z
// };

// uint8_t _transmit(Device dev)
// {
//     struct can_frame frame;
//     frame.can_id = dev.can_id;
//     frame.can_dlc = dev.can_dlc;

//     std::memcpy(frame.data, (const void*)(reinterpret_cast<uint8_t*>(&dev))[sizeof(Device)], sizeof(Device));

//     write(private_socket, &frame, sizeof(struct can_frame));
//     return 0;
// }

// struct AQ_gyroscope : Base{
//     AQ_gyroscope() : Base(0x87, 100){}    
//     static const uint16_t can_id = 0x87;
//     static const uint8_t can_freq = 100;
//     AQ_gyroscope_data data;
//     static const uint8_t can_dlc = sizeof(data);
// };


int main(int argc, char *argv[]){  
    // static const int can_dlc = sizeof(Our_device);
    
    Our_device dev;

    dev.speed_x = 1;
    dev.speed_y = 2;
    dev.speed_z = 3;

    // std::cout<<(reinterpret_cast<uint16_t*>(&dev))[2];


    CAN can;
    can.connect();

    can.transmit(dev);

    // Apps_main apps_transmit{
    //     .pedal_position = 1200,
    //     .counter = 0,
    //     .position_diff = 0,
    //     .device_state = Apps_states::Normal_operation,
    // };



    // struct Base{
    //     struct data{};
    //     const uint16_t can_id;
    //     const uint8_t can_freq;
        
    // };    




    // AQ_gyroscope aq_gyroscope;
    // aq_gyroscope.can_id;
    // aq_gyroscope.can_dlc;
    // aq_gyroscope.can_freq;
    // aq_gyroscope.data.speed_x;
    // aq_gyroscope.data.speed_y;
    // aq_gyroscope.data.speed_z;

    // transmit(Device dev)
    // {
    //     write(dev.can_id, dev.can_dlc, dev.data);
    // }

    // transmit(aq_gyroscope);

    // can.receive(aq_gyroscope);

    // Apps_main apps_receive;
    // unsigned int id;
    // uint8_t data[8] = {0};
    // data[0] = 1;
    // data[4] = 2;
    // data[6] = 2;

    // data[4] = 5;
    // data[4] = 5;

    // std::cin>>data[0];

    // can.transmit(185U, 1U, (char*)data);


    // while(true){
    //     std::cout<<"id:";
    //     std::cin>>id;
    //     std::cout<<"data:";
    //     std::cin>>data[0];
    //     can.transmit(id, 8U, (char*)data);
    // }

    // can.transmit(184U, 0, (char*)data);

    // while(true){
    // can.receive(1U, 9U, data);
    // printf("%d: %d\n", APPS_MAIN_CAN_ID);
    //     printf("%d: %d\n", APPS_MAIN_CAN_ID, apps_receive.counter);
    //     printf("%d: %d\n", APPS_MAIN_CAN_ID, apps_receive.position_diff);
    //     printf("%d: %d\n", APPS_MAIN_CAN_ID, apps_receive.device_state);
    // }

    // while(true){
    // can.receive_rtr(170U, 8U, (char*)data);
    // printf("%d,%d,%d,%d,%d,%d,%d,%d\n", data[0], data[1], data[2], data[3], data[4], data[5], data[6], data[7]);
    // }

    // printf("%d: %d\n", APPS_MAIN_CAN_ID, apps_transmit.counter);
    // printf("%d: %d\n", APPS_MAIN_CAN_ID, apps_transmit.position_diff);
    // printf("%d: %d\n", APPS_MAIN_CAN_ID, apps_transmit.device_state);
    // std::cout<< apps_transmit.counter <<"\n";

    return 0;
}