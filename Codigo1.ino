int P1P = A1;
int P2P = A2;
int P3P = A3;

const int A=10,B=11,C=12,D=13, S=9;
float v, dis=1; //Dis -  Distancia entre sensores (cm);

float P1, P2, P3;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  for(int x=10;x<=13;x++){
    pinMode(x,OUTPUT);
  }
  for(int x=9;x<=9;x++){
    pinMode(x,INPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  adquisicion();
  sensado_vaso();
  Serial.println(v);
}
void adquisicion(){
  P1 = analogRead(P1P);
  P2 = analogRead(P2P);
  P3 = analogRead(P3P);

  P1 = map(P1,0,1023,0,100);
  P2 = map(P2,0,1023,0,100);
  P3 = map(P3,0,1023,0,100);
  
}

int sensado_vaso(){
  v=1;
  int muxValue,a=-1;
  for (byte i = 0; i < 15; i++)
   {
      SetMuxChannel(i);
      muxValue = digitalRead(S);
      delay(50);
      if (muxValue == 0 && a==-1)a=v;
      v++;
   }
   v=a*dis;
   delay(1000);
}

int SetMuxChannel(byte channel){
   digitalWrite(A, bitRead(channel, 0));
   digitalWrite(B, bitRead(channel, 1));
   digitalWrite(C, bitRead(channel, 2));
   digitalWrite(D, bitRead(channel, 3));
}
 
