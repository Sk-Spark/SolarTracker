/*
* To test 4 LDR with 2 servos
*/

#include <Servo.h>

//Minimum change in position of a servo
const int delta=1;
const int del = 20;
const int THRESHOLD = 10;

int ldr1 = A0;
int ldr2 = A1;
int ldr3 = A2;
int ldr4 = A3;

int v_ldr1;
int v_ldr2;
int v_ldr3;
int v_ldr4;

int s1_pos, s2_pos;

int servo1_pin = 9; // Left-Right
int servo2_pin = 10;// Up-Down

Servo s1,s2;

void setup() 
{

  s1.attach(servo1_pin);
  s2.attach(servo2_pin);

  s1_pos = s2_pos = 90;

  s1.write(s1_pos);
  s2.write(s2_pos);

  Serial.begin(9600);
  delay(100);

}

void loop() 
{
	// Reading analog values fro LDR
	v_ldr1 = analogRead(ldr1);
	v_ldr2 = analogRead(ldr2);
	v_ldr3 = analogRead(ldr3);
	v_ldr4 = analogRead(ldr4);

	//Printing current values of LDR
	Serial.println(v_ldr1);
	Serial.println(v_ldr2);
	Serial.println(v_ldr3);
	Serial.println(v_ldr4);
	Serial.println("");

	// Reading current position of servos
	s1_pos = s1.read();
	s2_pos = s2.read();

	Serial.println(s1_pos);
	Serial.println(s2_pos);

	if( v_ldr4-v_ldr1 > THRESHOLD )
	{
		moveLeft();
	}

	if( v_ldr4-v_ldr1 < -THRESHOLD )
	{
		moveRight();
	}

	if( v_ldr3-v_ldr2 > THRESHOLD )
	{
		moveLeft();
	}

	if( v_ldr3-v_ldr2 < -THRESHOLD )
	{
		moveRight();
	}

	if( v_ldr4-v_ldr3 > THRESHOLD )
	{
		moveDown();
	}

	if( v_ldr4-v_ldr3 < -THRESHOLD )
	{
		moveUp();
	}

	if( v_ldr1-v_ldr2 > THRESHOLD )
	{
		moveDown();
	}

	if( v_ldr1-v_ldr2 < -THRESHOLD )
	{
		moveUp();
	}

	//pinMode(servo2_pin, OUTPUT);
	s2.write(s2_pos);
	delay(del);
	//pinMode(servo2_pin, INPUT);

	delay(100);

	//pinMode(servo1_pin, OUTPUT);
	s1.write(s1_pos);
	delay(del);
	//pinMode(servo1_pin, INPUT);


	delay(100);

}


void moveDown()
{
	// pinMode(servo2_pin, OUTPUT);

	s2_pos += delta;

	if(s2_pos >160)
		s2_pos = 160;
	
	// s2.write(s2_pos);
	// delay(del);

	// pinMode(servo2_pin, INPUT);

	Serial.print("Down movement ");
	Serial.println(s2_pos);

}

void moveUp()
{
	// pinMode(servo2_pin, OUTPUT);

	s2_pos -= delta;

	if(s2_pos < 30)
		s2_pos = 30;
	
	// s2.write(s2_pos);
	// delay(del);

	// pinMode(servo2_pin, INPUT);

	Serial.print("UP movement ");
	Serial.println(s2_pos);

}

void moveLeft()
{
	// pinMode(servo1_pin, OUTPUT);

	s1_pos += delta;

	if(s1_pos >160)
		s1_pos = 160;
	
	// s1.write(s1_pos);
	// delay(del);
	// pinMode(servo1_pin, INPUT);

	Serial.print("Left movement ");
	Serial.println(s1_pos);

}


void moveRight()
{
	// pinMode(servo1_pin, OUTPUT);

	s1_pos -= delta;

	if(s1_pos <10)
		s1_pos = 10;
	
	// s1.write(s1_pos);
	// delay(del);
	// pinMode(servo1_pin, INPUT);

	Serial.print("Right movement ");
	Serial.println(s1_pos);

}