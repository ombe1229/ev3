#pragma config(Sensor, S1,     touchSensor,    sensorEV3_Touch)
#pragma config(Sensor, S2,     gyroSensor,     sensorEV3_Gyro)
#pragma config(Sensor, S3,     colorSensor,    sensorEV3_Color)
#pragma config(Sensor, S4,     ultrasonicSensor, sensorEV3_Ultrasonic)
#pragma config(Motor,  motorB,          leftMotor,     tmotorEV3_Large, PIDControl, driveLeft, encoder)
#pragma config(Motor,  motorC,          rightMotor,    tmotorEV3_Large, PIDControl, driveRight, encoder)


float mot;

task main() {
	while(SensorValue[touchSensor] == 0) {};
	while(SensorValue[touchSensor] == 1) {
		moveMotorTarget(leftMotor, 360, 100);
		moveMotorTarget(rightMotor, 360, -100);
		waitUntilMotorStop(leftMotor);
	}

	while(SensorValue[touchSensor] == 0) {
		mot = (getColorReflected(colorSensor) - 38) * 1.1;
		motor[leftMotor] = 50 - mot;
		motor[rightMotor] = 50 + mot;
	}

	motor[leftMotor] = -100;
	motor[rightMotor] = -100;
	wait1Msec(1000);
}
