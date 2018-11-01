#include <Arduino.h>
#include "platformMotors.h"
#include "defines.h"

extern int motLeftForward;
extern int motLeftBack;
extern int motLeftVelo;

extern int motRightForward;
extern int motRightBack;
extern int motRightVelo;

void motorStop() {
	digitalWrite(motRightForward, LOW);
	digitalWrite(motRightBack, LOW);

	digitalWrite(motLeftForward, LOW);
	digitalWrite(motLeftBack, LOW);

	analogWrite(motLeftVelo, 0);
	analogWrite(motRightVelo, 0);

	delay(MOTOR_STOP_DELAY);
}

void motorTurn(int direction) {
	switch (direction) {
		case RIGHT:
			motorTurnRight();
			break;

		case LEFT:
			motorTurnLeft();
			break;

		case BACK:
			motorTurnBack();
			break;
	}
}

void motorTurnLeft() {
	int velocity = 255;

	analogWrite(motLeftVelo, velocity);
	analogWrite(motRightVelo, velocity);
	
	digitalWrite(motLeftForward, HIGH);
	digitalWrite(motLeftBack, LOW);

	digitalWrite(motRightForward, LOW);
	digitalWrite(motRightBack, HIGH);

	delay(TURNING_TIME);
	motorStop();
}

void motorTurnRight() {
	int velocity = 255;

	analogWrite(motLeftVelo, velocity);
	analogWrite(motRightVelo, velocity);

	digitalWrite(motLeftForward, LOW);
	digitalWrite(motLeftBack, HIGH);

	digitalWrite(motRightForward, HIGH);
	digitalWrite(motRightBack, LOW);

	delay(TURNING_TIME);
	motorStop();
}

void motorTurnBack() {
	int velocity = 255;
	
	analogWrite(motLeftVelo, velocity);
	analogWrite(motRightVelo, velocity);

	digitalWrite(motLeftForward, LOW);
	digitalWrite(motLeftBack, HIGH);

	digitalWrite(motRightForward, HIGH);
	digitalWrite(motRightBack, LOW);

	delay(2 * TURNING_TIME);
	motorStop();
}

void motorForward(int velocity) {
	analogWrite(motLeftVelo, velocity);
	analogWrite(motRightVelo, velocity);

	digitalWrite(motLeftForward, HIGH);
	digitalWrite(motRightBack, LOW);	

	digitalWrite(motRightForward, HIGH);
	digitalWrite(motRightBack, LOW);
}

void motorMoveOffset() {
	int velocity = 255;	

	analogWrite(motLeftVelo, velocity);
	analogWrite(motRightVelo, velocity);

	digitalWrite(motLeftForward, HIGH);
	digitalWrite(motRightBack, LOW);	

	digitalWrite(motRightForward, HIGH);
	digitalWrite(motRightBack, LOW);

	delay(SELF_LENGTH_OFFSET);
	motorStop();
}