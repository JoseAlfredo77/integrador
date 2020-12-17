int P1P = A1;
int P2P = A2;
int P3P = A3;

const int 
float P1, P2, P3;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  adquisicion();
  
  
}
void adquisicion(){
  P1 = analogRead(P1P);
  P2 = analogRead(P2P);
  P3 = analogRead(P3P);

  P1 = map(P1,0,1023,0,100);
  P2 = map(P2,0,1023,0,100);
  P3 = map(P3,0,1023,0,100);
  
}
