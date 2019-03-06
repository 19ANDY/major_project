
int data;
int LEDBUILTIN=6;

void setup() { 
  Serial.begin(9600); //initialize serial COM at 9600 baudrate
  pinMode(LEDBUILTIN, OUTPUT); //make the motor pin (6) as output
  digitalWrite (LEDBUILTIN, LOW);
  
  Serial.println("Hi!, I am Arduino");
}
 
void loop() {
while (Serial.available()){
  data = Serial.read();
}

if (data == '1')
{digitalWrite (LEDBUILTIN, HIGH);
delay(2000);
digitalWrite (LEDBUILTIN, LOW);
delay(2000);
data=0;
}

else if (data == '0')
digitalWrite (LEDBUILTIN, LOW);

}
