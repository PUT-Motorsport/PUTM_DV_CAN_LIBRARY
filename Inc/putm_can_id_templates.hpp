#ifndef PUTM_CAN_ID_TEMPLATE
#define PUTM_CAN_ID_TEMPLATE

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
    constexpr uint16_t INVALID_CAN_ID = 0xFFFF;

    template <typename T>
    constexpr uint16_t can_id = INVALID_CAN_ID;

    template <>
    constexpr uint16_t can_id<Apps_main> = APPS_MAIN_CAN_ID;

    template <>
    constexpr uint16_t can_id<AQ_main> = AQ_MAIN_CAN_ID;
    template <>
    constexpr uint16_t can_id<AQ_acceleration> = AQ_ACCELERATION_CAN_ID;
    template <>
    constexpr uint16_t can_id<AQ_gyroscope> = AQ_GYROSCOPE_CAN_ID;
    template <>
    constexpr uint16_t can_id<AQ_ts_button> = AQ_TS_BUTTON_CAN_ID;

    template <>
    constexpr uint16_t can_id<BMS_HV_main> = BMS_HV_MAIN_CAN_ID;
    template <>
    constexpr uint16_t can_id<BMS_LV_main> = BMS_LV_MAIN_CAN_ID;
    template <>
    constexpr uint16_t can_id<BMS_LV_temperature> = BMS_LV_TEMPERATURE_CAN_ID;

    template <>
    constexpr uint16_t can_id<Dash_Main> = DASH_MAIN_CAN_ID;
    template <>
    constexpr uint16_t can_id<Dash_TCS> = DASH_TCS_CAN_ID;
    template <>
    constexpr uint16_t can_id<Dash_Smart_Fuses_FAN_speed> = DASH_SMART_FUSES_FAN_SPEED_CAN_ID;
    template <>
    constexpr uint16_t can_id<Dash_steering_wheel_request> = DASH_STEERING_WHEEL_REQUEST_CAN_ID;
    template <>
    constexpr uint16_t can_id<Dash_lap_finished> = DASH_LAP_FINISHED_CAN_ID;
    template <>
    constexpr uint16_t can_id<Dash_steering_wheel_angle> = DASH_STEERING_WHEEL_ANGLE_CAN_ID;

    template <>
    constexpr uint16_t can_id<DV_Ass> = DV_ASS_CAN_ID;

    template <>
    constexpr uint16_t can_id<Lap_timer_Main> = LAP_TIMER_MAIN_CAN_ID;
    template <>
    constexpr uint16_t can_id<Lap_timer_Sector> = LAP_TIMER_SECTOR_CAN_ID;
    template <>
    constexpr uint16_t can_id<Lap_timer_Acc_time> = LAP_TIMER_ACC_TIME_CAN_ID;
    template <>
    constexpr uint16_t can_id<Lap_timer_Skidpad_time> = LAP_TIMER_SKIDPAD_TIME_CAN_ID;
    template <>
    constexpr uint16_t can_id<Lap_timer_Lap_time> = LAP_TIMER_LAP_TIME_CAN_ID;

    template <>
    constexpr uint16_t can_id<SF_main> = SF_MAIN_CAN_ID;
    template <>
    constexpr uint16_t can_id<SF_PassiveElements> = SF_PASSIVEELEMENTS_CAN_ID;
    template <>
    constexpr uint16_t can_id<SF_LegendaryDVAndSupply> = SF_LEGENDARYDVANDSUPPLY_CAN_ID;
    template <>
    constexpr uint16_t can_id<SF_Supply> = SF_SUPPLY_CAN_ID;
    template <>
    constexpr uint16_t can_id<SF_safety> = SF_SAFETY_CAN_ID;

    template <>
    constexpr uint16_t can_id<Steering_Wheel_main> = STEERING_WHEEL_MAIN_CAN_ID;
    template <>
    constexpr uint16_t can_id<Steering_Wheel_event> = STEERING_WHEEL_EVENT_CAN_ID;

    template <>
    constexpr uint16_t can_id<SWPS_main> = SWPS_MAIN_CAN_ID;

    template <>
    constexpr uint16_t can_id<TC_main> = TC_MAIN_CAN_ID;
    template <>
    constexpr uint16_t can_id<TC_rear_suspension> = TC_REAR_SUSPENSION_CAN_ID;
    template <>
    constexpr uint16_t can_id<TC_wheel_velocities> = TC_WHEEL_VELOCITIES_CAN_ID;
    template <>
    constexpr uint16_t can_id<TC_temperatures> = TC_TEMPERATURES_CAN_ID;
    template <>
    constexpr uint16_t can_id<TC_imu_gyro> = TC_IMU_GYRO_CAN_ID;
    template <>
    constexpr uint16_t can_id<TC_imu_acc> = TC_IMU_ACC_CAN_ID;

    template <>
    constexpr uint16_t can_id<Telemetry_Main> = TELEMETRY_MAIN_CAN_ID;

    template <>
    constexpr uint16_t can_id<WheelTemp_main> = WHEELTEMP_MAIN_CAN_ID;

    template <>
    constexpr uint16_t can_id<YawProbe_air_flow> = YAWPROBE_AIR_FLOW_CAN_ID;
}


#endif //PUTM_CAN_ID_TEMPLATE