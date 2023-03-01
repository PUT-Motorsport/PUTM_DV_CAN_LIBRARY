#ifndef DV
#define DV

#include <cstdint>

namespace PUTM_CAN {

enum struct AutonomousSystemStatus : uint8_t {
	Off,
    Ready,
    Driving,
    Emergency,
    Finished,
};

struct __attribute__ ((packed)) DV_Ass{
	AutonomousSystemStatus status;
};


const uint16_t DV_ASS_CAN_ID = 0x07;
const uint8_t DV_ASS_CAN_DLC = sizeof(DV_Ass);
const uint8_t DV_ASS_FREQUENCY = 1;

} // namespace can

#endif