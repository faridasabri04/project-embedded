#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_

#include "std_types.h"

// Motor Pin Definitions
#define MOTOR_PORT_ID        PORTB_ID
#define MOTOR_PIN_IN1        PB0
#define MOTOR_PIN_IN2        PB1
#define MOTOR_ENABLE_PIN     PB3

// Motor States
typedef enum {
    CW,   // Clockwise rotation
    ACW,  // Anti-clockwise rotation
	STOP
} DcMotor_State;



//Functions Prototypes

void DcMotor_Init(void);

void DcMotor_Rotate(DcMotor_State state, uint8 speed);

#endif /* DC_MOTOR_H_ */
