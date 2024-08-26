#define ECHO 11
#define TRIG 10
#define BUZZ 9
#define RED 4
#define GREEN 2
#define YELLOW 3


float hcsr04(int echo, int trig){
  long duration;
  int distance;
  
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  duration = pulseIn(echo, HIGH);
  distance = duration * 0.034 / 2;
  Serial.print("Distance: ");
  Serial.println(distance);

  return distance;

}

void setup() {
  Serial.begin (9600);
  pinMode(TRIG, OUTPUT); 
  pinMode(ECHO, INPUT); 
  pinMode(BUZZ, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(RED, OUTPUT);
  pinMode(YELLOW, OUTPUT);
}


void loop() {
  int s1 = hcsr04(ECHO, TRIG);
  
  if(s1 < 20){
    tone(BUZZ, 5);
    digitalWrite(RED, HIGH);
    digitalWrite(GREEN, LOW);
    digitalWrite(YELLOW, LOW);
  }
  else if(s1 < 40 && s1 > 20){
    tone(BUZZ, 15);
    digitalWrite(RED, LOW);
    digitalWrite(GREEN, LOW);
    digitalWrite(YELLOW, HIGH);
  }
  else if(s1 > 40){
    noTone(BUZZ);
    digitalWrite(RED, LOW);
    digitalWrite(GREEN, HIGH);
    digitalWrite(YELLOW, LOW);
  }
}