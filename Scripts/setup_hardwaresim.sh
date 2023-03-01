 
#!/bin/bash

 # This script allows to test the ros-can bridge by 
# simulating the USB-CAN device and PM08 CANbus frames

 # Virtual Can set-up
modprobe vcan
ip link add dev slcan0 type vcan
ip link set up slcan0


  # CANbus frames generation
i=0
while true
do
    if [ $i -eq 1 ]
    then
        uint32_t="00000B"
        int32_t="00000B"
        uint16_t="000B"
        int16_t="000B"
        uint8_t="0B"
        int8_t="0B"
        state="00"
        bool="00"

        i=0
    else
        uint32_t="00000A"
        int32_t="00000A"
        uint16_t="000A"
        int16_t="000A"
        uint8_t="0A"
        int8_t="0A"
        state="01"
        bool="01"

        i=1
    fi
    
# Dash_Main 
cansend slcan0 "064#${state}"

# Dash_TCS 
cansend slcan0 "019#${uint8_t}${uint8_t}${uint8_t}${uint8_t}${uint8_t}${uint8_t}${uint8_t}${uint8_t}"

# Dash_Smart_Fuses_FAN_speed 
cansend slcan0 "032#${uint8_t}${uint8_t}${uint8_t}"

# Dash_steering_wheel_request 
cansend slcan0 "037#"

# Dash_lap_finished 
cansend slcan0 "07d#${uint32_t}"

# Dash_steering_wheel_angle 
cansend slcan0 "08c#${uint16_t}"

# Odrive_Heartbeat 
cansend slcan0 "033#${uint32_t}${uint8_t}"

# Odrive_Estop 
cansend slcan0 "034#"

# Odrive_Get_Error 
cansend slcan0 "035#${uint32_t}${uint32_t}"

# Odrive_Set_Axis_Node_ID 
cansend slcan0 "038#${uint32_t}"

# Odrive_Set_Axis_State 
cansend slcan0 "039#${uint32_t}"

# Odrive_Get_Encoder_Estimation 
cansend slcan0 "041#${uint32_t}${uint32_t}"

# Odrive_Get_Encoder_Count 
cansend slcan0 "042#${uint32_t}${uint32_t}"

# Odrive_Set_Controller_Mode 
cansend slcan0 "043#${uint32_t}${uint32_t}"

# Odrive_Set_Input_Position 
cansend slcan0 "044#${uint32_t}${uint16_t}${uint16_t}"

# Odrive_Set_Input_Vel 
cansend slcan0 "045#${uint32_t}${uint32_t}"

# Odrive_Set_Input_Torque 
cansend slcan0 "046#${uint32_t}"

# Odrive_Set_Limits 
cansend slcan0 "047#${uint32_t}${uint32_t}"

# Odrive_Start_Anticogging 
cansend slcan0 "048#"

# Odrive_Set_Traj_Vel_Limit 
cansend slcan0 "049#${uint32_t}"

# Odrive_Set_Traj_Accel_Limits 
cansend slcan0 "050#${uint32_t}${uint32_t}"

# Odrive_Set_Traj_Inertia 
cansend slcan0 "051#${uint32_t}"

# Odrive_Get_Iq 
cansend slcan0 "052#${uint32_t}${uint32_t}"

# Odrive_Get_Temperature 
cansend slcan0 "053#${uint32_t}${uint32_t}"

# Odrive_Reboot 
cansend slcan0 "054#"

# Odrive_Get_Vbus_Voltage_Current 
cansend slcan0 "055#${uint32_t}${uint32_t}"

# Odrive_Clear_Errors 
cansend slcan0 "056#"

# Odrive_Set_Absolute_Position 
cansend slcan0 "057#${uint32_t}"

# Odrive_Set_Pos_Gain 
cansend slcan0 "058#${uint32_t}"

# Odrive_Set_Vel_gains 
cansend slcan0 "059#${uint32_t}${uint32_t}"

# TC_main 
cansend slcan0 "01e#000A000A0AFC2828"

# TC_rear_suspension 
cansend slcan0 "023#${uint16_t}${uint16_t}"

# TC_wheel_velocities 
cansend slcan0 "024#${uint16_t}${uint16_t}${uint16_t}${uint16_t}"

# TC_temperatures 
cansend slcan0 "025#${uint8_t}${uint8_t}${uint8_t}${uint8_t}${uint8_t}${uint8_t}"

# TC_imu_gyro 
cansend slcan0 "026#${int16_t}${int16_t}${int16_t}"

# TC_imu_acc 
cansend slcan0 "027#${int16_t}${int16_t}${int16_t}"

# BMS_LV_main 
cansend slcan0 "00f#${uint16_t}${uint8_t}${uint8_t}${uint8_t}${state}"

# BMS_LV_temperature 
cansend slcan0 "014#${uint8_t}${uint8_t}${uint8_t}${uint8_t}${uint8_t}${uint8_t}${uint8_t}${uint8_t}"

# DV_Ass 
cansend slcan0 "007#${uint8_t}"

# Swps_Main 
cansend slcan0 "09b#${uint16_t}"

# Lap_timer_Main 
cansend slcan0 "078#${state}"

# Lap_timer_Sector 
cansend slcan0 "03c#${uint8_t}${uint32_t}${state}"

# Lap_timer_Acc_time 
cansend slcan0 "091#${uint32_t}${state}"

# Lap_timer_Skidpad_time 
cansend slcan0 "096#${uint32_t}${state}"

# Lap_timer_Lap_time 
cansend slcan0 "09b#${uint32_t}${state}"

# Steering_Wheel_main 
cansend slcan0 "028#${int16_t}${state}"

# Steering_Wheel_event 
cansend slcan0 "02d#${uint8_t}${uint8_t}${uint8_t}"

# SF_main 
cansend slcan0 "041#${state}${uint8_t}${uint8_t}${uint8_t}${uint8_t}"

# SF_PassiveElements 
cansend slcan0 "046#${uint8_t}${uint8_t}${uint8_t}${uint8_t}${uint8_t}${uint8_t}${uint8_t}${uint8_t}"

# SF_LegendaryDVAndSupply 
cansend slcan0 "04b#${uint8_t}${uint8_t}${uint8_t}${uint8_t}${uint8_t}${uint8_t}${uint8_t}${uint8_t}"

# SF_Supply 
cansend slcan0 "050#${uint8_t}${uint8_t}${uint8_t}${uint8_t}${uint8_t}${uint8_t}${uint8_t}${uint8_t}"

# SF_Safety 
cansend slcan0 "03d#${bool}${bool}${bool}${bool}${bool}"

# BMS_HV_main 
cansend slcan0 "00a#000A000A02828281"

# WheelTemp_main 
cansend slcan0 "069#${uint8_t}${uint8_t}${uint8_t}${uint8_t}${uint8_t}${uint8_t}${uint8_t}${uint8_t}"

# AQ_main 
cansend slcan0 "05f#00A00A00A00AFF01"

# AQ_acceleration 
cansend slcan0 "082#${int16_t}${int16_t}${int16_t}"

# AQ_gyroscope 
cansend slcan0 "087#${int16_t}${int16_t}${int16_t}"

# AQ_ts_button 
cansend slcan0 "060#${uint8_t}"

# Telemetry_Main 
cansend slcan0 "073#${uint8_t}${uint8_t}${uint8_t}${state}"

# Apps_main 
cansend slcan0 "005#${uint16_t}${uint8_t}${int8_t}${state}"

# YawProbe_air_flow 
cansend slcan0 "06e#${uint16_t}${state}"

done