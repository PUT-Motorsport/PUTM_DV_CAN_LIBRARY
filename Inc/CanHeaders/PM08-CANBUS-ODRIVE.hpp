//Generated on 2023-03-10 21:36:48.871086
#pragma once

#include <cstdint>

namespace PUTM_CAN{

	enum struct Odrive_states: uint8_t {
	};

	struct __attribute__ ((packed)) Odrive_Heartbeat{
		uint32_t Axis_Error;//Axis error
		uint8_t Axis_State;//Axis State
	};

	struct __attribute__ ((packed)) Odrive_Estop{
	};

	struct __attribute__ ((packed)) Odrive_Get_Error{
		uint32_t Active_Errors;
		uint32_t Disarm_Reason;
	};

	struct __attribute__ ((packed)) Odrive_Set_Axis_Node_ID{
		uint32_t Axis_Node_ID;
	};

	struct __attribute__ ((packed)) Odrive_Set_Axis_State{
		uint32_t Axis_Requested_State;
	};

	struct __attribute__ ((packed)) Odrive_Get_Encoder_Estimation{
		uint32_t Pos_Estimate;
		uint32_t Vel_Estimate;
	};

	struct __attribute__ ((packed)) Odrive_Get_Encoder_Count{
		uint32_t Shadow_Count;
		uint32_t Count_in_CPR;
	};

	struct __attribute__ ((packed)) Odrive_Set_Controller_Mode{
		uint32_t Control_Mode;
		uint32_t Input_Mode;
	};

	struct __attribute__ ((packed)) Odrive_Set_Input_Position{
		uint32_t Input_Pos;
		uint16_t Vel_FF;
		uint16_t Torque_FF;
	};

	struct __attribute__ ((packed)) Odrive_Set_Input_Vel{
		uint32_t Input_Vel;
		uint32_t Input_Torque_FF;
	};

	struct __attribute__ ((packed)) Odrive_Set_Input_Torque{
		uint32_t Input_Torque;
	};

	struct __attribute__ ((packed)) Odrive_Set_Limits{
		uint32_t Velocity_Limit;
		uint32_t Current_Limit;
	};

	struct __attribute__ ((packed)) Odrive_Start_Anticogging{
	};

	struct __attribute__ ((packed)) Odrive_Set_Traj_Vel_Limit{
		uint32_t Traj_Vel_Limit;
	};

	struct __attribute__ ((packed)) Odrive_Set_Traj_Accel_Limits{
		uint32_t Traj_Accel_Limit;
		uint32_t Traj_Decel_Limit;
	};

	struct __attribute__ ((packed)) Odrive_Set_Traj_Inertia{
		uint32_t Traj_Inertia;
	};

	struct __attribute__ ((packed)) Odrive_Get_Iq{
		uint32_t Iq_Setpoint;
		uint32_t Iq_Measured;
	};

	struct __attribute__ ((packed)) Odrive_Get_Temperature{
		uint32_t FET_Temperature;
		uint32_t Motor_Temperature;
	};

	struct __attribute__ ((packed)) Odrive_Reboot{
	};

	struct __attribute__ ((packed)) Odrive_Get_Vbus_Voltage_Current{
		uint32_t Vbus_Voltage;
		uint32_t Vbus_Current;
	};

	struct __attribute__ ((packed)) Odrive_Clear_Errors{
	};

	struct __attribute__ ((packed)) Odrive_Set_Absolute_Position{
		uint32_t Position;
	};

	struct __attribute__ ((packed)) Odrive_Set_Pos_Gain{
		uint32_t Pos_Gain;
	};

	struct __attribute__ ((packed)) Odrive_Set_Vel_gains{
		uint32_t Vel_Gain;
		uint32_t Vel_Integrator_Gain;
	};


	const uint16_t ODRIVE_HEARTBEAT_CAN_ID = 0x161;
	const uint8_t ODRIVE_HEARTBEAT_CAN_DLC = sizeof(Odrive_Heartbeat);
	const uint8_t ODRIVE_HEARTBEAT_FREQUENCY = 1;
	const uint16_t ODRIVE_ESTOP_CAN_ID = 0x162;
	const uint8_t ODRIVE_ESTOP_CAN_DLC = sizeof(Odrive_Estop);
	const uint8_t ODRIVE_ESTOP_FREQUENCY = 0;
	const uint16_t ODRIVE_GET_ERROR_CAN_ID = 0x163;
	const uint8_t ODRIVE_GET_ERROR_CAN_DLC = sizeof(Odrive_Get_Error);
	const uint8_t ODRIVE_GET_ERROR_FREQUENCY = 0;
	const uint16_t ODRIVE_SET_AXIS_NODE_ID_CAN_ID = 0x166;
	const uint8_t ODRIVE_SET_AXIS_NODE_ID_CAN_DLC = sizeof(Odrive_Set_Axis_Node_ID);
	const uint8_t ODRIVE_SET_AXIS_NODE_ID_FREQUENCY = 0;
	const uint16_t ODRIVE_SET_AXIS_STATE_CAN_ID = 0x167;
	const uint8_t ODRIVE_SET_AXIS_STATE_CAN_DLC = sizeof(Odrive_Set_Axis_State);
	const uint8_t ODRIVE_SET_AXIS_STATE_FREQUENCY = 0;
	const uint16_t ODRIVE_GET_ENCODER_ESTIMATION_CAN_ID = 0x169;
	const uint8_t ODRIVE_GET_ENCODER_ESTIMATION_CAN_DLC = sizeof(Odrive_Get_Encoder_Estimation);
	const uint8_t ODRIVE_GET_ENCODER_ESTIMATION_FREQUENCY = 0;
	const uint16_t ODRIVE_GET_ENCODER_COUNT_CAN_ID = 0x170;
	const uint8_t ODRIVE_GET_ENCODER_COUNT_CAN_DLC = sizeof(Odrive_Get_Encoder_Count);
	const uint8_t ODRIVE_GET_ENCODER_COUNT_FREQUENCY = 0;
	const uint16_t ODRIVE_SET_CONTROLLER_MODE_CAN_ID = 0x171;
	const uint8_t ODRIVE_SET_CONTROLLER_MODE_CAN_DLC = sizeof(Odrive_Set_Controller_Mode);
	const uint8_t ODRIVE_SET_CONTROLLER_MODE_FREQUENCY = 0;
	const uint16_t ODRIVE_SET_INPUT_POSITION_CAN_ID = 0x172;
	const uint8_t ODRIVE_SET_INPUT_POSITION_CAN_DLC = sizeof(Odrive_Set_Input_Position);
	const uint8_t ODRIVE_SET_INPUT_POSITION_FREQUENCY = 0;
	const uint16_t ODRIVE_SET_INPUT_VEL_CAN_ID = 0x173;
	const uint8_t ODRIVE_SET_INPUT_VEL_CAN_DLC = sizeof(Odrive_Set_Input_Vel);
	const uint8_t ODRIVE_SET_INPUT_VEL_FREQUENCY = 0;
	const uint16_t ODRIVE_SET_INPUT_TORQUE_CAN_ID = 0x174;
	const uint8_t ODRIVE_SET_INPUT_TORQUE_CAN_DLC = sizeof(Odrive_Set_Input_Torque);
	const uint8_t ODRIVE_SET_INPUT_TORQUE_FREQUENCY = 0;
	const uint16_t ODRIVE_SET_LIMITS_CAN_ID = 0x175;
	const uint8_t ODRIVE_SET_LIMITS_CAN_DLC = sizeof(Odrive_Set_Limits);
	const uint8_t ODRIVE_SET_LIMITS_FREQUENCY = 0;
	const uint16_t ODRIVE_START_ANTICOGGING_CAN_ID = 0x176;
	const uint8_t ODRIVE_START_ANTICOGGING_CAN_DLC = sizeof(Odrive_Start_Anticogging);
	const uint8_t ODRIVE_START_ANTICOGGING_FREQUENCY = 0;
	const uint16_t ODRIVE_SET_TRAJ_VEL_LIMIT_CAN_ID = 0x177;
	const uint8_t ODRIVE_SET_TRAJ_VEL_LIMIT_CAN_DLC = sizeof(Odrive_Set_Traj_Vel_Limit);
	const uint8_t ODRIVE_SET_TRAJ_VEL_LIMIT_FREQUENCY = 0;
	const uint16_t ODRIVE_SET_TRAJ_ACCEL_LIMITS_CAN_ID = 0x178;
	const uint8_t ODRIVE_SET_TRAJ_ACCEL_LIMITS_CAN_DLC = sizeof(Odrive_Set_Traj_Accel_Limits);
	const uint8_t ODRIVE_SET_TRAJ_ACCEL_LIMITS_FREQUENCY = 0;
	const uint16_t ODRIVE_SET_TRAJ_INERTIA_CAN_ID = 0x179;
	const uint8_t ODRIVE_SET_TRAJ_INERTIA_CAN_DLC = sizeof(Odrive_Set_Traj_Inertia);
	const uint8_t ODRIVE_SET_TRAJ_INERTIA_FREQUENCY = 0;
	const uint16_t ODRIVE_GET_IQ_CAN_ID = 0x180;
	const uint8_t ODRIVE_GET_IQ_CAN_DLC = sizeof(Odrive_Get_Iq);
	const uint8_t ODRIVE_GET_IQ_FREQUENCY = 0;
	const uint16_t ODRIVE_GET_TEMPERATURE_CAN_ID = 0x181;
	const uint8_t ODRIVE_GET_TEMPERATURE_CAN_DLC = sizeof(Odrive_Get_Temperature);
	const uint8_t ODRIVE_GET_TEMPERATURE_FREQUENCY = 0;
	const uint16_t ODRIVE_REBOOT_CAN_ID = 0x182;
	const uint8_t ODRIVE_REBOOT_CAN_DLC = sizeof(Odrive_Reboot);
	const uint8_t ODRIVE_REBOOT_FREQUENCY = 0;
	const uint16_t ODRIVE_GET_VBUS_VOLTAGE_CURRENT_CAN_ID = 0x183;
	const uint8_t ODRIVE_GET_VBUS_VOLTAGE_CURRENT_CAN_DLC = sizeof(Odrive_Get_Vbus_Voltage_Current);
	const uint8_t ODRIVE_GET_VBUS_VOLTAGE_CURRENT_FREQUENCY = 0;
	const uint16_t ODRIVE_CLEAR_ERRORS_CAN_ID = 0x184;
	const uint8_t ODRIVE_CLEAR_ERRORS_CAN_DLC = sizeof(Odrive_Clear_Errors);
	const uint8_t ODRIVE_CLEAR_ERRORS_FREQUENCY = 0;
	const uint16_t ODRIVE_SET_ABSOLUTE_POSITION_CAN_ID = 0x185;
	const uint8_t ODRIVE_SET_ABSOLUTE_POSITION_CAN_DLC = sizeof(Odrive_Set_Absolute_Position);
	const uint8_t ODRIVE_SET_ABSOLUTE_POSITION_FREQUENCY = 0;
	const uint16_t ODRIVE_SET_POS_GAIN_CAN_ID = 0x186;
	const uint8_t ODRIVE_SET_POS_GAIN_CAN_DLC = sizeof(Odrive_Set_Pos_Gain);
	const uint8_t ODRIVE_SET_POS_GAIN_FREQUENCY = 0;
	const uint16_t ODRIVE_SET_VEL_GAINS_CAN_ID = 0x187;
	const uint8_t ODRIVE_SET_VEL_GAINS_CAN_DLC = sizeof(Odrive_Set_Vel_gains);
	const uint8_t ODRIVE_SET_VEL_GAINS_FREQUENCY = 0;

}

