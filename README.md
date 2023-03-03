# PUTM LINUX CAN LIBRARY
This library allows one to easily communicate with devices connected to the CAN bus.

## How to use
Create a CAN instance and trigger the connect() method:
```cpp
CAN can;
can.connect();
```
Create a structure instance:
```cpp
Apps_main apps_frame;
```
Assign values to the structure:
```cpp
apps_frame = {
    .pedal_position = 1,
    .counter = 2,
    .position_diff = 3,
    .device_state = Apps_states::Sensor_Implausiblity
};
```
Transmit data:
```cpp
can.transmit(apps_frame);
```
Receive data:
```cpp
can.receive(apps_frame);
```
Transmit remote request and receive data:
```cpp
can.receive_rtr(apps_frame);
```
