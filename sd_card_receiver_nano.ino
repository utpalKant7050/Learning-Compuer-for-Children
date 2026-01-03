#include <SD.h> 
#include <SPI.h> 
#include <TMRpcm.h> 
#define SD_ChipSelectPin 4
TMRpcm tmrpcm;
#define max_char 90
char message[max_char]; 
char r_char;  
int index = 0,L=0; 
String myst,myst1; 
void setup() {
  tmrpcm.speakerPin = 9;
  Serial.begin(9600);
  SPI.begin();
  pinMode(SD_ChipSelectPin, OUTPUT);
  if(!SD.begin(SD_ChipSelectPin)){
    Serial.print("F");
    return;
  }
  else
  {
    Serial.print("P");  
  }
  tmrpcm.setVolume(5);
  digitalWrite(SD_ChipSelectPin, HIGH); 
  tmrpcm.pause();
  if(true)
  {
  tmrpcm.play("wel.wav");
  }
  //tmrpcm.pause();
}

void loop() {
  digitalWrite(5,1);
 if(Serial.available())
   {  for(int i=0; i<max_char-1;i++)
 {
       message[i]='\0';
 }
       index=0 ;
   }
    while(Serial.available() > 0)
    {       if(index < (max_char)) 
       {         
           r_char = Serial.read();     
           message[index] = r_char;     
          index++;
          L = 1;
   }}
   
    myst1 = String(message) ;
  myst1.trim();
  myst = myst1 + ".wav";
   myst.trim();
  //Serial.println(uttu);
  int utpal = myst.length();
 char uttu[utpal-1];
   for(int j = 0;j<=utpal;j++)
   {
    uttu[j] = myst.charAt(j);
   }
   
    delay(1000);
    if(L == 1)
    {
      digitalWrite(5,0 );
      if(uttu[0]=='|')
  {
    tmrpcm.pause();
  }
   else
   {
   tmrpcm.play(uttu);
   Serial.println(uttu);
    }
    L=0;
    }
  }
    
   
