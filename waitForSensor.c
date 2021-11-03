#pragma config(Sensor, S1,     touchSensor,    sensorEV3_Touch)
#pragma config(Sensor, S2,     gyroSensor,     sensorEV3_Gyro)
#pragma config(Sensor, S3,     colorSensor,    sensorEV3_Color)
#pragma config(Sensor, S4,     ultrasonicSensor, sensorEV3_Ultrasonic)
#pragma config(Motor,  motorB,          leftMotor,     tmotorEV3_Large, PIDControl, driveLeft, encoder)
#pragma config(Motor,  motorC,          rightMotor,    tmotorEV3_Large, PIDControl, driveRight, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//


task main() {
	while(true) {
		while(SensorValue[touchSensor] == 0){};
		while(SensorValue[touchSensor] == 1) {
			motor[leftMotor] = 30;
			motor[rightMotor] = 30;
		}
		while(SensorValue[touchSensor] == 0){};
		while(SensorValue[touchSensor] == 1){
			motor[leftMotor] = 0;
			motor[rightMotor] = 0;
		}
	}
}