//including MQ sensor library
#include <MQUnifiedsensor.h>

//********************Declaration Hub************************

//********Macro Section - Hardware********
//defining the board as arduino uno
#define Board ("Arduino Uno")
//defining the analog pin
#define Pin ("A0")//im using A0 for this

//********Macro Section - Software********
//defining the type of sensor
#define sensType ("MQ-2") // Im using MQ2 for this
//defining voltage resolution
#define vRes (5) //setting it to 5 volts
//defining adc bit resolution
#define ADCBitRes (10)
//clean air ppm range
#define cleanAirRange (9.83)

//*********Declaring global variables**********
MQUnifiedSensor MQ2(Board,vRes,ADCBitRes,Pin,sensType);


//***********************Setup loop**************************
void setup() {
  //initialising serial port communication
  Serial.begin(9600);

  //building math model to calculate ppm
  MQ2.setRegressionMethod(1); //PPM = a*ratio^b
  //Cigarette emits CO so we will target CO using our smoke sensor
  /*
  CO regression
  a     |   b
  36974 |   -3.109
  */
  MQ2.setA(36974); // a of CO
  MQ2.setB(-3.109); //b of CO

  //initialising MQ2 sensor
  MQ2.init();

  //displaying a message for calibrating the sensor
  Serial.print("Calibrating the sensor....");

  //resistor of sensor
  float calcR0 = 0;
  for(int i = 1; i<=10;i++){
    //updating the data 
    MQ2.update();
    calcR0 += MQ2.calibrate(cleanAirRange);
    Serial.print(".");

  }
  //setting resistance
  MQ2.setR0(calcR0/10);
  Serial.println("  done");

  //in case of infinite resistance or open circuit
  if(isinf(calcR0)) {Serial.println("Warning: Conection issue, R0 is infinite (Open circuit detected) please check your wiring and supply"); while(1);}
  //in case of short circuit
  if(calcR0 == 0){Serial.println("Warning: Conection issue found, R0 is zero (Analog pin shorts to ground) please check your wiring and supply"); while(1);}
  MQ2.serialDebug(true);
}

//************************Main Loop***************************
void loop() {
  //updating the data
  MQ2.update();
  //asking the sensor to read ppm concentration
  MQ2.readSensor();
  //printing table on serial port
  MQ2.serialDebug();
  //adding a delay or timer
  delay(500);

}
