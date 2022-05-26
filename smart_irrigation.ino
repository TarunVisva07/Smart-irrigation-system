int sensorPin = A0;	  // moisture sensor is connected with the analog pin A0 of the Arduino
int moistureValue = 0;	 // moisture sensor value is initialized to 0
int  motor = 7; 	//Water pump is connected digital pin 7
boolean flag = false;  // a flag variable is used to avoid repetitive iterations in loop
int upperBound = 900;
int lowerBound = 650;
//Configuration of Pins
void setup() {
  //set moisture sensor pin to INPUT
  //set the pin connected to the Pump to OUTPUT

  Serial.begin(9600);
  pinMode(sensorPin, INPUT);
  pinMode( motor, OUTPUT);  
}
 //define loop function to monitor continuously
void loop() {
  //read the value of the Analog pin connected to moisture sensor
  //print the moisture content value in the serial monitor

  moistureValue = analogRead(sensorPin);
  Serial.println(moistureValue);

  //if moisture content value is greater than or equal to upper bound set Pump(motor pin) to HIGH
  //if moisture content value is less than or equal to lower bound set Pump(motor pin) to LOW

  if ( (moistureValue >= upperBound  ) && ( flag == false ) )
{
  digitalWrite( motor, HIGH); 
  flag = true; 
 
}
 
  if ( (moistureValue <= lowerBound  ) && ( flag == true ) )
{
  digitalWrite( motor, LOW); 
  flag = false;
 }
}
