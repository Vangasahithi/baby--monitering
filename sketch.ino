int sensorState = 0;
int baselineTemp = 0;
int celsius = 0;

void setup()
{
  	pinMode(2, INPUT);
  	pinMode(13, OUTPUT);
  	pinMode(12, OUTPUT);
  	pinMode(A0, INPUT);
  	pinMode(3, OUTPUT);
  	pinMode(4, OUTPUT);
  	pinMode(5, OUTPUT);
  
  	Serial.begin(9600);
}

void loop()
{

    sensorState = digitalRead(2);
  
  	if (sensorState == HIGH) 
    {
    	digitalWrite(13, HIGH);
      	digitalWrite(12, HIGH);

    	Serial.println("Senzor miscare activat!");
  	} 
  	else 
    {
    	digitalWrite(13, LOW);
      	digitalWrite(12, LOW);
  	}
    
  	baselineTemp = 37;
  
  	celsius = map(((analogRead(A0) - 20) * 3.04), 0, 1023, -40, 125);
  	
  	if (celsius < baselineTemp) {
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
  }
  if (celsius >= baselineTemp) {
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
  }
  if (celsius >= baselineTemp + 1) {
    digitalWrite(3, LOW);
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
  }
  if (celsius >= baselineTemp + 2) {
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, HIGH);
  }

  
  	Serial.print(celsius);
  	Serial.println(" C, ");
  
  	delay(10);
}