
/*

      Samya Lamichhane 
      Sensor Circuit
      Interactive Media
      Nov 3, 2022

*/ 



int lightSensorPin = A2;                              // Analog pin for photo resistor
int ledPin = 13;                                      // Digital pin location for the LED
int volt_read = 0;                                    // Raw data read by the resistor - initially set to 0
int delayTime = 50;                                   // Flickering rate of the LEDs

void setup()
{
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);                           // Pinmode for digital pin set to OUTPUT
}


void loop ( )
{
  // Reading data from the photoresistor and storing it in volt_read
  volt_read = analogRead(lightSensorPin);

  // Mapping to a range of (0.0 V to 5.0 V)
  float volt_converted = volt_read * (5.0/ 1023);

  // Debugging
  Serial.println("True Voltage: ");                     // Max recorded = 2.80 V
  Serial.println(volt_converted);


  // Calling the function whichSensor() - the return value determines which LED to light up 
  // Return value stored in a global variable
  ledPin = whichSensor(volt_converted);
  Serial.println((ledPin));


  // Conditional to switch off the second LED based on the value stored in ledPin
  if (ledPin == 12)
  {
    digitalWrite(13, LOW);
  }
  else if (ledPin == 13)
  {
    digitalWrite(12, LOW);
  }


  // MAIN LED - flickering effect
  digitalWrite(ledPin, HIGH);
  delay(delayTime);
  digitalWrite(ledPin, LOW);
  delay(delayTime);
  
}



// Function that determines which LED to light up - takes converted volt reading as input
int whichSensor(int volt)
{
  int value_to_be_returned;

  // Check the range of the value and store appropriate value in the return variable and return the integer value stored in it
  if (volt >= 0 && volt < 1.8)
  {
    value_to_be_returned = 13;
  }
  else if (volt >= 1.5 && volt < 4.0)
  {
    value_to_be_returned = 12;
  }

  return value_to_be_returned;
}

