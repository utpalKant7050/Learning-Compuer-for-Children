#include <TimerOne.h>
#include <Arduino.h>
#include <U8g2lib.h>
#include <Arduino_FreeRTOS.h> 
#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif
#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h>
#endif
int d = 1,d1 = 40,x0,y0,circum,so,up,down,done;
int Y[]={0,0,0,0,0,0,0,0,0,0};
//const int pinx[] = {6,5,4,3,2};
//const int piny[] = {22,23,24,25,26,27},left_butt = 18,done_butt = 17,right_butt = 16,back_butt = 20,home_butt = 21;
const int pinx[] = {2,3,4,5,6};
const int piny[] = {22,23,24,25,26,27},left_butt = 18,done_butt = 17,right_butt = 16,back_butt = 19,home_butt = 21;
int ok,uk,uk1,uk2; int px = 0,py = 15;  
bool buttonState1,buttonState2,buttonState3,buttonState4,count1;      
int lastButtonState1 = 1; 
int lastButtonState2 = 1; 
int lastButtonState3 = 1; 
int lastButtonState4 = 1; 
//int lastButtonState5 = 1; 
//unsigned long cmilli,pmilli;
byte sum1,sum2;
U8G2_ST7920_128X64_F_SW_SPI u8g2(U8G2_R0, /* clock=*/ 52, /* data=*/ 51, /* CS=*/ 53, /* reset=*/ 50);
////////////////////////////////////////////////////////////////////////
/////////////////////game/////////////////////////////////////////////


#define ST_FP 3


/////////////animalkingdom///////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////

static const unsigned char congrats[] PROGMEM = {
   0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
   0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x07,
   0xe0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf9, 0xff, 0xff,
   0xff, 0xff, 0x3f, 0xf8, 0x1f, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
   0x7f, 0xe6, 0xff, 0xff, 0xff, 0xff, 0xc7, 0xff, 0xff, 0xf1, 0xff, 0xff,
   0xff, 0xff, 0x07, 0xff, 0x9f, 0xdf, 0xff, 0xff, 0xff, 0xff, 0xf9, 0xff,
   0xff, 0xcf, 0xff, 0xff, 0xff, 0xff, 0xfb, 0xfc, 0xdf, 0xdf, 0xff, 0xff,
   0xff, 0x7f, 0xfe, 0xff, 0xff, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xfd, 0xf9,
   0xef, 0x9f, 0xff, 0xff, 0xff, 0xbf, 0xff, 0xff, 0xff, 0xff, 0xfc, 0xff,
   0xff, 0xff, 0xfd, 0xfb, 0xef, 0xbf, 0xff, 0xff, 0xff, 0xcf, 0xff, 0xff,
   0xff, 0xff, 0xfb, 0xff, 0xff, 0xff, 0xfd, 0xf7, 0xef, 0xbf, 0xff, 0xff,
   0xff, 0xf7, 0xff, 0xff, 0xff, 0xff, 0xe7, 0xff, 0xff, 0xff, 0xfd, 0xf7,
   0xef, 0xbf, 0xff, 0xff, 0xff, 0xfb, 0x07, 0xfc, 0xff, 0xff, 0xcf, 0xff,
   0xff, 0xff, 0xfe, 0xf7, 0xef, 0xbf, 0xff, 0xff, 0xff, 0xfd, 0xf3, 0xf3,
   0xff, 0xff, 0x9f, 0xff, 0xff, 0xff, 0xfe, 0xf7, 0xef, 0x7f, 0xff, 0xff,
   0xff, 0xfe, 0xf9, 0xe7, 0x7f, 0xe0, 0x3f, 0xff, 0xff, 0xff, 0xfe, 0xfb,
   0xcf, 0x7f, 0xff, 0xff, 0x7f, 0xff, 0xfc, 0xcf, 0x3f, 0x9f, 0x7f, 0xfe,
   0xff, 0xff, 0xfe, 0xfb, 0xdf, 0x7f, 0xfe, 0xff, 0xbf, 0x7f, 0xfe, 0x9f,
   0xdf, 0x7f, 0xfe, 0xfc, 0xff, 0x7f, 0xff, 0xfb, 0x9f, 0xff, 0xfe, 0xff,
   0xdf, 0x7f, 0xff, 0xbf, 0xef, 0xff, 0xfc, 0xfd, 0xff, 0x3f, 0xff, 0xfd,
   0x3f, 0xff, 0xfd, 0xff, 0xcf, 0x3f, 0xff, 0x3f, 0xef, 0xff, 0xfd, 0xfb,
   0xff, 0xbf, 0xff, 0xfc, 0x7f, 0xfc, 0xfb, 0xff, 0xef, 0xbf, 0x1f, 0x7e,
   0xf7, 0xf1, 0xfb, 0xf3, 0xff, 0xdf, 0x7f, 0xfe, 0xff, 0xfc, 0xe7, 0xff,
   0xf7, 0xbf, 0x37, 0x7c, 0xf7, 0xe3, 0xfb, 0xf7, 0xff, 0xe7, 0x0f, 0xff,
   0xff, 0xf9, 0x9f, 0xff, 0xf7, 0xbf, 0x37, 0xf8, 0x76, 0xc0, 0xf3, 0xef,
   0xff, 0xf3, 0x9f, 0xff, 0xff, 0xf3, 0x7f, 0xfe, 0xfb, 0xbf, 0x07, 0xf8,
   0x76, 0xc0, 0xf7, 0xef, 0x7f, 0xfc, 0xef, 0xff, 0xff, 0xf7, 0xff, 0xfd,
   0xfb, 0xbf, 0x07, 0xf8, 0x7e, 0xc0, 0xf7, 0xcf, 0x3f, 0xff, 0xe7, 0xff,
   0xff, 0xef, 0xff, 0xfb, 0xf9, 0xbf, 0x07, 0xf8, 0xfe, 0xe0, 0xf7, 0xdf,
   0xdf, 0xff, 0xf7, 0xff, 0xff, 0xe7, 0xff, 0xf7, 0xfd, 0xbf, 0x0f, 0xfc,
   0xf6, 0xf1, 0xf7, 0xdf, 0xef, 0xff, 0xf7, 0xff, 0xff, 0xe1, 0xff, 0xef,
   0xfd, 0xbf, 0x1f, 0x7f, 0xf6, 0xff, 0xfb, 0xbf, 0xf7, 0xff, 0xc7, 0xff,
   0x7f, 0xfe, 0xff, 0xdf, 0xfc, 0x3f, 0xff, 0x7f, 0xf7, 0xff, 0xfb, 0xbf,
   0xfb, 0xff, 0x37, 0xff, 0x9f, 0xff, 0xff, 0xdf, 0xfe, 0x7f, 0xff, 0x3f,
   0xef, 0xff, 0xf9, 0xbf, 0xfb, 0xff, 0xff, 0xfc, 0xe7, 0xff, 0xff, 0xdf,
   0xfe, 0xff, 0xfe, 0xbf, 0xef, 0xff, 0x8d, 0xbf, 0xfd, 0xff, 0xff, 0xf3,
   0xf3, 0x8f, 0xfc, 0xbf, 0xfe, 0xff, 0xf9, 0xcf, 0x9f, 0x7f, 0x7e, 0x3e,
   0xfd, 0x3f, 0xfc, 0xe7, 0xfb, 0xe0, 0xfb, 0xbf, 0x0e, 0xfe, 0xe3, 0xe3,
   0x7f, 0x80, 0x3f, 0x3c, 0xfd, 0xcf, 0x87, 0xcf, 0xfd, 0xff, 0xf7, 0xbf,
   0xc6, 0xff, 0x1f, 0xf8, 0xff, 0xff, 0x8f, 0x7d, 0xfd, 0xef, 0xf7, 0xdf,
   0xfd, 0xff, 0xf7, 0xbf, 0x16, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe7, 0x7d,
   0xfd, 0xf7, 0xff, 0xdf, 0xfd, 0xff, 0xf7, 0xbf, 0x7e, 0xfc, 0xff, 0xff,
   0xff, 0xff, 0xe1, 0x7f, 0xfd, 0xf7, 0xff, 0xdf, 0xfd, 0xff, 0xf7, 0xbf,
   0xfe, 0xf0, 0xff, 0xff, 0xff, 0x3f, 0xf6, 0x7f, 0xfd, 0xf7, 0xff, 0xdf,
   0xfb, 0xff, 0xf7, 0xdf, 0xfe, 0xc3, 0xff, 0xff, 0xff, 0x8f, 0xfb, 0x3f,
   0xfd, 0xef, 0xff, 0xdf, 0xf3, 0xff, 0xc3, 0x9f, 0xfe, 0x07, 0xfc, 0xff,
   0xff, 0xe0, 0xfb, 0x3f, 0xf9, 0xe3, 0xff, 0xcf, 0xe7, 0xff, 0xb9, 0xbf,
   0xfe, 0xcf, 0xc1, 0xff, 0x0f, 0xf8, 0xfd, 0xbf, 0xfd, 0xcd, 0xff, 0xe7,
   0x8f, 0x7f, 0x3e, 0xbe, 0xfe, 0x9f, 0x0f, 0x00, 0x80, 0x7f, 0xfc, 0xbf,
   0xfd, 0x9c, 0xff, 0xf3, 0x2f, 0x00, 0xbf, 0xbf, 0xfc, 0x3f, 0xff, 0x00,
   0xf8, 0x3f, 0xfe, 0xbf, 0xff, 0x7c, 0x7c, 0xf8, 0xef, 0xff, 0x3f, 0xbe,
   0xfd, 0x7f, 0xf8, 0xff, 0xff, 0x0f, 0xfe, 0xbf, 0x7f, 0xfc, 0x83, 0xfb,
   0xef, 0xff, 0xdf, 0xbe, 0xfd, 0xff, 0xc0, 0xff, 0xff, 0x03, 0xfe, 0x9f,
   0x7d, 0xfd, 0xff, 0xfb, 0xdf, 0xff, 0xcf, 0xde, 0xfd, 0xff, 0x01, 0xfc,
   0x7f, 0x00, 0xff, 0xdf, 0xbd, 0xf9, 0xff, 0xfb, 0x9f, 0xff, 0xe7, 0xd8,
   0xfb, 0xff, 0x03, 0x00, 0x00, 0x00, 0xff, 0xdf, 0x9b, 0xf3, 0xff, 0xfd,
   0x7f, 0xfe, 0xf1, 0xe2, 0xfb, 0xff, 0x07, 0xe0, 0x3f, 0x80, 0xff, 0xef,
   0x0b, 0xe7, 0xff, 0xfe, 0x7f, 0x00, 0x7e, 0xf7, 0xf3, 0xff, 0x0f, 0xfe,
   0xff, 0x81, 0xff, 0xef, 0x67, 0x1f, 0x1e, 0xff, 0x7f, 0xff, 0x3f, 0xfb,
   0xf7, 0xff, 0xcf, 0xff, 0xff, 0xc7, 0xff, 0xe7, 0x6f, 0xfe, 0x60, 0xff,
   0x7f, 0xff, 0x9f, 0xfb, 0xef, 0xff, 0x9f, 0xff, 0xff, 0xcf, 0xff, 0xf7,
   0xef, 0xfc, 0x7f, 0xff, 0xff, 0xfe, 0xcf, 0xfb, 0xcf, 0xff, 0x3f, 0xff,
   0xff, 0xe7, 0xff, 0xfb, 0xcf, 0xf9, 0x7f, 0xff, 0xff, 0xfd, 0xf3, 0xfd,
   0xdf, 0xff, 0x7f, 0xfe, 0xff, 0xf1, 0xff, 0xf9, 0xdf, 0xe3, 0xbf, 0xff,
   0xff, 0x03, 0xfc, 0xfe, 0xbf, 0xff, 0xff, 0xf0, 0x1f, 0xf0, 0xff, 0xfc,
   0xbf, 0x0f, 0xc6, 0xff, 0xff, 0xcf, 0x3f, 0xff, 0x3f, 0xff, 0xff, 0x19,
   0xf8, 0xf9, 0xff, 0xfe, 0x7f, 0xfe, 0xf0, 0xff, 0xff, 0x1f, 0xc0, 0xff,
   0x7f, 0xfe, 0xff, 0xf3, 0x7f, 0xfe, 0x7f, 0xff, 0xff, 0xf1, 0xf9, 0xff,
   0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0xff, 0xc7, 0x1f, 0xff, 0xbf, 0xff,
   0xff, 0x07, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf9, 0xff, 0x1f,
   0xc0, 0xff, 0xdf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
   0xff, 0xf3, 0xff, 0xff, 0xf0, 0xff, 0xe7, 0xff, 0xff, 0xff, 0xff, 0xff,
   0xff, 0xff, 0xff, 0xff, 0xff, 0xe7, 0xff, 0xff, 0xff, 0xff, 0xf3, 0xff,
   0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x9f, 0xff, 0xff,
   0xff, 0xff, 0xf8, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
   0xff, 0x3f, 0xfe, 0xff, 0xff, 0x7f, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff,
   0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 0xff, 0xff, 0x8f, 0xff, 0xff,
   0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc3, 0xff,
   0xff, 0xe3, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
   0xff, 0xff, 0x1f, 0xfc, 0x3f, 0xf8, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
   0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x80, 0xff, 0xff, 0xff,
   0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
   0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
   0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
   0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
   0xff, 0xff, 0xff, 0xff };


void animals(byte type)
{
  switch(type)
  {
     case 1: Serial3.write("bear");
  u8g2.drawStr(px,py,"bear");
  u8g2_draw_unifont_devanagari(0,35,"भालू");break;
  case 2:  Serial3.write("camel");
  u8g2.drawStr(px,py,"camel");
  u8g2_draw_unifont_devanagari(0,35,"ऊंट");break;
  case 3:Serial3.write("cheeta");
  u8g2.drawStr(px,py,"cheeta");
  u8g2_draw_unifont_devanagari(0,35,"चीता");break;
  case 4:Serial3.write("elephant");
  u8g2.drawStr(px,py,"elephant");
  u8g2_draw_unifont_devanagari(0,35,"हाथी");break;
  case 5: Serial3.write("deer");
  u8g2.drawStr(px,py,"deer");
  u8g2_draw_unifont_devanagari(0,35,"हिरण");break;
  case 6: Serial3.write("boar");
  u8g2.drawStr(px,py,"boar");
  u8g2_draw_unifont_devanagari(0,35,"सूअर");break;
  case 7: Serial3.write("fox");
  u8g2.drawStr(px,py,"fox");
  u8g2_draw_unifont_devanagari(0,35,"लोमड़ी");break;
  case 8:Serial3.write("lion");
  u8g2.drawStr(px,py,"lion");
  u8g2_draw_unifont_devanagari(0,35,"सिंह");break;
  case 9: Serial3.write("tiger");
  u8g2.drawStr(px,py,"tiger");
  u8g2_draw_unifont_devanagari(0,35,"बाघ");break;
  case 10:Serial3.write("zebra");
  u8g2.drawStr(px,py,"zebra");
  u8g2_draw_unifont_devanagari(0,35,"ज़ेबरा");break; }
}
void birds(byte type)
{
  switch(type)
  {
  case 1: Serial3.write("cock");
  u8g2.drawStr(px,py,"Cock");
  u8g2_draw_unifont_devanagari(0,35,"मुर्गा");break;
  case 2:  Serial3.write("crow");
  u8g2.drawStr(px,py,"crow");
  u8g2_draw_unifont_devanagari(0,35,"कौआ");break;
  case 3:Serial3.write("duck");
  u8g2.drawStr(px,py,"duck");
  u8g2_draw_unifont_devanagari(0,35,"बत्तख");break;
  case 4:Serial3.write("hen");
  u8g2.drawStr(px,py,"hen");
  u8g2_draw_unifont_devanagari(0,35,"मुर्गी");break;
  case 5: Serial3.write("owl");
  u8g2.drawStr(px,py,"owl");
  u8g2_draw_unifont_devanagari(0,35,"  उल्लू");break;
  case 6: Serial3.write("parrot");
  u8g2.drawStr(px,py,"parrot");
  u8g2_draw_unifont_devanagari(0,35,"तोता");break;
  case 7: Serial3.write("peacock");
  u8g2.drawStr(px,py,"peacock");
  u8g2_draw_unifont_devanagari(0,35,"मोर");break;
  case 8:Serial3.write("pigeon");
  u8g2.drawStr(px,py,"pigeon");
  u8g2_draw_unifont_devanagari(0,35,"कबूतर");break;
  case 9: Serial3.write("swan");
  u8g2.drawStr(px,py,"swan");
  u8g2_draw_unifont_devanagari(0,35,"हंस");break;
  case 10:Serial3.write("mainya");
  u8g2.drawStr(px,py,"mainya");
  u8g2_draw_unifont_devanagari(0,35,"मैना");break; 
  }
}

void fruits(byte type)
{
  switch(type)
  {
    case 1: Serial3.write("apple");
  u8g2.drawStr(px,py,"Apple");
  u8g2_draw_unifont_devanagari(0,35,"सेव");break;
  case 2:  Serial3.write("banana");
  u8g2.drawStr(px,py,"Banana");
  u8g2_draw_unifont_devanagari(0,35,"केला");break;
  case 3:Serial3.write("coconut");
  u8g2.drawStr(px,py,"Coconut");
  u8g2_draw_unifont_devanagari(0,35,"नारियल");break;
  case 4:Serial3.write("grapes");
  u8g2.drawStr(px,py,"Grapes");
  u8g2_draw_unifont_devanagari(0,35,"अंगूर");break;
  case 5: Serial3.write("guava");
  u8g2.drawStr(px,py,"guava");
  u8g2_draw_unifont_devanagari(0,35,"अमरूद");break;
  case 6: Serial3.write("mango");
  u8g2.drawStr(px,py,"mango");
  u8g2_draw_unifont_devanagari(0,35,"आम");break;
  case 7: Serial3.write("orange");
  u8g2.drawStr(px,py,"orange");
  u8g2_draw_unifont_devanagari(0,35,"संतरा");break;
  case 8:Serial3.write("papaya");
  u8g2.drawStr(px,py,"papaya");
  u8g2_draw_unifont_devanagari(0,35,"पपीता");break;
  case 9: Serial3.write("lichy");
  u8g2.drawStr(px,py,"lichi");
  u8g2_draw_unifont_devanagari(0,35,"लिची");break;
  case 10:Serial3.write("waterm");
  u8g2.drawStr(px,py,"Watermelon");
  u8g2_draw_unifont_devanagari(0,35,"तरबूज");break; 
  
 /* case 11: Serial3.write("canna");
  u8g2.drawStr(px,py,"canna");
  u8g2_draw_unifont_devanagari(0,35,"देवकली");break; 
  case 12: Serial3.write("lily");
  u8g2.drawStr(px,py,"lily");
  u8g2_draw_unifont_devanagari(0,35,"कुमुदनी");break;
  case 13:Serial3.write("bluewaterlily");
  u8g2.drawStr(px,py,"bluewaterlily");
  u8g2_draw_unifont_devanagari(0,35,"निलकमल");break; 
  case 14:Serial3.write("delonixrezia");
  u8g2.drawStr(px,py,"dalonixregia");
  u8g2_draw_unifont_devanagari(0,35,"गुलमुहर");break;
  case 15: Serial3.write("morningglory");
  u8g2.drawStr(px,py,"morning glory");
  u8g2_draw_unifont_devanagari(0,35,"महिमा फूल ");break;
  case 16: Serial3.write("olender");
  u8g2.drawStr(px,py,"oleander");
  u8g2_draw_unifont_devanagari(0,35,"कनेर");break;
  case 17: Serial3.write("palcy");
  u8g2.drawStr(px,py,"pansy");
  u8g2_draw_unifont_devanagari(0,35,"बन फूल");break;
  case 18: Serial3.write("iris");
  u8g2.drawStr(px,py,"iris");
  u8g2_draw_unifont_devanagari(0,35,"आईरिस ");break;*/
}}

//static const unsigned char lotus[] PROGMEM =
    void flowers(byte type)
{
  switch(type)
  {
    case 1: Serial3.write("rose");
  u8g2.drawStr(px,py,"rose");
  u8g2_draw_unifont_devanagari(0,35,"गुलाब");break;
  case 2:  Serial3.write("sweetj");
  u8g2.drawStr(px,py,"sweetjasmine");
  u8g2_draw_unifont_devanagari(0,35,"जूही");break;
  case 3:Serial3.write("lotus");
  u8g2.drawStr(px,py,"lotus");
  u8g2_draw_unifont_devanagari(0,35,"कमल");break;
  case 4:
  Serial3.write("jasmine");
  u8g2.drawStr(px,py,"jasmine");
  u8g2_draw_unifont_devanagari(0,35,"चमेली");break;
  case 5: Serial3.write("daffodil");
  u8g2.drawStr(px,py,"daffodil");
  u8g2_draw_unifont_devanagari(0,35,"नरगिस");break;
  case 6: Serial3.write("dailia");
  u8g2.drawStr(px,py,"dahlia");
  u8g2_draw_unifont_devanagari(0,35,"गुलदावदी");break;
  case 7: 
   Serial3.write("marigold");
  u8g2.drawStr(px,py,"marigold");
  u8g2_draw_unifont_devanagari(0,35,"गेंदे का फूल");break;
  case 8:Serial3.write("plumeria");
  u8g2.drawStr(px,py,"plumeria");
  u8g2_draw_unifont_devanagari(0,35,"चंपा ");break;
  case 9: Serial3.write("hibiscus");
  u8g2.drawStr(px,py,"hibiscus");
  u8g2_draw_unifont_devanagari(0,35,"गुड़हल");break;
  case 10:Serial3.write("periw");
  u8g2.drawStr(px,py,"periwinkle");
  u8g2_draw_unifont_devanagari(0,35,"सदाबहार");break; 
  
 /* case 11: Serial3.write("canna");
  u8g2.drawStr(px,py,"canna");
  u8g2_draw_unifont_devanagari(0,35,"देवकली");break; 
  case 12: Serial3.write("lily");
  u8g2.drawStr(px,py,"lily");
  u8g2_draw_unifont_devanagari(0,35,"कुमुदनी");break;
  case 13:Serial3.write("bluewaterlily");
  u8g2.drawStr(px,py,"bluewaterlily");
  u8g2_draw_unifont_devanagari(0,35,"निलकमल");break; 
  case 14:Serial3.write("delonixrezia");
  u8g2.drawStr(px,py,"dalonixregia");
  u8g2_draw_unifont_devanagari(0,35,"गुलमुहर");break;
  case 15: Serial3.write("morningglory");
  u8g2.drawStr(px,py,"morning glory");
  u8g2_draw_unifont_devanagari(0,35,"महिमा फूल ");break;
  case 16: Serial3.write("olender");
  u8g2.drawStr(px,py,"oleander");
  u8g2_draw_unifont_devanagari(0,35,"कनेर");break;
  case 17: Serial3.write("palcy");
  u8g2.drawStr(px,py,"pansy");
  u8g2_draw_unifont_devanagari(0,35,"बन फूल");break;
  case 18: Serial3.write("iris");
  u8g2.drawStr(px,py,"iris");
  u8g2_draw_unifont_devanagari(0,35,"आईरिस ");break;
  case 19: Serial3.write("dizy");
  u8g2.drawStr(px,py,"daisy");
  u8g2_draw_unifont_devanagari(0,35,"गुल बहार");break;
  case 20: Serial3.write("zeinia");
  u8g2.drawStr(px,py,"zinnia");
  u8g2_draw_unifont_devanagari(0,35,"ज़ेनिआ");break;
     case 21: Serial3.write("tulip");
  u8g2.drawStr(px,py,"tulip");
  u8g2_draw_unifont_devanagari(0,35,"मालिनी");break;
     case 22: Serial3.write("tuberose");
  u8g2.drawStr(px,py,"tube rose");
  u8g2_draw_unifont_devanagari(0,35,"रजनीगंधा");break;
     case 23:
  Serial3.write("bluebell");
  u8g2.drawStr(px,py,"bluebell");
  u8g2_draw_unifont_devanagari(0,35,"निल घंटी");break;
   case 24: Serial3.write(toycathon_logo"starglory");
  u8g2.drawStr(px,py,"star glory");
  u8g2_draw_unifont_devanagari(0,35,"काम लता");break;
   case 25: 
  Serial3.write("aster");
  u8g2.drawStr(px,py,"aster");
  u8g2_draw_unifont_devanagari(0,35,"तारक पुष्प");break;
     */ }
}
  
static const unsigned char toycathon_logo[] PROGMEM = {
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0xf8, 0x2f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x7f, 0xff, 0x01, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x03, 0xc0,
   0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x78, 0x00, 0x00, 0x3c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x1e, 0x00, 0x00, 0xf0, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00,
   0xc0, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x80, 0x03, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x1c, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x00, 0x00, 0x00,
   0x00, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0xa8, 0x5a, 0xdb, 0xb6, 0x6d,
   0x7f, 0x00, 0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf8,
   0xff, 0xff, 0xff, 0xff, 0x3d, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x1c, 0x00, 0x00, 0x00, 0x00, 0x1c, 0x00, 0x00, 0x00,
   0x00, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x00, 0x00, 0x00, 0x00,
   0x18, 0x00, 0x00, 0x00, 0x00, 0x80, 0x01, 0x00, 0x00, 0x00, 0x00, 0x1c,
   0x00, 0x00, 0x00, 0x00, 0x1c, 0x00, 0x80, 0x0f, 0x00, 0x80, 0x01, 0x00,
   0x00, 0x00, 0x00, 0x18, 0x00, 0x00, 0x00, 0x00, 0x1c, 0x00, 0x80, 0x1f,
   0x00, 0x80, 0x03, 0x00, 0x00, 0x00, 0x00, 0x1c, 0x00, 0x00, 0x00, 0x00,
   0x1c, 0x00, 0xc0, 0x0f, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x1c,
   0x00, 0x00, 0x00, 0x00, 0x1c, 0x00, 0x00, 0x07, 0x00, 0x00, 0x07, 0x00,
   0x00, 0x00, 0x00, 0x1c, 0x00, 0x00, 0x00, 0x00, 0x1c, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x18, 0x00, 0x00, 0x00, 0x00,
   0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x00, 0x1c,
   0x00, 0x00, 0x00, 0x00, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00,
   0x00, 0x00, 0x00, 0x18, 0x00, 0x00, 0x00, 0x00, 0x38, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x00, 0x1c, 0x00, 0x00, 0x00, 0x00,
   0x70, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x40, 0xff, 0x1d,
   0x00, 0x00, 0x00, 0x00, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00,
   0x00, 0xfc, 0xea, 0x1f, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x01, 0x00, 0x00,
   0x00, 0x80, 0x03, 0x00, 0x00, 0x06, 0x00, 0x0c, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x07, 0x00, 0x00, 0x00, 0x80, 0x03, 0x00, 0x80, 0x03, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x0e, 0x00, 0x00, 0x00, 0x80, 0x01, 0x00,
   0x80, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf8, 0x02, 0x00,
   0x00, 0xc0, 0x03, 0x00, 0xc0, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0xc0, 0x1f, 0x00, 0x00, 0xc0, 0x00, 0x00, 0xc0, 0x01, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0xc0, 0x01, 0x00,
   0xc0, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0xe0, 0x00, 0x00, 0x80, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x60, 0x00, 0x00, 0x80, 0x03, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x70, 0x00, 0x00,
   0x00, 0x07, 0x00, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x38, 0x00, 0x00, 0x00, 0x0e, 0xe0, 0x07, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x38, 0x00, 0x00, 0x00, 0xfc, 0xff, 0x0e,
   0x00, 0x00, 0xe0, 0x0f, 0x00, 0x00, 0xe0, 0x03, 0x00, 0x1c, 0x00, 0x00,
   0x00, 0xd0, 0x0f, 0x0e, 0x00, 0x00, 0x7e, 0x7c, 0x00, 0x00, 0xf8, 0x00,
   0x00, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x00, 0x06, 0xe0,
   0x00, 0x00, 0x1c, 0x00, 0x00, 0x0e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06,
   0x00, 0x80, 0x01, 0xc0, 0x01, 0x00, 0x07, 0x00, 0x00, 0x07, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x0c, 0x00, 0x80, 0x01, 0x80, 0x03, 0x00, 0x07, 0x00,
   0x80, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0e, 0x00, 0xc0, 0x01, 0x80,
   0x03, 0x80, 0x03, 0x00, 0x80, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0c,
   0x00, 0xc0, 0x01, 0x00, 0x03, 0x80, 0x03, 0x00, 0xc0, 0x01, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x06, 0x00, 0xc0, 0x00, 0x80, 0x03, 0x80, 0x03, 0x00,
   0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0e, 0x00, 0xc0, 0x01, 0x80,
   0x03, 0x00, 0x03, 0x00, 0x70, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0e,
   0x00, 0xc0, 0x01, 0x80, 0x01, 0x80, 0x03, 0x00, 0x38, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x0c, 0x00, 0xc0, 0x01, 0x80, 0x01, 0x00, 0x06, 0x00,
   0x1c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0e, 0x80, 0xfe, 0x01, 0xc0,
   0x7f, 0xff, 0x0f, 0x00, 0x0e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfc,
   0xff, 0xfb, 0x01, 0xc0, 0xf7, 0xfd, 0x3f, 0x80, 0x07, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0xf5,
   0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x5f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x3c, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x02, 0x80,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x00, 0x00, 0x80, 0x0c,
   0x00, 0x00, 0xdf, 0xef, 0x1b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10,
   0x37, 0x39, 0xc3, 0x3d, 0x8e, 0x02, 0xd9, 0x28, 0x13, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0xd8, 0x6c, 0x85, 0xd9, 0x6c, 0xd1, 0x04, 0x49, 0x0c,
   0x11, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x90, 0xc5, 0x8c, 0xcd, 0x64,
   0xdb, 0x0c, 0xce, 0xcc, 0x19, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08,
   0xc6, 0x38, 0x8b, 0x04, 0x8c, 0x04, 0x9e, 0xe3, 0x03, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00 };
 
 static const unsigned char sad[]PROGMEM = {
   0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
   0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
   0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
   0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
   0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x07, 0x00, 0x00, 0xe0, 0xff, 0xff,
   0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x0f, 0x00, 0x00,
   0x00, 0x00, 0xe0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
   0x7f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0xff, 0xff, 0xff, 0xff,
   0xff, 0xff, 0xff, 0xff, 0x07, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0xc0,
   0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x00, 0x00, 0xfe, 0xff,
   0xff, 0xff, 0x00, 0x00, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x1f,
   0x00, 0xf8, 0xff, 0xff, 0xff, 0xff, 0x1f, 0x00, 0xf0, 0xff, 0xff, 0xff,
   0xff, 0xff, 0xff, 0x03, 0x80, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x01,
   0xc0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0xf0, 0xff, 0xff, 0xff,
   0xff, 0xff, 0xff, 0x1f, 0x00, 0xfe, 0xff, 0xff, 0xff, 0xff, 0x1f, 0x00,
   0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0xf8, 0xff, 0xff,
   0xff, 0xff, 0x0f, 0xc0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
   0x03, 0xe0, 0xff, 0xff, 0xff, 0xff, 0x03, 0xf0, 0xff, 0xff, 0xff, 0xff,
   0xff, 0xff, 0xff, 0xff, 0x0f, 0x80, 0xff, 0xff, 0xff, 0xff, 0x00, 0xfc,
   0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x3f, 0x00, 0xff, 0xff,
   0xff, 0x7f, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
   0xff, 0x00, 0xfc, 0xff, 0xff, 0x1f, 0xc0, 0xff, 0xff, 0xff, 0xff, 0xff,
   0xff, 0xff, 0xff, 0xff, 0xff, 0x03, 0xf8, 0xff, 0xff, 0x0f, 0xe0, 0xff,
   0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x07, 0xf0, 0xff,
   0xff, 0x07, 0xf0, 0xff, 0xff, 0x00, 0xfc, 0xff, 0xff, 0x3f, 0x00, 0xff,
   0xff, 0x1f, 0xe0, 0xff, 0xff, 0x03, 0xfc, 0xff, 0x3f, 0x00, 0xe0, 0xff,
   0xff, 0x0f, 0x00, 0xfc, 0xff, 0x3f, 0xc0, 0xff, 0xff, 0x01, 0xfe, 0xff,
   0x1f, 0x00, 0xc0, 0xff, 0xff, 0x03, 0x00, 0xf0, 0xff, 0x7f, 0x80, 0xff,
   0xff, 0x00, 0xff, 0xff, 0x0f, 0x00, 0x80, 0xff, 0xff, 0x03, 0x00, 0xf0,
   0xff, 0xff, 0x00, 0xff, 0x7f, 0x80, 0xff, 0xff, 0x0f, 0x00, 0x80, 0xff,
   0xff, 0x03, 0x00, 0xf0, 0xff, 0xff, 0x01, 0xfe, 0x7f, 0x80, 0xff, 0xff,
   0x0f, 0x00, 0xc0, 0xff, 0xff, 0x03, 0x00, 0xf0, 0xff, 0xff, 0x03, 0xfc,
   0x3f, 0xc0, 0xff, 0xff, 0x1f, 0x00, 0xc0, 0xff, 0xff, 0x07, 0x00, 0xf8,
   0xff, 0xff, 0x03, 0xfc, 0x3f, 0xc0, 0xff, 0xff, 0x7f, 0x00, 0xf0, 0xff,
   0xff, 0x0f, 0x00, 0xfc, 0xff, 0xff, 0x07, 0xf8, 0x3f, 0xe0, 0xff, 0xff,
   0xff, 0x03, 0xfe, 0xff, 0xff, 0x7f, 0x80, 0xff, 0xff, 0xff, 0x07, 0xf8,
   0x1f, 0xe0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
   0xff, 0xff, 0x0f, 0xf8, 0x1f, 0xf0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
   0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x0f, 0xf8, 0x1f, 0xf0, 0xff, 0xff,
   0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x0f, 0xf8,
   0x1f, 0xf0, 0xff, 0xff, 0xff, 0xff, 0x1f, 0x00, 0x00, 0xf8, 0xff, 0xff,
   0xff, 0xff, 0x0f, 0xf8, 0x1f, 0xf0, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00,
   0x00, 0x00, 0xfe, 0xff, 0xff, 0xff, 0x0f, 0xf8, 0x1f, 0xf0, 0xff, 0xff,
   0xff, 0x0f, 0x00, 0x00, 0x00, 0x00, 0xf0, 0xff, 0xff, 0xff, 0x0f, 0xf8,
   0x1f, 0xf0, 0xff, 0xff, 0xff, 0x03, 0x00, 0x00, 0x00, 0x00, 0x80, 0xff,
   0xff, 0xff, 0x0f, 0xf8, 0x1f, 0xe0, 0xff, 0xff, 0xff, 0x00, 0x00, 0xfc,
   0x7f, 0x00, 0x00, 0xfe, 0xff, 0xff, 0x0f, 0xf8, 0x1f, 0xe0, 0xff, 0xff,
   0x3f, 0x00, 0xf8, 0xff, 0xff, 0x3f, 0x00, 0xf8, 0xff, 0xff, 0x0f, 0xf8,
   0x3f, 0xe0, 0xff, 0xff, 0x0f, 0x80, 0xff, 0xff, 0xff, 0xff, 0x03, 0xf0,
   0xff, 0xff, 0x07, 0xf8, 0x3f, 0xc0, 0xff, 0xff, 0x07, 0xf0, 0xff, 0xff,
   0xff, 0xff, 0x1f, 0xc0, 0xff, 0xff, 0x07, 0xfc, 0x7f, 0xc0, 0xff, 0xff,
   0x03, 0xfc, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x80, 0xff, 0xff, 0x03, 0xfc,
   0x7f, 0x80, 0xff, 0xff, 0x01, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x01,
   0xff, 0xff, 0x01, 0xfe, 0xff, 0x00, 0xff, 0xff, 0x80, 0xff, 0xff, 0xff,
   0xff, 0xff, 0xff, 0x03, 0xfe, 0xff, 0x01, 0xfe, 0xff, 0x00, 0xfe, 0x7f,
   0xc0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x07, 0xfe, 0xff, 0x00, 0xff,
   0xff, 0x01, 0xfc, 0x7f, 0xe0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x0f,
   0xfc, 0x7f, 0x80, 0xff, 0xff, 0x03, 0xf8, 0x3f, 0xf0, 0xff, 0xff, 0xff,
   0xff, 0xff, 0xff, 0x1f, 0xfc, 0x3f, 0xc0, 0xff, 0xff, 0x07, 0xf0, 0x3f,
   0xf8, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x3f, 0xf8, 0x0f, 0xe0, 0xff,
   0xff, 0x0f, 0xe0, 0x3f, 0xfc, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x3f,
   0xf8, 0x07, 0xf0, 0xff, 0xff, 0x3f, 0x80, 0xff, 0xff, 0xff, 0xff, 0xff,
   0xff, 0xff, 0xff, 0xff, 0xff, 0x01, 0xf8, 0xff, 0xff, 0x7f, 0x00, 0xfe,
   0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0xfe, 0xff,
   0xff, 0xff, 0x01, 0xf8, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
   0x3f, 0x00, 0xff, 0xff, 0xff, 0xff, 0x03, 0xe0, 0xff, 0xff, 0xff, 0xff,
   0xff, 0xff, 0xff, 0xff, 0x0f, 0xc0, 0xff, 0xff, 0xff, 0xff, 0x0f, 0x80,
   0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x01, 0xf0, 0xff, 0xff,
   0xff, 0xff, 0x3f, 0x00, 0xfc, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f,
   0x00, 0xfc, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0xe0, 0xff, 0xff, 0xff,
   0xff, 0xff, 0xff, 0x0f, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x07,
   0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0xc0, 0xff, 0xff, 0xff,
   0xff, 0xff, 0xff, 0x3f, 0x00, 0xe0, 0xff, 0xff, 0xff, 0xff, 0x07, 0x00,
   0xf8, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x01, 0x00, 0xf0, 0xff,
   0xff, 0x1f, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
   0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0xff, 0xff, 0xff, 0xff,
   0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff,
   0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x3f, 0x00, 0x00,
   0x00, 0x00, 0xf8, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
   0xff, 0xff, 0x7f, 0x00, 0x00, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
   0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
   0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
   0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
   0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
   0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
   0xff, 0xff, 0xff, 0xff };  
    void vegetables(byte type)
{
  switch(type)
  {
    case 1: Serial3.write("brinjal");
  u8g2.drawStr(px,py,"brinjal");
  u8g2_draw_unifont_devanagari(0,35,"बैंगन");break;
  case 2: Serial3.write("spinach");
  u8g2.drawStr(px,py,"spinach");
  u8g2_draw_unifont_devanagari(0,35,"पालक");break;
  case 3: Serial3.write("beetroot");
  u8g2.drawStr(px,py,"beet root");
  u8g2_draw_unifont_devanagari(0,35,"चुकंदर");break;
  case 4: Serial3.write("bitter");
  u8g2.drawStr(px,py,"bitterguard");
  u8g2_draw_unifont_devanagari(0,35,"करेला");break;
  case 5: Serial3.write("bottle");
  u8g2.drawStr(px,py,"bottle gourd");
  u8g2_draw_unifont_devanagari(0,35,"लौकी");break;
  case 6: Serial3.write("cabbage");
  u8g2.drawStr(px,py,"cabbage");
  u8g2_draw_unifont_devanagari(0,35,"पत्ता गोभी");break;
  case 7:  Serial3.write("pumpkin");
  u8g2.drawStr(px,py,"pumpkin");
  u8g2_draw_unifont_devanagari(0,35,"कद्दू");break;
  case 8: Serial3.write("carrot");
  u8g2.drawStr(px,py,"carrot");
  u8g2_draw_unifont_devanagari(0,35,"गाजर");break;
  case 9: Serial3.write("chillis");
  u8g2.drawStr(px,py,"chillis");
  u8g2_draw_unifont_devanagari(0,35,"मिर्च");break;
  case 10: Serial3.write("tomato");
  u8g2.drawStr(px,py,"tomato");
  u8g2_draw_unifont_devanagari(0,35,"टमाटर");break;
 
}}
    void rivers(byte type)
{
  switch(type)
  {case 1:  u8g2.drawStr(px,py,"ganga");  break;
    case 2:  u8g2.drawStr(px,py,"yamuna");  break;
    case 3: u8g2.drawStr(px,py,"saraswati");  break;
    case 4:  u8g2.drawStr(px,py,"sarayou"); break;
    case 5:  u8g2.drawStr(px,py,"gandak"); break;
    case 6:  u8g2.drawStr(px,py,"kosi"); break;
    case 7:  u8g2.drawStr(px,py,"sipra"); break;
    case 8:  u8g2.drawStr(px,py,"falgu"); break;
    case 9:  u8g2.drawStr(px,py,"nil"); break;
    case 0:  u8g2.drawStr(px,py,"bharamputra"); break;
  }
}
void u8g2_prepare(void) 
{
  u8g2.setFont(u8g2_font_6x10_tf);
  u8g2.setFontRefHeightExtendedText();
  u8g2.setDrawColor(1);
  u8g2.setFontPosTop();
  u8g2.setFontDirection(0);
}
u8g2_uint_t u8g2_draw_unifont_devanagari(u8g2_uint_t x, u8g2_uint_t y, const char *str)
{
  uint16_t e;
  u8g2_uint_t delta, sum;
  u8g2.getU8g2()->u8x8.next_cb = u8x8_utf8_next;
  u8x8_utf8_init(u8g2.getU8x8());
  sum = 0;
  for(;;)
  {
    e = u8g2.getU8g2()->u8x8.next_cb(u8g2.getU8x8(), (uint8_t)*str);
    if ( e == 0x0ffff )
      break;
    str++;
    if ( e != 0x0fffe )
    {
      switch(e)
      {
 case 0x093e: x-= 12; break;
  case 0x093f: x-= 23; break;
  case 0x0940: x-= 10;  break;
  case 0x0941: x-= 10; y+=3; break;
  case 0x0942: x-=14;y+=3; break;
  case 0x0943: x-=16;y+=3; break;
  case 0x0947: x-= 13;y-=1; break;
  case 0x0948: x-=13;y-=2; break;
  case 0x0949:x-= 10;  break;
  case 0x094b:x-=10;  break;
  case 0x094c:x-=10;  break;
  case 0x094d: x-= 10;y+=2; break;
  case 0x0902:x-= 14;y-=2;break;
      }
      delta = u8g2.drawGlyph(x, y, e);    
      switch(e)
      {
  case 0x093f: x+= 5; break;
  case 0x0941: x-= 6; y -=3; break;
  case 0x094d: x-= 7;y-=2; break;
  case 0x0942: x-=2;y-=3; break;
  case 0x0943: y-=3; break;
  case 0x0947: y+=1; break;
  case 0x0948: x-= 4;y+=2; break;
  case 0x094b:x-=2;  break;
  case 0x094c:x-=2;  break;
  case 0x0902:x-= 2;y+=2;break;
  }
     x += delta;
     sum += delta;    
  }
  }
  return sum;
}
int del_fun = 100;
void setup(void) {
  Serial.begin(9600);
  Serial3.begin(9600);
  for(int i = 0;i<=4;i++)
  {
  pinMode(pinx[i],OUTPUT);
  }
  for(int i = 0;i<=6;i++)
  {
  pinMode(piny[i],INPUT_PULLUP);
  }
  u8g2.begin();
  u8g2.firstPage();  
  do {
  u8g2.drawFrame(1,2,126,62);
     u8g2.drawXBMP( 0, 0, 128, 64, toycathon_logo);
    } while( u8g2.nextPage() );
   delay(4000);
  u8g2.setDrawColor(1);
  u8g2.clearBuffer(); 
   u8g2.setFont(u8g2_font_unifont_t_devanagari);
    u8g2_draw_unifont_devanagari(0,15,"स्वाध्ययन");
     u8g2_draw_unifont_devanagari(0,35,"पुस् तिका में");
  u8g2.sendBuffer();
   delay(2000);
    u8g2.clearBuffer();  
     u8g2_draw_unifont_devanagari(0,15,"आपका");
      u8g2_draw_unifont_devanagari(0,35,"स्वागत है ।");
       u8g2.sendBuffer();
        delay(2000);   
   u8g2.clearBuffer();  
  pinMode(left_butt,INPUT_PULLUP);
  pinMode(right_butt,INPUT_PULLUP);
  pinMode(done_butt,INPUT_PULLUP);
  pinMode(back_butt,INPUT_PULLUP);
  pinMode(home_butt,INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(21),To_Home,LOW);
}
bool game_xx;
void To_Home()
{
 uk = 0;
 uk1 = 0;
 ok = 0; 
 Serial3.write("khjh"); 
del_fun = 0;
game_xx = 0;
//counting(100);
u8g2.clearBuffer();  

}
//***********************************************************************main loop********************************************************************************//
char serial;
bool var9 = 0;
void loop(void) 
{
  if(game_xx == 0)
  {
    menu();
  }
  else
  {
    game_1();
  }
  if(del_fun == 0)
  {
  u8g2.clearBuffer(); 
  }
   del_fun = 100;
if(var9 == 1)
{
if (Serial.available())
{
// Write what is received to the default serial port
serial = (Serial.read());

if(serial == 'A')
{
 u8g2.firstPage();  
  do {
 // u8g2.drawFrame(1,2,126,62);
     u8g2.drawXBMP( 0, 0, 128, 64, congrats);
    } while( u8g2.nextPage() );
    Serial3.write("rig");
   var9 = 0;
} 
else
{
 u8g2.firstPage();  
  do {
 // u8g2.drawFrame(1,2,126,62);
     u8g2.drawXBMP( 0, 0, 128, 64, sad);
    } while( u8g2.nextPage() );
    Serial3.write("wro");
   var9 = 0;
}}}
Serial.print(serial); }
//***********************************************************************main loop********************************************************************************//
void menu()
{
  buttonState1 = digitalRead(left_butt);  
  buttonState2 = digitalRead(done_butt);
  buttonState3 = digitalRead(right_butt); 
  buttonState4 = digitalRead(back_butt); 
  //buttonState5 = digitalRead(tab_butt);
  //////////////////////////////////
  ////////////up////////////////////
   if (buttonState3 != lastButtonState3) 
  { 
    if (buttonState3 == HIGH) 
    {
      if(ok == 0)
      {
      uk++; 
      uk1 = 0;}
      else if(ok == 1)
      {
        uk1++;
      }
      else if(ok == 2&&uk == 7)
      {
        uk2++;
        count1 = 0;
      }
    //  count1 = 0;
      u8g2.clearBuffer(); 
    }
    delay(100);
  }
  lastButtonState3 = buttonState3;
//////////////////////////////////  
  /////////////down///////////////
  if (buttonState1 != lastButtonState1) 
  { 
    if (buttonState1 == HIGH) 
    { 
      if(ok == 0)
      { uk--; 
      uk1 = 0;}
      else if(ok == 1)
      {
        uk1--;
      }
       else if(ok == 2&&uk == 7)
      {
        uk2--;
        count1 = 0;
      }
      u8g2.clearBuffer(); 
  }
    delay(100);
  }
  lastButtonState1 = buttonState1;
  ////////////////////////////////////
  /////////////ok/////////////////////
   if (buttonState2 != lastButtonState2) 
  { 
    if (buttonState2 == HIGH) 
    {
     if(ok<2)
        ok++; 
        else
        ok--;
        //uk = 0;   
       count1 = 0;
      u8g2.clearBuffer(); 
    }
  delay(100);
  }
  lastButtonState2 = buttonState2;
  //////////////////////////////////
  ////////////back//////////////////
   if (buttonState4 != lastButtonState4) 
  { 
    if (buttonState4 == HIGH) 
    {
     
     ok--;
     uk1 = 0;
     if(ok<0)
     {
      ok = 0;
     }
      //count1 = 0;
      u8g2.clearBuffer(); 
    }
    delay(100);
  }
  lastButtonState4 = buttonState4;
  ////////////////////////////////
  ///////////////ok/////////////////
  
if(ok == 0)
  {
     //u8g2.clearBuffer();  
  u8g2.setFont(u8g2_font_unifont_t_devanagari);       
   if(uk == 0)
   {
  u8g2.drawStr(px,py,"Alphabet"); 
  u8g2_draw_unifont_devanagari(2,35,"वर्णमाला");
   }
   else if(uk == 1)
   {
  u8g2.drawStr(px,py,"Poem"); 
  u8g2_draw_unifont_devanagari(5,35,"क बिता");
   }
   else if(uk == 2)
   {
  u8g2.drawStr(px,py,"Story"); 
  u8g2_draw_unifont_devanagari(0,35,"कहानी");
   }
   else if(uk == 3)
   {
  u8g2.drawStr(px,py,"Table"); 
  u8g2_draw_unifont_devanagari(0,35,"पहाड़ा");
   }
    else if(uk == 4)
   {
  u8g2.drawStr(px,py,"Counting"); 
  u8g2_draw_unifont_devanagari(6,35,"गिनती ");
   }
    else if(uk == 5)
   {
  u8g2.drawStr(px,py,"Maths"); 
  u8g2_draw_unifont_devanagari(6,35,"हिसाब ");
   }
    else if(uk == 6)
   {
  u8g2.drawStr(px,py,"Games"); 
  u8g2_draw_unifont_devanagari(0,35,"खेल ");
   }
   else if(uk == 7)
   {
  u8g2.drawStr(px,py,"Name"); 
  u8g2_draw_unifont_devanagari(0,35,"नाम");
   }
   else
   {
    if(uk>=8)
    uk = 0;
    else
    uk = 7;
   }
  // uk = 0;
   u8g2.sendBuffer(); 
}
//////////////////////////////
/////////////////////////////
else if(ok == 1||ok == 2)
  {
     //u8g2.clearBuffer();  
    if(uk == 0)
    {
      if(ok == 1)
      {
    if(uk1 == 0)
   {
 u8g2_draw_unifont_devanagari(6,15,"हिंदी");
 u8g2_draw_unifont_devanagari(2,35,"वर्णमाला");
  u8g2_draw_unifont_devanagari(2,55,"अ,आ,इ,ई");
   }
  else if(uk1 == 1)
  {
 u8g2_draw_unifont_devanagari(5,15,"हिंदी");
 u8g2_draw_unifont_devanagari(2,35,"वर्णमाला");
 u8g2_draw_unifont_devanagari(5,55,"क,ख,ग,घ");
  }
  else if(uk1 == 2)
  {
 u8g2.drawStr(px,py,"English"); 
  u8g2.drawStr(px,py+15,"Alphabet"); 
 u8g2.drawStr(5,55,"A,B,C,D");
  }
  else if(uk1 == 3)
  {
 u8g2.drawStr(px,py,"English"); 
  u8g2.drawStr(px,py+15,"Alphabet"); 
 u8g2.drawStr(5,55,"a,b,c,d");
  }
  else
 {
    if(uk1>=4)
    uk1 = 0;
    else
    uk1 = 3;
   }
      }  
  if(ok == 2)
  {  
    vernmala(uk1);  
  }
  }
   else if(uk == 1)
   {
      if(uk1 == 0)
   {
   u8g2_draw_unifont_devanagari(0,15,"आलू कचालू ");
   }
    else if(uk1 == 1)
   {
   u8g2_draw_unifont_devanagari(0,15,"मछली जल की");
   }
   else if(uk1 == 2)
   {
   u8g2_draw_unifont_devanagari(0,15,"ऊपर पंखा");
   }
   else if(uk1 == 3)
   {
  u8g2_draw_unifont_devanagari(0,15,"हिन्दू मुस्लिम");
   }
   else if(uk1 == 4)
   {
  u8g2_draw_unifont_devanagari(0,15,"गईया मेरी");
   }
   else if(uk1 == 5)
   {
  u8g2_draw_unifont_devanagari(0,15,"twinkle twinkle");
   }
   else
   {
    if(uk1>=6)
    uk1 = 0;
    else
    uk1 = 5;
   }
   if(ok == 2)
   {
    poem(uk1); 
    ok--;
   }}
   else if(uk == 2)
   {
    if(ok == 1)
    {
    if(uk1 == 0)
   {
   u8g2_draw_unifont_devanagari(0,15,"एकता में");
   u8g2_draw_unifont_devanagari(50,35,"शक ्ति");
   }
    else if(uk1 == 1)
   {
   u8g2_draw_unifont_devanagari(0,15,"खरगोश और");
   u8g2_draw_unifont_devanagari(20,35,"कछुआ");
   }
   else if(uk1 == 2)
   {
   u8g2_draw_unifont_devanagari(0,15,"प्यासा कौआ");
   }
   else if(uk1 == 3)
   {
  u8g2_draw_unifont_devanagari(0,15,"शेर और चूहा");
   }
   else if(uk1 == 4)
   {
  u8g2_draw_unifont_devanagari(0,15,"लालची कुत्ता");
   }
   else
   {
    if(uk1>=5)
    uk1 = 0;
    else
    uk1 = 4;
    }}
  else if(ok == 2)
   {
    story(uk1); 
    ok--;
   }}
   else if(uk == 3)
   {
    //table
    vernmala(4);
   }
   else if(uk == 4)
   {
  counting(0);
   }
   else if(uk == 5)
   {
    if(ok == 1)
    {
    if(uk1 == 0)
  {
   u8g2.drawStr(px,py,"Addition"); 
   u8g2_draw_unifont_devanagari(0,35,"जोड़ +");
   //sum1 = 2;
    }
   else if(uk1 == 1)
    {
   u8g2.drawStr(px,py,"Substraction"); 
   u8g2_draw_unifont_devanagari(0,35,"घटाव -");
   //sum1 = 2;
    }
    else
   {
    if(uk1>=2)
    uk1 = 0;
    else
    uk1 = 1;
   }
    }
   else if(ok == 2)
    {
    vernmala(5);
    }
    }
   else if(uk == 6)
   {
    game_xx = 1;
   }
   if(uk == 7)
   {
if(ok == 1)
{
  if(uk1 == 0)
  {
  u8g2.drawStr(px,py,"Animals Name"); 
   u8g2_draw_unifont_devanagari(0,35,"जानवरो के");
   u8g2_draw_unifont_devanagari(0,55,"नाम");
}
else if(uk1 == 1)
{
 u8g2.drawStr(px,py,"Birds Name"); 
   u8g2_draw_unifont_devanagari(0,35,"पच्छीओ  के");
   u8g2_draw_unifont_devanagari(0,55,"नाम"); 
}
else if(uk1 == 2)
{
  u8g2.drawStr(px,py,"Fruits Name"); 
   u8g2_draw_unifont_devanagari(0,35,"फलो के नाम");
}
else if(uk1 == 3)
{
  u8g2.drawStr(px,py,"Flowers Name"); 
   u8g2_draw_unifont_devanagari(0,35,"फूलो के नाम");
}
  else if(uk1 == 4)
{
  u8g2.drawStr(px,py,"Vegetables Name"); 
   u8g2_draw_unifont_devanagari(0,35,"सब् जिओ के");
   u8g2_draw_unifont_devanagari(20,55,"नाम");
} 
// else if(uk1 == 5)
//{
 // u8g2.drawStr(px,py,"Rivers Name"); 
 //  u8g2_draw_unifont_devanagari(0,35,"न दिओं के नाम");
//} 
else
{
  if(uk1>=5)
  uk1 = 0;
  else
  uk1 = 4; 
}}
else if(ok == 2)
{
  if(uk2 >= 11)
    uk2 = 1;
    else if(uk<1)
    uk2 = 10;
 if(uk1 == 0)
 {
  if(count1==0)
  {
  count1= 1;
   animals(uk2);
 }}
else if(uk1 == 1)
{
  if(count1==0)
  {
  count1= 1;
   birds(uk2);
  }}
else if(uk1 == 2)
{
 if(count1==0)
  {
  count1= 1;
   fruits(uk2);
 }}
else if(uk1 == 3)
{
 if(count1==0)
  {
  count1= 1;
 flowers(uk2);
  count1 = 1;
  }
}
else if(uk1 == 4)
{
  if(count1==0)
  {
 vegetables(uk2);
 count1 = 1;
  }
 // u8g2.clearBuffer();
}
else if(uk1 == 5)
{
 u8g2.firstPage();  
  do 
  {
   rivers(uk2);
  } while( u8g2.nextPage() ); 
}
  }}}
u8g2.sendBuffer(); 
}
void poem(int xyz)
{
  switch(xyz)
{
    case 0:
 Serial3.write("poem1"); 
 delay(1000);
 u8g2.clearBuffer();
 u8g2.setFont(u8g2_font_unifont_t_devanagari);
   u8g2_draw_unifont_devanagari(0,15,"आलू कचालू ");
   u8g2_draw_unifont_devanagari(0,35,"बेटा कहां ");
   u8g2_draw_unifont_devanagari(0,55,"गए थे।");
  send_fun(35);
  u8g2_draw_unifont_devanagari(0,15,"बन्दर की");
   u8g2_draw_unifont_devanagari(0,35,"टोकरी में सो ");
   u8g2_draw_unifont_devanagari(0,55,"रहे थे");
  send_fun(35);
u8g2_draw_unifont_devanagari(0,15,"बन्दर ने");
   u8g2_draw_unifont_devanagari(0,35,"लात मारी");
   u8g2_draw_unifont_devanagari(0,55,"रो रहे थे।");
  send_fun(35);
  u8g2_draw_unifont_devanagari(0,15,"मम्मी ने ");
   u8g2_draw_unifont_devanagari(0,35,"प्यार  किया");
   u8g2_draw_unifont_devanagari(0,55,"हस रहे थे।");
  send_fun(35);
  u8g2_draw_unifont_devanagari(0,15,"पापा ने पैसे");
   u8g2_draw_unifont_devanagari(0,35," दिए नाच");
   u8g2_draw_unifont_devanagari(0,55,"रहे थे।");
  send_fun(35);
  u8g2_draw_unifont_devanagari(0,15,"भइआ ने ");
   u8g2_draw_unifont_devanagari(0,35,"लड्डू  दिया");
   u8g2_draw_unifont_devanagari(0,55,"खा रहे थे।");
  send_fun(30);
 break;
  case 1:
 Serial3.write("poem2"); 
 delay(del_fun*10);
 u8g2.clearBuffer();
 /*u8g2.setFont(u8g2_font_unifont_t_devanagari);
 /*  u8g2_draw_unifont_devanagari(0,15,"मछली जल की");
   u8g2_draw_unifont_devanagari(0,35,"रानी है जीवन ");
   u8g2_draw_unifont_devanagari(0,55,"उसका पानी है");
  send_fun(60);
  u8g2_draw_unifont_devanagari(0,15,"हाथ लगाओ");
   u8g2_draw_unifont_devanagari(0,35,"डर जाएगी ");
   u8g2_draw_unifont_devanagari(0,55,"बाहर  निकालो");
 send_fun(45);
  u8g2_draw_unifont_devanagari(0,15,"मर जाएगी");
  send_fun(10);*/
 break;
 case 2:
 Serial3.write("poem3"); 
 break;
  case 3:
 Serial3.write("poem4"); 
 break;
  case 4:
 Serial3.write("poem5"); 
 break;
 case 5:
 Serial3.write("poeme1"); 
 /*u8g2.drawStr(0,15,"Twinkle,twinkle"); 
 u8g2.drawStr(0,30,"little star"); 
 u8g2.drawStr(0,45,"How I wonder"); 
 u8g2.drawStr(0,60,"what you are"); 
 send_fun(67);
 u8g2.drawStr(0,15,"Up above the"); 
 u8g2.drawStr(0,30,"world so high");
 u8g2.drawStr(0,45,"Like a diamond"); 
 u8g2.drawStr(0,60,"in the sky");  
 send_fun(55);*/
 break;
  }
}
void story(int stor)
{
  u8g2.setFont(u8g2_font_unifont_t_devanagari);
  u8g2.clearBuffer();
switch(stor)
{
  case 0:
Serial3.write("story1");
 //delay(1000); 
 break;
 case 1:
Serial3.write("story3"); 
// delay(1000);
  break;
 case 2:
Serial3.write("story3"); 
 //delay(1000);
  break;
   case 3:
Serial3.write("story4"); 
 //delay(1000);
  break;
   case 4:
Serial3.write("story5"); 
// delay(1000);
  break;
 }
 u8g2.sendBuffer();
}
void send_fun(int x)
{
 u8g2.sendBuffer();
 delay(del_fun*x);
 u8g2.clearBuffer();
}
String stringOne, stringTwo, stringThree,stringfour,stringfive;
void table(int tab)
{
  u8g2.clearBuffer();
  int y  = 1;
  int UT = 0;
    for(byte con = 0;con<28;con++)
  {
     if(con<5)
  {
    if(con == 4)
    {
   delay(del_fun*176);
   UT = 0;
   y = 2;
   u8g2.clearBuffer();
    }
  }
  if((con == 8)||(con == 12)||(con == 16)||(con == 20)||(con == 24))
  {
    delay(del_fun*44);
    UT = 0;
    y = 1+ (con/4);
    u8g2.clearBuffer();
  }
  int z = tab*y;
  stringOne = String(tab);
  stringTwo = String(y);
  stringThree = String(z);
  stringfour = String();
  stringfour = stringOne + "X" + stringTwo + " = "+ stringThree;
  char m_str[12];
  stringfour.toCharArray(m_str,12);
  u8g2.drawStr(0,13+UT, m_str); 
  u8g2.sendBuffer();
  y++;
 UT += 17;
  }}
  //int counter;
  ///////////////counting function//////////////////
  ///////////////////////////////
void counting(byte count)
{
  u8g2.setFont(u8g2_font_logisoso62_tn);
  Serial3.write("1to100"); 
  byte i = 0; 
 while(i<=100&&ok!=0)
 {
  i++;
  char m_str2[3];
  strcpy(m_str2, u8x8_u8toa(i, 2)); //u8g2.setFont(u8g2_font_6x10_tf);
  u8g2.firstPage();
  do {
     u8g2.drawStr(0,63, m_str2); 
  } while ( u8g2.nextPage() );
  delay(del_fun*29);
}}
////////////math function////////////
/////////////////////////////////////
void math(byte no_line)
{
//  vernmala(5);
if(sum1>=2)
{
  sum1 = 0;
  u8g2.clearBuffer();  
}
if(uk1 == 0&&sum1 == 0)
{
  sum2 = no_line;
  sum1++;
  for(byte con = 0;con<no_line;con++)
  {
    if(con<=20)
    {
  u8g2.drawBox((con*6)+2,0,4,16);
  u8g2.sendBuffer();
    }
  if(con>20)
  {
  u8g2.drawBox(((con-21)*6)+2,21,4,16);
  u8g2.sendBuffer();
  }
  delay(del_fun);
  }}
  //////////
  else if(uk1 == 0&&sum1 == 1)
  {
    sum1++;
    for(int con = sum2;con<no_line+sum2;con++)
  {
  if(con<=20)
    {
  u8g2.drawBox((con*6)+2,0,4,16);
  u8g2.sendBuffer();
    }
  if(con>20&&con<=41)
  {
  u8g2.drawBox(((con-21)*6)+2,21,4,16);
  u8g2.sendBuffer();
  }
  else if(con>41)
  {
  u8g2.drawBox(((con-42)*6)+2,42,4,16);
  u8g2.sendBuffer();
  }
  delay(del_fun);
  }
  char m_str1[3];
  strcpy(m_str1, u8x8_u8toa(no_line+sum2, 2));  
   u8g2.drawStr(107,60, m_str1); 
  u8g2.sendBuffer();
  }
  ////////////////////////substraction
 else if(uk1 == 1&&sum1 == 0)
{
  sum2 = no_line;
  sum1++;
  for(byte con = 0;con<no_line;con++)
  {
    if(con<=20)
    {
  u8g2.drawBox((con*6)+2,0,4,16);
  u8g2.sendBuffer();
    }
  if(con>20)
  {
  u8g2.drawBox(((con-21)*6)+2,21,4,16);
  u8g2.sendBuffer();
  }
  delay(del_fun);
  }}
  /////////////////
   else if(uk1 == 1&&sum1 == 1)
  {
    sum1++;
    for(int con = sum2;con>sum2-no_line;con--)
  {
  if(con<=21&&con>=0)
    {
  u8g2.drawBox((con*6)-6,6,6,4);
  u8g2.sendBuffer();
    }
  if(con>21)
  {
  u8g2.drawBox(((con-21)*6)-6,27,6,4);
  u8g2.sendBuffer();
  }
  delay(del_fun);
  }
  char m_str1[3];
  strcpy(m_str1, u8x8_u8toa(sum2-no_line, 2));  
   u8g2.drawStr(107,60, m_str1); 
  u8g2.sendBuffer();
  }
}
////////////////////////////////////
////////////////////////////////////
void games()
{
  
}
//*************************//
void vernmala(int kant)
{
  for(int uttu = 0;uttu<=4;uttu++)
  {
    for( int i = 0;i<= 5;i++)
    {  
  Y[i] = digitalRead(piny[i]); 
  delay(2);
    }
    if(Y[0] == HIGH &&Y[1] == HIGH && Y[2] == HIGH && Y[3] == HIGH && Y[4] == HIGH && Y[5] == HIGH)
    {
    for(int i = 0;i<=4;i++)
    {
      digitalWrite(pinx[i],1);
    }
     digitalWrite(pinx[uttu],0);
    }
     else
     {
    if(kant == 1)
      {
        u8g2.clearBuffer();  
    if(Y[0] == 0)
    {
      
     if(uttu == 0)
     {
      Serial3.write("15");
      anga();
     }
     else if(uttu == 1)
     {
      Serial3.write("11");
      ka();
     }
     else if(uttu == 2)
     {
      Serial3.write("12");
      kha();
     }
     else if(uttu == 3)
     {
      Serial3.write("13");
      gaa();
     }
     else if(uttu == 4)
     {
      Serial3.write("14");
      gha();
     }
    }
//////////////////////////////
    else if(Y[1] == 0)
    {
     if(uttu == 0)
     {
      Serial3.write("20");
      yn();
     }
     else if(uttu == 1)
     {
      Serial3.write("16");
      cha();
     }
     else if(uttu == 2)
     {
      Serial3.write("17");
      chha();
     }
     else if(uttu == 3)
     {
      Serial3.write("18");
      jaa();
     }
     else if(uttu == 4)
     {
      Serial3.write("19");
      jha();
     }
    }
   //////////////////////////////
    else if(Y[2] == 0)
    {
     if(uttu == 0)
     {
      Serial3.write("25");
      ada();
     }
     else if(uttu == 1)
     {
      Serial3.write("21");
      taa();
     }
     else if(uttu == 2)
     {
      Serial3.write("22");
      tha();
     }
     else if(uttu == 3)
     {
      Serial3.write("23");
      da();
     }
     else if(uttu == 4)
     {
      Serial3.write("24");
      dha();
     }
    }
     //////////////////////////////
    else if(Y[3] == 0)
    {
     if(uttu == 0)
     {
      Serial3.write("30");
      na();
     }
     else if(uttu == 1)
     {
      Serial3.write("26");
      ta();
     }
     else if(uttu == 2)
     {
      Serial3.write("27");
      thha();
     }
     else if(uttu == 3)
     {
      Serial3.write("28");
      daa();
     }
     else if(uttu == 4)
     {
      Serial3.write("29");
      dhaa();
     }
    }
    //////////////////////////////
    else if(Y[4] == 0)
    {
     if(uttu == 0)
     {
      Serial3.write("35");
      ma();
     }
     else if(uttu == 1)
     {
      Serial3.write("31");
      pa();
     }
     else if(uttu == 2)
     {
      Serial3.write("32");
      fa();
     }
     else if(uttu == 3)
     {
      Serial3.write("33");
      ba();
     }
     else if(uttu == 4)
     {
      Serial3.write("34");
      bha();
     }
    }
    /////////////////////////////////
    /////////////////////////////////
    else if(Y[5] == 0)
    {
     if(uttu == 0)
     {
      Serial3.write("44");
      uo();
     }
     else if(uttu == 1)
     {
      Serial3.write("55");
     aa();
     }
     else if(uttu == 2)
     {
     Serial3.write("56");
     aaa();
     }
     else if(uttu == 3)
     {
      Serial3.write("57");
      ee();
     }
     else if(uttu == 4)
     {
      Serial3.write("58");
     eee();
     }
    }}
    //////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////
    else if(kant == 0) 
    {
      u8g2.clearBuffer();  
     if(Y[0] == 0)
    {
     if(uttu == 0)
     {
      Serial3.write("55");
      uo();
     }
     else if(uttu == 1)
     {
     Serial3.write("51");
     aa();
     }
     else if(uttu == 2)
     {
     Serial3.write("52");
     aaa();
     }
     else if(uttu == 3)
     {
     Serial3.write("53");
      ee();
     }
     else if(uttu == 4)
     {
     Serial3.write("54");
     eee();
     }
    }
    //////////////////////////////
    else if(Y[1] == 0)
    {
     if(uttu == 0)
     {
      Serial3.write("59");
    ooo();
     }
     else if(uttu == 1)
     {
     Serial3.write("56");
    uoo();
     }
     else if(uttu == 2)
     {
     Serial3.write("37");
     ree();
     }
     else if(uttu == 3)
     {
    Serial3.write("57");
     aae();
     }
     else if(uttu == 4)
     {
     Serial3.write("58");
    aai();
     }
    }
    //////////////////////////////
    else if(Y[2] == 0)
    {
     if(uttu == 0)
     {
    Serial3.write("38");
      adha();
     }
     else if(uttu == 1)
     {
      Serial3.write("60");
     auo();
     }
     else if(uttu == 2)
     {
      Serial3.write("61");
    aan();
     }
     else if(uttu == 3)
     {
     Serial3.write("62");
      aah();
     }
     else if(uttu == 4)
     {
      Serial3.write("39");
      adda();
     }
    }
//////////////////////////////
    else if(Y[3] == 0)
    {
     if(uttu == 0)
     {
      Serial3.write("44");
      sha();
     }
     else if(uttu == 1)
     {
      Serial3.write("41");
      ya();
     }
     else if(uttu == 2)
     {
      Serial3.write("42");
      ra();
     }
     else if(uttu == 3)
     {
      Serial3.write("43");
      la();
     }
     else if(uttu == 4)
     {
      Serial3.write("44");
      va();
     }
    }
    ///////////////////////////////
    else if(Y[4] == 0)
    {
     if(uttu == 0)
     {
    Serial3.write("49");
      tra();
     }
     else if(uttu == 1)
     {
      Serial3.write("45");
      shaa();
     }
     else if(uttu == 2)
     {
     Serial3.write("46");
      sa();
     }
     else if(uttu == 3)
     {
      Serial3.write("47");
      ha();
     }
     else if(uttu == 4)
     {
      Serial3.write("48");
      ksha();
     }
    }
//////////////////////////////
    else if(Y[5] == 0)
    {
     if(uttu == 0)
     {
     Serial3.write("cd");
     
     }
     else if(uttu == 1)
     {
     Serial3.write("50");
      gya();
     }
     else if(uttu == 2)
     {
      Serial3.write("37");
      shara();
     }
     else if(uttu == 3)
     {
      Serial3.write("cb");
   
     }
     else if(uttu == 4)
     {
    Serial3.write("38");
      adda();
     }
    }}
///english vernmala////capital letter ///////////////////////
/////////////////////////////////////////////////////////////
   else if(kant == 2)  
   {
     u8g2.clearBuffer();  
     if(Y[0] == 0)
    {
      
     if(uttu == 0)
     {
      Serial3.write("be");
      E();
     }
     else if(uttu == 1)
     {
      Serial3.write("ba");
      serial = '\n';
      A();
      var9 = 1;

     }
     else if(uttu == 2)
     {
      Serial3.write("bb");
      B();
     }
     else if(uttu == 3)
     {
     Serial3.write("bc");
      C();
     }
     else if(uttu == 4)
     {
      Serial3.write("bd");
      D();
     }
    }
//////////////////////////////
    else if(Y[1] == 0)
    {
     if(uttu == 0)
     {
      Serial3.write("bj");
      J();
     }
     else if(uttu == 1)
     {
      Serial3.write("bf");
      F1();
     }
     else if(uttu == 2)
     {
     Serial3.write("bg");
      G();
     }
     else if(uttu == 3)
     {
      Serial3.write("bh");
      H();
     }
     else if(uttu == 4)
     {
      Serial3.write("bi");
      I();
     }
    }
//////////////////////////////
    else if(Y[2] == 0)
    {
     if(uttu == 0)
     {
      Serial3.write("bo");
      O();
     }
     else if(uttu == 1)
     {
      Serial3.write("bk");
      K();
     }
     else if(uttu == 2)
     {
      Serial3.write("bl");
      L();
     }
     else if(uttu == 3)
     {
      Serial3.write("bm");
      M();
     }
     else if(uttu == 4)
     {
      Serial3.write("bn");
      N();
     }
    }
//////////////////////////////
    else if(Y[3] == 0)
    {
     if(uttu == 0)
     {
      Serial3.write("bt");
      T();
     }
     else if(uttu == 1)
     {
      Serial3.write("bp");
      P();
     }
     else if(uttu == 2)
     {
      Serial3.write("bq");
      Q();
     }
     else if(uttu == 3)
     {
      Serial3.write("br");
      R();
     }
     else if(uttu == 4)
     {
      Serial3.write("bs");
      S();
     }
    }
//////////////////////////////
    else if(Y[4] == 0)
    { 
     if(uttu == 0)
     {
      Serial3.write("by");
      Y1();
     }
     else if(uttu == 1)
     {
      Serial3.write("bu");
      U();
     }
     else if(uttu == 2)
     {
      Serial3.write("bv");
      V();
     }
     else if(uttu == 3)
     {
      Serial3.write("bw");
      W();
     }
     else if(uttu == 4)
     {
      Serial3.write("bx");
      X1();
     }
    }
//////////////////////////////
    else if(Y[5] == 0)
    {
     if(uttu == 0)
     {
     // Serial3.write("cd");
      //sha();
     }
     else if(uttu == 1)
     {
      Serial3.write("bz");
      Z();
     }
     else if(uttu == 2)
     {
    //  Serial3.write("ca");
    //  ra();
     }
     else if(uttu == 3)
     {
    //  Serial3.write("cb");
     // la();
     }
     else if(uttu == 4)
     {
     // Serial3.write("cc");
     // va();
     }}}
 //////small letter///////
 ////////////////////////
     else if(kant == 3)  
   {
     u8g2.clearBuffer();  
     if(Y[0] == 0)
    {
      
     if(uttu == 0)
     {
      Serial3.write("be");
      e();
     }
     else if(uttu == 1)
     {
      Serial3.write("ba");
      a();
     }
     else if(uttu == 2)
     {
      Serial3.write("bb");
      b();
     }
     else if(uttu == 3)
     {
     Serial3.write("bc");
      c();
     }
     else if(uttu == 4)
     {
      Serial3.write("bd");
      dd();
     }
    }
/////////////////////////
    else if(Y[1] == 0)
    {
     if(uttu == 0)
     {
      Serial3.write("bj");
      j();
     }
     else if(uttu == 1)
     {
      Serial3.write("bf");
      f();
     }
     else if(uttu == 2)
     {
     Serial3.write("bg");
      g();
     }
     else if(uttu == 3)
     {
      Serial3.write("bh");
      h();
     }
     else if(uttu == 4)
     {
      Serial3.write("bi");
      i();
     }
    }
///////////////////////////
    else if(Y[2] == 0)
    {
     if(uttu == 0)
     {
      Serial3.write("bo");
      oo();
     }
     else if(uttu == 1)
     {
      Serial3.write("bk");
      k();
     }
     else if(uttu == 2)
     {
      Serial3.write("bl");
      ll();
     }
     else if(uttu == 3)
     {
      Serial3.write("bm");
      mm();
     }
     else if(uttu == 4)
     {
      Serial3.write("bn");
      nn();
     }
    }
//////////////////////////////
    else if(Y[3] == 0)
    {
     if(uttu == 0)
     {
      Serial3.write("bt");
      t();
     }
     else if(uttu == 1)
     {
      Serial3.write("bp");
      pp();
     }
     else if(uttu == 2)
     {
      Serial3.write("bq");
      qq();
     }
     else if(uttu == 3)
     {
      Serial3.write("br");
      r();
     }
     else if(uttu == 4)
     {
      Serial3.write("bs");
      s();
     }
    }
//////////////////////////////
    else if(Y[4] == 0)
    { 
     if(uttu == 0)
     {
      Serial3.write("by");
      y();
     }
     else if(uttu == 1)
     {
      Serial3.write("bu");
      u();
     }
     else if(uttu == 2)
     {
      Serial3.write("bv");
      v();
     }
     else if(uttu == 3)
     {
      Serial3.write("bw");
      w();
     }
     else if(uttu == 4)
     {
      Serial3.write("bx");
      x();
     }
    }
//////////////////////////////
    else if(Y[5] == 0)
    {
     if(uttu == 0)
     {
     // Serial3.write("cd");
      //sha();
     }
     else if(uttu == 1)
     { Serial3.write("bz");
      z();
     }
     else if(uttu == 2)
     {
    //  Serial3.write("ca");
    //  ra();
     }
     else if(uttu == 3)
     {
    //  Serial3.write("cb");
     // la();
     }
     else if(uttu == 4)
     {
     // Serial3.write("cc");
     // va();
     }}}
     /////////////////////table start///////////////////////////
     ///////////////////////////////////////////////////////////
     else if(kant == 4) 
    {
      u8g2.clearBuffer();  
     if(Y[0] == 0)
    {
     if(uttu == 0)
     {
      Serial3.write("tab5");
      table(5);
     }
     else if(uttu == 1)
     {
      Serial3.write("tab1");
      table(1);
     }
     else if(uttu == 2)
     {
      Serial3.write("tab2");
     table(2);
     }
     else if(uttu == 3)
     {
     Serial3.write("tab3");
     table(3);
     }
     else if(uttu == 4)
     {
      Serial3.write("tab4");
      table(4);
     }
    }
//////////////////////////////
    else if(Y[1] == 0)
    {
     if(uttu == 0)
     {
      Serial3.write("tab10");
      table(10);
     }
     else if(uttu == 1)
     {
      Serial3.write("tab6");
      table(6);
     }
     else if(uttu == 2)
     {
     Serial3.write("tab7");
      table(7);
     }
     else if(uttu == 3)
     {
      Serial3.write("tab8");
      table(8);
     }
     else if(uttu == 4)
     {
      Serial3.write("tab9");
      table(9);
     }
    }
//////////////////////////////
    else if(Y[2] == 0)
    {
     if(uttu == 0)
     {
      Serial3.write("tab15");
      table(15);
     }
     else if(uttu == 1)
     {
      Serial3.write("tab11");
     table(11);
     }
     else if(uttu == 2)
     {
      Serial3.write("tab12");
     table(12);
     }
     else if(uttu == 3)
     {
      Serial3.write("tab13");
     table(13);
     }
     else if(uttu == 4)
     {
      Serial3.write("tab14");
     table(14);
     }
    }
//////////////////////////////
    else if(Y[3] == 0)
    {
     if(uttu == 0)
     {
      Serial3.write("tab20");
    table(20);
     }
     else if(uttu == 1)
     {
     Serial3.write("tab16");
    table(16);
     }
     else if(uttu == 2)
     {
     Serial3.write("tab17");
     table(17);
     }
     else if(uttu == 3)
     {
     Serial3.write("tab18");
     table(18);
     }
     else if(uttu == 4)
     {
     Serial3.write("tab19");
     table(19);
     }
    }
//////////////////////////////
    else if(Y[4] == 0)
    {
     if(uttu == 0)
     {
      Serial3.write("tab25");
      table(25);
     }
     else if(uttu == 1)
     {
      Serial3.write("tab21");
     table(21);
     }
     else if(uttu == 2)
     {
      Serial3.write("tab22");
     table(22);
     }
     else if(uttu == 3)
     {
      Serial3.write("tab23");
      table(23);
     }
     else if(uttu == 4)
     {
      Serial3.write("tab24");
     table(24);
     }
    }
//////////////////////////////
    else if(Y[5] == 0)
    {
     if(uttu == 0)
     {
      Serial3.write("tab30");
      table(30);
     }
     else if(uttu == 1)
     {
      Serial3.write("tab26");
      table(26);
     }
     else if(uttu == 2)
     {
      Serial3.write("tab27");
      table(27);
     }
     else if(uttu == 3)
     {
      Serial3.write("tab28");
     table(28);
     }
     else if(uttu == 4)
     {
      Serial3.write("tab29");
      table(29);
   }}}
   ///////////////math start////////////////////
   /////////////////////////////////////////////
    else if(kant == 5) 
    {
      //u8g2.clearBuffer();  
     if(Y[0] == 0)
    {
     if(uttu == 0)
     {
      Serial3.write("n5");
      math(5);
     }
     else if(uttu == 1)
     {
      Serial3.write("n1");
      math(1);
     }
     else if(uttu == 2)
     {
      Serial3.write("n2");
     math(2);
     }
     else if(uttu == 3)
     {
     Serial3.write("n3");
     math(3);
     }
     else if(uttu == 4)
     {
      Serial3.write("n4");
      math(4);
     }
    }
//////////////////////////////
    else if(Y[1] == 0)
    {
     if(uttu == 0)
     {
      Serial3.write("n10");
      math(10);
     }
     else if(uttu == 1)
     {
      Serial3.write("n6");
      math(6);
     }
     else if(uttu == 2)
     {
     Serial3.write("n7");
      math(7);
     }
     else if(uttu == 3)
     {
      Serial3.write("n8");
      math(8);
     }
     else if(uttu == 4)
     {
      Serial3.write("n9");
     math(9);
     }
    }
//////////////////////////////
    else if(Y[2] == 0)
    {
     if(uttu == 0)
     {
      Serial3.write("n15");
      math(15);
     }
     else if(uttu == 1)
     {
      Serial3.write("n11");
    math(11);
     }
     else if(uttu == 2)
     {
      Serial3.write("n12");
    math(12);
     }
     else if(uttu == 3)
     {
      Serial3.write("n13");
     math(13);
     }
     else if(uttu == 4)
     {
      Serial3.write("n14");
     math(14);
     }
    }
//////////////////////////////
    else if(Y[3] == 0)
    {
     if(uttu == 0)
     {
     Serial3.write("n20");
    math(20);
     }
     else if(uttu == 1)
     {
     Serial3.write("n16");
    math(16);
     }
     else if(uttu == 2)
     {
     Serial3.write("n17");
    math(17);
     }
     else if(uttu == 3)
     {
     Serial3.write("n18");
     math(18);
     }
     else if(uttu == 4)
     {
     Serial3.write("n19");
     math(19);
     }
    }
//////////////////////////////
    else if(Y[4] == 0)
    {
     if(uttu == 0)
     {
      Serial3.write("n25");
     math(25);
     }
     else if(uttu == 1)
     {
      Serial3.write("n21");
     math(21);
     }
     else if(uttu == 2)
     {
      Serial3.write("n22");
     math(22);
     }
     else if(uttu == 3)
     {
      Serial3.write("n23");
      math(23);
     }
     else if(uttu == 4)
     {
      Serial3.write("n24");
     math(24);
     }
    }
//////////////////////////////
    else if(Y[5] == 0)
    {
     if(uttu == 0)
     {
      Serial3.write("n30");
      math(30);
     }
     else if(uttu == 1)
     {
      Serial3.write("n26");
      math(26);
     }
     else if(uttu == 2)
     {
      Serial3.write("n27");
     math(27);
     }
     else if(uttu == 3)
     {
      Serial3.write("n28");
     math(28);
     }
     else if(uttu == 4)
     {
      Serial3.write("n29");
     math(29);
   }}}}}}
 //*********************************vernmala end//

 
     void hori(int l,int m,int n)
{
  for(uint8_t a = 0;a<l ;a++)
   {
    u8g2.drawLine(m+a, n, m+a, n+3);
    delay(d);
    u8g2.sendBuffer();
    }}
//////////////////////
void vrt(int o,int p,int q)
{
  for(uint8_t a = 0;a<o;a++)
  {
    u8g2.drawLine(p, q+a, p+3, q+a);
    delay(d);
    u8g2.sendBuffer();
  }
}
void vrt1(int o1,int p1,int q1)
{
for(uint8_t a = 0;a<o1;a++)
 {
  u8g2.drawLine(p1, q1-a, p1+3, q1-a);
  delay(d);
   u8g2.sendBuffer();
}}
///////////////////////
void hori1(int l1,int m1,int n1)
  {
 for(uint8_t a = 0;a<l1 ;a++)
 {
  u8g2.drawLine(m1-a, n1, m1-a, n1+3);
  delay(d);
   u8g2.sendBuffer();
}}
/////////////////////
void cross(int len2,int sx,int ey,int din)
{
  if(din == 0)
  {
 for(uint8_t a = 0;a<=len2;a++)
      {
        u8g2.drawLine(sx-a, ey+a, sx+3-a, ey+a);
  delay(d);
   u8g2.sendBuffer();
      }}
      else
      {
      for(uint8_t a = 0;a<=len2;a++)
      {
        u8g2.drawLine(sx+a, ey+a, sx+3+a, ey+a);
  delay(d);
   u8g2.sendBuffer();
      }}}
 /////////////////////////
       void cross1(int len2,int sx,int ey,int din)
{
  if(din == 0)
  {
 for(uint8_t a = 0;a<=len2;a++)
      {
        u8g2.drawLine(sx-a/2, ey+a, sx+3-a/2, ey+a);
  delay(d);
   u8g2.sendBuffer();
      }}
      else
      {
      for(uint8_t a = 0;a<=len2;a++)
      {
        u8g2.drawLine(sx+a/2, ey+a, sx+3+a/2, ey+a);
  delay(d);
   u8g2.sendBuffer();
      }}}
////////////////////
void circle(int len,int x,int y,int st,int en,int dir)
{
  if(st<=2)
  {
    x0 = x;
     y0 = y-4;
  }
  else if(st>4&&st<=6)
  {
   x0 = x;
     y0 = y+4;
  }
  else if(st>2&&st<=4)
  {
    if(dir == 0){x0 = x-4;}
   else{x0 = x+4;}
     y0 = y; 
  }
  else
  {
    if(dir == 0){x0 = x+2;}
    else{x0 = x-4;}
     y0 = y; 
  }
  if(dir == 0)
  {
  for(circum = st;circum<=en;circum++)
  {
     
    switch(circum)
    {
      case 1:
      for(uint8_t a = 0;a<=len;a++)
      {
        u8g2.drawLine(x-a, y-1, x0-a, y0);
  delay(d);
   u8g2.sendBuffer();
      }
      x0 = x-len;
      x = x-len;
    break;
    case 2:
    for(uint8_t a = 0;a<=len;a++)
      {
   u8g2.drawLine(x-a, y+a, x0-a, y0+a);
  delay(d);
   u8g2.sendBuffer();
      }
      x0 = x0-len;
      x = x-len+4;
      y = y0+len;
      y0 = y0 + len;
      break;
      case 3:
    for(uint8_t a = 0;a<=len;a++)
      {
        u8g2.drawLine(x-1, y+a, x0, y0+a);
  delay(d);
   u8g2.sendBuffer();
      }
      y = y+len;
      y0 = y0 + len;
      break;
   case 4:
      for(uint8_t a = 0;a<=len;a++)
      {
        u8g2.drawLine(x+a, y+a, x0+a, y0+a);
  delay(d);
   u8g2.sendBuffer();
      }
      y = y+len-4;
      y0 = y0 + len;
      x0 = x0+len;
      x = x0;
        break;
    case 5:
    {
      for(uint8_t a = 0;a<=len;a++)
      {
        u8g2.drawLine(x+a, y+1, x0+a, y0);
  delay(d);
   u8g2.sendBuffer();
      }
      x0 = x0+len;
      x = x+len;
      y0 = y+4; 
        break; 
    }
     case 6:
    {
      for(uint8_t a = 0;a<=len;a++)
      {
        u8g2.drawLine(x+a, y-a, x0+a, y0-a);
  delay(d);
   u8g2.sendBuffer();
      }
      y = y-len+4;
      y0 = y; 
      x = x+len;
      x0 = x-4;
     
        break; 
    }
     case 7:
    {
      for(uint8_t a = 0;a<=len;a++)
      {
        u8g2.drawLine(x, y-a, x0+1, y0-a);
  delay(d);
   u8g2.sendBuffer();
      }
      y = y-len;
      y0 = y0-len;
        break; 
    }
    case 8:
    {
      for(uint8_t a = 0;a<=len;a++)
      {
        u8g2.drawLine(x-a, y-a, x0-a, y0-a);
  delay(d);
   u8g2.sendBuffer();
      }
        break; 
    }
  }
}}
else
{
 for(circum = st;circum<=en;circum++)
  {   
    switch(circum)
    {
      case 1:
      for(uint8_t a = 0;a<=len;a++)
      {
        u8g2.drawLine(x+a, y-1, x0+a, y0);
  delay(d);
   u8g2.sendBuffer();
      }
      x0 = x+len;
      x = x+len;
    break;
    case 2:
    for(uint8_t a = 0;a<=len;a++)
      {
        u8g2.drawLine(x+a, y+a, x0+a, y0+a);
  delay(d);
   u8g2.sendBuffer();
      }
      x0 = x0+len;
      x = x+len-4;
      y = y0+len;
      y0 = y0 + len;
      break;
      case 3:
    for(uint8_t a = 0;a<=len;a++)
      {
        u8g2.drawLine(x+1, y+a, x0, y0+a);
  delay(d);
   u8g2.sendBuffer();
      }
      y = y+len;
      y0 = y0 + len;
      break;
       case 4:
      for(uint8_t a = 0;a<=len;a++)
      {
        u8g2.drawLine(x-a, y+a, x0-a, y0+a);
  delay(d);
   u8g2.sendBuffer();
      }
      y = y+len-4;
      y0 = y0 + len;
      x0 = x0-len;
      x = x0;
        break;
    
    case 5:
    {
      for(uint8_t a = 0;a<=len;a++)
      {
        u8g2.drawLine(x-a, y+1, x0-a, y0);
  delay(d);
   u8g2.sendBuffer();
      }
      x0 = x0-len;
      x = x-len;
      y0 = y+4; 
        break; 
    }
     case 6:
    {
      for(uint8_t a = 0;a<=len;a++)
      {
        u8g2.drawLine(x-a, y-a, x0-a, y0-a);
  delay(d);
   u8g2.sendBuffer();
      }
      y = y-len+4;
      y0 = y; 
      x = x-len;
      x0 = x+4;
     
        break; 
    }
     case 7:
    {
      for(uint8_t a = 0;a<=len;a++)
      {
        u8g2.drawLine(x, y-a, x0-1, y0-a);
  delay(d);
   u8g2.sendBuffer();
      }
      y = y-len;
      y0 = y0-len;
        break; 
    }
    case 8:
    {
      for(uint8_t a = 0;a<=len;a++)
    {
        u8g2.drawLine(x+a, y-a, x0+a, y0-a);
  delay(d);
   u8g2.sendBuffer();
    }
     break;  
     }
}
} 
}
delay(d1);
}
//////////////hindi venmala///////////////////
///////////////////////////////////////////////
  void ka()
  {
  hori(68,30,0);
  vrt(50,64,3);
  circle(10,57,10,1,6,0);
  circle(9,68,23,8,8,1);
  circle(9,74,18,1,4,1);
  }
  void kha()
  {
  hori(68,30,0);
  vrt(50,77,3);
  circle(9,38,6,1,5,1);
  circle(14,38,23,3,6,0);
  circle(8,77,12,1,5,0);
  }
 void gaa()
  {
  //u8g2.clearBuffer();
  hori(68,30,0);
  vrt(50,77,3);
  vrt(30,64,3);
  circle(7,63,33,4,8,1);
  } 
  void gha()
  {
  hori(68,30,0);
  circle(9,47,4,2,5,0);
  circle(11,47,27,2,6,0);
  vrt(50,69,3); 
  }
  void anga()
  {
  hori(68,30,0);
  vrt(7,64,3);
  circle(9,64,10,1,5,0);
  circle(9,64,34,2,6,1);
  u8g2.drawDisc(79,43,2); 
  }
  void cha()
  {
  hori(68,30,0);
   hori(25,33,12);
  circle(11,54,16,2,6,0);
  vrt(50,77,3);    
  }
 void chha()
  {
   hori(68,30,0);
  circle(9,55,4,2,5,0);
  circle(12,58,28,2,4,0);
  circle(15,59,56,5,7,0);
   circle(5,85,29,8,8,0);
   circle(5,81,27,2,5,0);  
  // vrt(21,81,3);   
  }
  void jaa()
  {
   hori(68,30,0);
  circle(12,50,12,2,7,0);
  hori(10,75,20);
  vrt(50,85,3);      
  }
  void jha()
  {
   hori(68,30,0);
  circle(8,58,7,1,5,0);
  circle(8,58,28,2,6,1);
   vrt(12,42,38);  
  hori(17,68,28);
  vrt(50,82,3);      
  }
  void yn()
  {
   hori(68,30,0);
  circle(12,40,15,1,6,1); 
  hori(16,65,27);
  vrt(50,81,3);      
  }
  void taa()
{
  hori(68,30,0);
  vrt(10,64,3);
  circle(15,67,13,1,5,0);
  circle(10,68,54,8,8,1); 
}

void tha()
{
  hori(68,30,0);
  vrt(15,62,3);
  circle(15,72,20,1,8,0); 
}
void da()
{
  hori(68,30,0);
  vrt(7,64,3);
  circle(9,64,10,1,5,0);
  circle(9,64,34,2,6,1); 
}
void dha()
{
  hori(68,30,0);
  vrt(10,64,3);
  circle(15,67,17,1,5,0);
  circle(5,68,54,6,8,0);
  circle(5,68,47,1,5,0);
}
void ada()
{
  hori(68,30,0);
  vrt(20,45,3);
  circle(8,49,23,3,7,0);
  circle(19,66,22,7,7,0);
  //vrt(20,66,3);
  vrt(50,80,3); 
}
void ta()
{
  hori(68,30,0);
  vrt(50,85,3);
  circle(25,85,20,1,1,0);
  circle(12,59,20,2,4,0);
}
void thha()
{
  hori(68,30,0);
  circle(5,50,5,1,8,1);
  circle(10,55,16,2,2,0);
  circle(14,49,25,4,6,0);
  vrt(50,85,3);
}

  void daa()
{
  hori(68,30,0);
  vrt(10,64,3);
  circle(15,67,17,1,5,0);
  circle(5,68,54,6,8,0);
  circle(5,68,47,1,5,0);
  circle(5,66,59,4,4,0);
}
  void dhaa()
{
  hori(31,30,0);
  circle(5,53,4,2,6,1);
  circle(10,49,4,2,5,0);
  circle(10,48,30,2,6,0);
  vrt(55,69,3);
  hori(20,65,0);
}
  void na()
{
  hori(68,30,0);
  vrt(50,85,3);
  circle(35,85,20,1,1,0);
  circle(5,50,20,2,8,0);
}
  void pa()
{
  hori(68,30,0);
  circle(14,52,4,3,5,0);
  circle(8,77,28,6,6,0);
  vrt(50,82,3);
}
  void fa()
{
  hori(68,30,0);
  vrt(50,66,3);
  circle(13,40,4,3,6,0);
  circle(4,75,17,8,8,1);
  circle(10,76,17,1,4,1); 
}
void ba()
{
  hori(68,30,0);
  vrt(50,80,3);
  circle(10,79,22,8,8,0);
  circle(11,71,16,1,6,0);
  circle(18,59,19,4,4,0);
}
 void bha ()
{
  circle(5,46,15,6,8,1);
  circle(5,46,8,1,2,1);
  vrt(31,53,10);
  circle(10,56,40,6,6,1);
  hori(33,47,30);
  vrt(50,80,3);
  hori(25,70,0);
}
  void ma()
{
  hori(68,30,0);
  vrt(37,53,3);
  circle(10,56,40,6,6,1);
  hori(33,47,30);
  vrt(50,80,3);
}
//////////////////////////////////
/////////////////////////////////

  void ya()
{
  hori(68,30,0);
  circle(8,42,5,1,4,1);
  circle(14,49,25,4,6,0);
  vrt(50,84,3);
}
  void ra()
{
  hori(68,30,0);
  circle(10,55,5,1,4,1);
  circle(20,65,31,4,4,0);
}
  void la()
{
  hori(68,30,0);
  vrt(50,80,3);
  circle(13,80,20,2,2,0);
  circle(11,66,30,8,8,0);
  circle(11,59,23,1,4,0);
}
  void va()
{
  hori(68,30,0);
  vrt(50,80,3);
  circle(10,79,22,8,8,0);
  circle(11,71,16,1,6,0);
}
  void sha()
{
  hori(68,30,0);
  circle(5,52,10,4,8,1);
  circle(10,40,5,1,4,1);
  circle(20,50,31,4,4,0);
  vrt(48,80,3);
}
  void shaa()
{
  hori(68,30,0);
  circle(14,52,4,3,5,0);
  circle(8,77,28,6,6,0);
  vrt(50,82,3);
  circle(24,56,4,4,4,0);
}
void sa()
{
  hori(68,30,0);
  circle(10,40,5,1,4,1);
  circle(20,50,31,4,4,0);
  vrt(48,80,3);
  hori(30,50,28);
}
void ha()
{
  hori(68,30,0);
  vrt(7,64,3);
  circle(8,64,10,1,5,0);
  circle(5,65,31,1,4,1);
  circle(11,58,31,2,4,0); 
}
void ksha()
{
  hori(68,30,0);
  vrt(50,80,3);
  circle(30,80,25,1,1,0);
  circle(5,50,20,6,8,1);
  circle(7,50,13,1,4,1);
  circle(9,56,31,2,5,0);
  circle(4,66,50,6,8,0);
  circle(5,67,46,1,4,0);  
}
void tra()
{
  hori(68,30,0);
  vrt(50,80,3);
  circle(10,78,25,8,8,0);
  circle(13,70,19,1,1,0);
  circle(18,79,25,4,4,1);
}
void gya()
{
  hori(68,30,0);
  vrt(50,80,3);
  circle(20,80,25,1,1,0);
  circle(10,59,25,2,5,1);
  circle(5,48,47,6,8,1);
  circle(4,48,40,1,3,1);
  vrt(10,53,45);
}
////////////////////////
///////////////////////

void aa()
  {
   hori(65,30,0);
  circle(9,40,8,1,5,1); 
  circle(10,47,32,2,6,1); 
  hori(20,55,35);
  vrt(55,75,3);      
  }
  void aaa()
  {
   hori(65,30,0);
  circle(9,40,8,1,5,1); 
  circle(10,47,32,2,6,1); 
  hori(20,55,35);
  vrt(55,75,3); 
  vrt(55,82,3);      
  }
  void ee()
{
  hori(68,30,0);
  vrt(7,64,3);
  circle(9,64,10,1,5,0);
  circle(9,64,34,2,6,1);
  circle(6,47,48,1,4,1);
}
void eee()
{
  hori(68,30,10);
  vrt(7,64,13);
  circle(7,64,20,1,5,0);
  circle(7,64,38,2,6,1);
  circle(6,50,47,1,4,1); 
  circle(5,64,4,1,3,0); 
}
void uo()
{
   hori(65,30,0);
  circle(9,50,8,1,5,1); 
  circle(10,57,32,2,6,1); 
}
void uoo()
{
  hori(65,30,0);
  circle(9,50,8,1,5,1); 
  circle(10,57,32,2,6,1); 
  circle(6,68,38,1,3,1); 
}
  void aae()
  {
   hori(65,27,9);
   vrt(20,40,12);
 cross(30,40,32,1);
  vrt(26,67,12);   
  }
  void aai()
  {
   hori(65,27,9);
   vrt(20,40,12);
 cross(30,40,32,1);
  vrt(26,67,12);
  cross(8,50,0,1);
  }
  void ooo()
  {
  hori(65,30,9);
  circle(8,40,18,1,5,1); 
  circle(9,46,39,2,6,1); 
  hori(16,55,38);
  vrt(50,70,12); 
  vrt(50,78,12); 
  cross(8,50,0,1);    
  }
  void auo()
  {
   hori(65,30,9);
  circle(8,40,18,1,5,1); 
  circle(9,46,39,2,6,1); 
  hori(16,55,38);
  vrt(50,70,12); 
  vrt(50,78,12); 
  cross(8,50,0,1); 
  cross(8,58,0,1);    
  }
  void aan()
  {
  hori(65,30,9);
  circle(8,40,18,1,5,1); 
  circle(9,46,39,2,6,1); 
  hori(16,55,38);
  vrt(50,70,12); 
  u8g2.drawDisc(55,3,2);   
  }
  void aah()
  {
   hori(65,30,9);
  circle(8,40,18,1,5,1); 
  circle(9,46,39,2,6,1); 
  hori(16,55,38);
  vrt(50,70,12); 
  u8g2.drawDisc(79,23,2);
  u8g2.sendBuffer();   
  delay(1000);   
  u8g2.drawDisc(79,43,2);   
  }
  void adha()
  {
  hori(68,30,0);
  vrt(7,64,3);
  circle(8,64,10,1,5,0);
  circle(8,64,31,2,6,1); 
  u8g2.drawDisc(61,57,2);    
  }
  void adda()
  {
   hori(68,30,0);
  vrt(5,64,3);
  circle(13,67,12,1,5,0);
  circle(5,68,43,6,8,0);
  circle(5,67,37,1,3,0);
 // circle(5,66,59,4,4,0); 
  u8g2.drawDisc(65,55,2);   
  }
  void shara()
  {
   hori(20,60,0);
  vrt(50,70,3);
  cross(22,69,28,0);  
  cross(15,46,20,1);  
  circle(5,45,17,5,8,1);
  circle(5,42,10,1,5,1);
  cross(18,45,20,0);  
  }
  void ree()
  {
   hori(60,40,0);
  vrt(50,80,3);
  circle(10,78,25,8,8,0);
  circle(13,70,19,1,1,0);
  circle(18,79,25,4,4,1);
  hori(10,84,11);
  circle(6,99,15,1,4,0);
  circle(7,95,30,2,5,0);
  }
  ///////////////////////////////
  /////////special char//////////
  void star()
  {
  cross(50,40,5,1);
  cross(50,90,5,0);
  hori(58,37,28);
  }
  void ach()
  {
   hori(68,30,0);
  circle(12,40,15,1,6,1);
  hori(16,65,27);
  vrt(50,81,3);   
  }
  void question()
  {
  circle(13,60,5,1,4,1);
  //circle(5,68,43,6,8,0);
  vrt(9,69,41); 
  u8g2.drawDisc(71,58,2);     
  }
  void and_m()
  {
   hori(68,30,0);
  circle(12,40,15,1,6,1);
  hori(16,65,27);
  vrt(50,81,3);   
  }
  void exclamnation()
  {
  vrt(47,69,4); 
  u8g2.drawDisc(70,58,2);       
  }
  void backslash()
  {
   hori(68,30,0);
  circle(12,40,15,1,6,1);
  hori(16,65,27);
  vrt(50,81,3);   
  }
  void slash()
  {
   hori(68,30,0);
  circle(12,40,15,1,6,1);
  hori(16,65,27);
  vrt(50,81,3);   
  }
  void lessthan()
  {
   hori(68,30,0);
  circle(12,40,15,1,6,1);
  hori(16,65,27);
  vrt(50,81,3);   
  }
  void greaterthan()
  {
   hori(68,30,0);
  circle(12,40,15,1,6,1);
  hori(16,65,27);
  vrt(50,81,3);   
  }
  void doublequote()
  {
   hori(68,30,0);
  circle(12,40,15,1,6,1);
  hori(16,65,27);
  vrt(50,81,3);   
  }
  void rightbracket()
  {
   hori(68,30,0);
  circle(12,40,15,1,6,1);
  hori(16,65,27);
  vrt(50,81,3);   
  }
  void leftbracket()
  {
   hori(68,30,0);
  circle(12,40,15,1,6,1);
  hori(16,65,27);
  vrt(50,81,3);   
  }
  void leftbrace()
  {
   hori(68,30,0);
  circle(12,40,15,1,6,1);
  hori(16,65,27);
  vrt(50,81,3);   
  }
  void rightbrace()
  {
   hori(68,30,0);
  circle(12,40,15,1,6,1);
  hori(16,65,27);
  vrt(50,81,3);   
  }
  void caret()
  {
   hori(68,30,0);
  circle(12,40,15,1,6,1);
  hori(16,65,27);
  vrt(50,81,3);   
  }
  void atsign()
  {
  hori(68,30,0);
  circle(12,40,15,1,6,1);
  hori(16,65,27);
  vrt(50,81,3);   
  }
  
//////////////captial letter//////////
//////////////////////////////////////

 void A()
{
 cross1(53,62,3,0);
 cross1(53,65,3,1);
 hori(33,48,33);
}
void B()
{
 vrt(60,50,0); 
 circle(10,54,5,1,5,1); 
 circle(10,64,32,2,5,1); 
}
void C()
{
 circle(16,75,10,1,5,0); 
}
void D()
{
 circle(16,50,10,1,5,1); 
 vrt(45,53,10); 
}
void E()
{
 vrt(60,40,0); 
  hori(34,40,0);
  hori(30,40,30);
  hori(34,40,60);
}
void F1()
{
 vrt(60,40,0); 
  hori(34,40,0);
  hori(30,40,30);
}
 void G()
  {
  // hori(68,30,0);
  circle(12,50,12,2,7,0);
  hori(10,75,20);
  vrt(25,85,20);      
  }
  void H()
{
 vrt(50,40,8);
 vrt(50,70,8); 
  hori(30,40,31);
}
void I()
{
  hori(35,40,7);
 vrt(50,55,7);
  hori(35,40,55);
}
void J()
  {
  hori(40,45,4);
  vrt(40,71,6);
  circle(9,70,46,4,7,1);
  } 
  void K()
  {
  vrt(54,50,5);
  cross(25,75,6,0);
  cross(25,50,32,1);
  } 
  void L()
  {
  vrt(55,50,6);
 hori(35,50,57);
 vrt1(6,81,56);
  }
  void M()
  {
 vrt(55,40,6);
 cross(20,40,6,1);
 cross(20,80,6,0);
 vrt(55,80,6);   
  }
  void N()
  {
 vrt(55,40,6);
 cross1(42,40,10,1);
 vrt(55,82,6);   
  }
  void O()
  {
  circle(16,70,10,1,8,0);
  }
  void P()
  {
 vrt(55,50,6);  
 circle(11,54,10,1,5,1);
  }
  void Q()
  {
  circle(16,70,10,1,8,0);
  cross(12,73,40,1);
  }
  void R()
  {
  vrt(55,50,6);  
  circle(11,54,10,1,5,1);
  cross(22,53,35,1);
  }
  void S()
  {
 circle(9,70,15,8,8,0);
 circle(9,64,10,1,5,0);
 circle(9,64,34,2,6,1);
  }
  void T()
{
 hori(45,40,7);
 vrt(50,60,7); 
}
void U()
{
 vrt(33,39,6);
 circle(13,43,37,3,7,0);
 vrt1(33,75,37); 
}
void V()
  {
  cross1(50,40,6,1);
 cross1(50,90,6,0);
  }
  void W()
  {
 vrt(55,40,6);
 cross(20,60,40,0);
 cross(20,60,40,1);
 //hori(35,50,57);
 vrt(55,80,6); 
  }
  void X1()
  {
 cross1(54,50,4,1);
 cross1(54,77,4,0);
  }
   void Y1()
  {
 cross(25,40,6,1);
 cross(25,90,6,0);
  vrt(28,65,32); 
  }
   void Z()
  {
 hori(45,40,3);
 cross(50,85,7,0);
  hori(45,40,57);
  } 
  ///////////small letter/////////
  ////////////////////////////////
  void a()
{
  circle(10,70,16,8,8,0);
  circle(16,64,10,1,5,0);
  circle(10,64,50,6,6,0);
  vrt(27,71,16);
  circle(7,74,45,4,6,0); 
}
void b()
{
  vrt(52,50,8);
  circle(11,54,30,1,5,1); 
}

void c()
{
  circle(5,71,19,8,8,0);
  circle(13,70,18,1,5,0);
  circle(5,71,49,6,6,0);
}

void dd()
{
  vrt(52,70,8);
  circle(11,69,30,1,5,0);
}

void e()
{
  circle(34,50,35,1,1,1);
  circle(10,80,34,7,8,0);
  circle(14,74,18,1,5,0);
  circle(7,75,52,6,6,0);
}

void f()
{
  circle(7,69,13,8,8,0);
  circle(7,64,10,1,2,0);
  vrt(46,50,15);
  circle(15,44,33,1,1,1);
}

void g()
{
  circle(10,69,10,1,5,0);
  vrt(51,70,5);
  circle(7,69,55,4,6,1);  
}

void h()
{
  u8g2.clearBuffer();
  vrt(55,50,5);
  circle(18,54,35,1,1,1);
  circle(8,73,35,2,2,1);
  vrt(20,78,40); 
}

void i()
{
  circle(6,45,50,4,6,0);
  vrt(20,58,30);
  circle(6,62,49,4,6,0);
  circle(3,60,19,1,8,0);
}

void j()
{
  circle(8,53,28,8,8,1);
  vrt(35,58,20);
  circle(6,57,55,4,6,1);
  circle(3,60,10,1,8,0);
}

void k ()
{
  vrt(42,58,15);
  circle(10,63,45,8,8,1);
  circle(10,65,45,4,4,0);
}

void ll()
{
  circle(8,45,50,4,5,0);
  circle(12,57,54,6,6,0);
  vrt(35,66,10);
  circle(3,65,9,8,8,0);
  circle(3,65,10,1,3,0);
  vrt(32,59,13);
  circle(12,63,45,4,4,0);
  circle(7,72,54,5,6,0);
}
void mm()
{
  vrt(35,40,20);
  circle(10,44,30,8,8,1);
  circle(8,50,24,1,3,1);
  vrt(18,63,37);
  circle(10,67,30,8,8,1);
  circle(8,74,24,1,3,1);
  vrt(18,87,37); 
}
void nn()
{
  vrt(40,40,20);
  circle(10,44,32,8,8,1);
  circle(10,50,26,1,3,1);
  vrt(16,67,43); 
}
void oo()
{
  circle(15,60,15,1,8,1); 
}
void pp()
{
 vrt(50,50,10);
 circle(10,54,30,8,8,1);
 circle(10,60,24,1,6,1);
}
void qq()
{
  vrt(50,70,10);
  circle(10,69,20,8,8,0);
  circle(9,63,14,1,6,0);
  circle(17,70,58,6,6,0);
}
void r()
{
  circle(13,28,50,5,7,0);
  circle(6,50,27,8,8,0);
  circle(4,46,25,1,5,0);
  circle(30,46,34,1,1,1);
  vrt(16,72,30);
  circle(7,76,46,4,6,0);
}
void s()
{
  circle(37,36,58,8,8,1);
  circle(6,70,20,8,8,0);
  circle(5,66,18,1,4,0);
  circle(10,64,32,2,6,1);
}
void t()
{
  circle(6,45,50,4,6,0);
  vrt(37,57,12);
  circle(6,61,49,4,6,0);
  circle(20,49,29,1,1,1);
}
void u()
{
  vrt(35,45,15);
  circle(10,49,50,4,6,0);
  circle(35,75,50,7,7,1);
  circle(6,75,51,4,6,0);
}
void v()
{
  circle(23,45,27,4,4,0);
  circle(3,65,50,1,1,1);
  circle(20,68,46,6,6,0);
  circle(5,84,26,8,8,0);
  circle(4,82,26,1,5,0);
  circle(9,85,34,1,1,1);  
}
void w()
{
  vrt(30,40,20);
  circle(7,44,50,4,6,0);
  vrt(10,58,40);
  circle(7,61,50,4,6,0);
  circle(29,79,49,7,7,1);
  circle(5,75,20,8,8,0);
  circle(4,73,19,1,5,0);
  circle(9,80,27,1,1,1); 
}
void x()
{
  circle(10,43,30,1,5,1);
  circle(10,82,30,1,5,0);
}
void y()
{
  vrt(20,45,10);
  circle(8,49,30,4,6,0);
  vrt(43,66,10);
  circle(7,65,53,4,6,1);
}
void z()
{
  circle(25,45,10,1,1,1);
  circle(18,71,6,4,4,1);
  circle(11,53,29,1,4,1);
  circle(7,63,60,1,1,0);
  circle(4,55,55,6,8,1);
  circle(20,60,46,8,8,1);
}
///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////


struct _st_ot_struct
{
 uint8_t missle_mask;    /* this object is a missle: it might destroy something if the target is_hit_fn says so */ 
  uint8_t hit_mask;     /* if missle_mask & hit_mask is != 0  then the object can be destroyed */
  uint8_t points;
  uint8_t draw_fn;
  uint8_t move_fn;
      /* ST_MOVE_FN_NONE, ST_MOVE_FN_X_SLOW */
  uint8_t destroy_fn;   /* object can be destroyed by a missle (e.g. a missle from the space ship) */
      /* ST_DESTROY_FN_NONE, ST_DESTROY_FN_SPLIT */
  uint8_t is_hit_fn;    /* is hit procedure */
      /* ST_IS_HIT_FN_NONE, ST_IS_HIT_BBOX */
  uint8_t fire_fn;
    /* ST_FIRE_FN_NONE, ST_FIRE_FN_X_LEFT */
  
};
typedef struct _st_ot_struct st_ot;
struct _st_obj_struct
{
  uint8_t ot;       /* object type: zero means, object is not used */
  int8_t tmp;     /* generic value, used by ST_MOVE_IMPLODE */
  int16_t x, y;
  int8_t x0,y0,x1,y1; /* object outline in pixel, reference point is at 0,0 */
};
typedef struct _st_obj_struct st_obj;

#define ST_DRAW_NONE 0
#define ST_DRAW_BBOX 1
#define ST_DRAW_TRASH1 2
#define ST_DRAW_PLAYER1 3
#define ST_DRAW_TRASH2 4
#define ST_DRAW_PLAYER2 5
#define ST_DRAW_PLAYER3 6
#define ST_DRAW_GADGET 7
#define ST_DRAW_BACKSLASH 8
#define ST_DRAW_SLASH 9
#define ST_DRAW_BIG_TRASH 10

#define ST_MOVE_NONE 0
#define ST_MOVE_X_SLOW 1
#define ST_MOVE_PX_NORMAL 2
#define ST_MOVE_PX_FAST 3
#define ST_MOVE_PLAYER 4
#define ST_MOVE_PY 5
#define ST_MOVE_NY 6
#define ST_MOVE_IMPLODE 7
#define ST_MOVE_X_FAST 8
#define ST_MOVE_WALL 9
#define ST_MOVE_NXPY 10
#define ST_MOVE_NXNY 11

#define ST_IS_HIT_NONE 0
#define ST_IS_HIT_BBOX 1
#define ST_IS_HIT_WALL 2

#define ST_DESTROY_NONE 0
#define ST_DESTROY_DISAPPEAR 1
#define ST_DESTROY_TO_DUST 2
#define ST_DESTROY_GADGET 3
#define ST_DESTROY_PLAYER 4
#define ST_DESTROY_PLAYER_GADGETS 5
#define ST_DESTROY_BIG_TRASH 6

#define ST_FIRE_NONE 0
#define ST_FIRE_PLAYER1 1
#define ST_FIRE_PLAYER2 2
#define ST_FIRE_PLAYER3 3

#define ST_OT_WALL_SOLID 1
#define ST_OT_BIG_TRASH 2
#define ST_OT_MISSLE 3
#define ST_OT_TRASH1 4
#define ST_OT_PLAYER 5
#define ST_OT_DUST_PY 6
#define ST_OT_DUST_NY 7
#define ST_OT_TRASH_IMPLODE 8
#define ST_OT_TRASH2 9
#define ST_OT_PLAYER2 10
#define ST_OT_PLAYER3 11
#define ST_OT_GADGET 12
#define ST_OT_GADGET_IMPLODE 13
#define ST_OT_DUST_NXPY 14
#define ST_OT_DUST_NXNY 15

u8g2_t *st_u8g2;

u8g2_uint_t u8g_height_minus_one;

#define ST_AREA_HEIGHT (st_u8g2->height - 8)
#define ST_AREA_WIDTH (st_u8g2->width)

const st_ot st_object_types[] U8X8_PROGMEM =
{
    /* 0: empty object type */
    { 0, 0,  0, ST_DRAW_NONE, ST_MOVE_NONE, ST_DESTROY_DISAPPEAR, ST_IS_HIT_NONE, ST_FIRE_NONE },
    /* 1: wall, player will be destroyed */
    { 2, 1, 30, ST_DRAW_BBOX, ST_MOVE_WALL, ST_DESTROY_DISAPPEAR, ST_IS_HIT_WALL, ST_FIRE_NONE },
    /* ST_OT_BIG_TRASH (2) */
    { 2, 1,  0, ST_DRAW_BIG_TRASH, ST_MOVE_X_SLOW, ST_DESTROY_BIG_TRASH, ST_IS_HIT_BBOX, ST_FIRE_NONE },
    /* 3: simple space ship (player) missle */
    { 1, 0,  0, ST_DRAW_BBOX, ST_MOVE_PX_FAST, ST_DESTROY_DISAPPEAR, ST_IS_HIT_NONE, ST_FIRE_NONE },
    /* ST_OT_TRASH1 (4): trash */
    { 2, 1,  0, ST_DRAW_TRASH1, ST_MOVE_X_SLOW, ST_DESTROY_TO_DUST, ST_IS_HIT_BBOX, ST_FIRE_NONE },
    /* ST_OT_PLAYER (5): player space ship */
    { 0, 2,  0, ST_DRAW_PLAYER1, ST_MOVE_PLAYER, ST_DESTROY_PLAYER, ST_IS_HIT_BBOX, ST_FIRE_PLAYER1 },
    /* ST_OT_DUST_PY (6): Last part of trash  */
    { 0, 0,  0, ST_DRAW_BBOX, ST_MOVE_PY, ST_DESTROY_NONE, ST_IS_HIT_NONE, ST_FIRE_NONE },
    /* ST_OT_DUST_NY (7): Last part of trash  */
    { 0, 0,  0, ST_DRAW_BBOX, ST_MOVE_NY, ST_DESTROY_NONE, ST_IS_HIT_NONE, ST_FIRE_NONE },
    /* ST_OT_TRASH_IMPLODE (8): trash was hit */
    { 0, 0,  5, ST_DRAW_TRASH1, ST_MOVE_IMPLODE, ST_DESTROY_NONE, ST_IS_HIT_NONE, ST_FIRE_NONE },
    /* ST_OT_TRASH2 (9): trash */
    { 2, 1,  0, ST_DRAW_TRASH2, ST_MOVE_X_SLOW, ST_DESTROY_TO_DUST, ST_IS_HIT_BBOX, ST_FIRE_NONE },
    /* ST_OT_PLAYER2 (10): player space ship+1x enhancement */
    { 0, 2,  0, ST_DRAW_PLAYER2, ST_MOVE_PLAYER, ST_DESTROY_PLAYER_GADGETS, ST_IS_HIT_BBOX, ST_FIRE_PLAYER2 },
    /* ST_OT_PLAYER3 (11): player space ship+2x enhancement */
    { 0, 2,  0, ST_DRAW_PLAYER3, ST_MOVE_PLAYER, ST_DESTROY_PLAYER_GADGETS, ST_IS_HIT_BBOX, ST_FIRE_PLAYER3 },
    /* ST_OT_GADGET (12): adds enhancements */
    { 0, 1,  0, ST_DRAW_GADGET, ST_MOVE_X_FAST, ST_DESTROY_GADGET, ST_IS_HIT_BBOX, ST_FIRE_NONE },
    /* ST_OT_GADGET_IMPLODE (13) */
    { 0, 0, 20, ST_DRAW_GADGET, ST_MOVE_IMPLODE, ST_DESTROY_NONE, ST_IS_HIT_NONE, ST_FIRE_NONE },
    /* ST_OT_DUST_NXPY (14): Last part of trash  */
    { 0, 0,  0, ST_DRAW_BACKSLASH, ST_MOVE_NXPY, ST_DESTROY_NONE, ST_IS_HIT_NONE, ST_FIRE_NONE },
    /* ST_OT_DUST_NXNY (15): Last part of trash  */
    { 0, 0,  0, ST_DRAW_SLASH, ST_MOVE_NXNY, ST_DESTROY_NONE, ST_IS_HIT_NONE, ST_FIRE_NONE },
    
};

#if RAMEND < 0x300 
#define ST_OBJ_CNT 25
#else
//#define ST_OBJ_CNT 45
#define ST_OBJ_CNT 60
#endif 

st_obj st_objects[ST_OBJ_CNT];

uint8_t st_player_pos;

#define ST_POINTS_PER_LEVEL 25
uint16_t st_player_points;
uint16_t st_player_points_delayed;
uint16_t st_highscore = 0;

#define ST_STATE_PREPARE 0
#define ST_STATE_IPREPARE 1
#define ST_STATE_GAME 2
#define ST_STATE_END 3
#define ST_STATE_IEND 4

uint8_t st_state = ST_STATE_PREPARE;

/*================================================================*/
/* game difficulty */
/*================================================================*/
uint8_t st_difficulty = 1;
#define ST_DIFF_VIS_LEN 30
#define ST_DIFF_FP 5
uint16_t st_to_diff_cnt = 0;

const uint8_t st_bitmap_player1[]  = 
{ 
  /* 01100000 */ 0x060,
  /* 11111000 */ 0x0f8,
  /* 01111110 */ 0x07e,
  /* 11111000 */ 0x0f8,
  /* 01100000 */ 0x060
};

const uint8_t st_bitmap_player2[] = 
{   
  /* 01100000 */ 0x060,
  /* 01111100 */ 0x078,
  /* 01100000 */ 0x060,
  /* 11100000 */ 0x0e0,
  /* 11111000 */ 0x0f8,
  /* 01111110 */ 0x07e,
  /* 11111000 */ 0x0f8,
  /* 01100000 */ 0x060
};

const uint8_t st_bitmap_player3[] = 
{   
  /* 01100000 */ 0x060,
  /* 01111100 */ 0x078,
  /* 01100000 */ 0x060,
  /* 11100000 */ 0x0e0,
  /* 11111000 */ 0x0f8,
  /* 01111110 */ 0x07e,
  /* 11111000 */ 0x0f8,
  /* 11100000 */ 0x0e0,
  /* 01100000 */ 0x060,
  /* 01111100 */ 0x078,
  /* 01100000 */ 0x060
 };

const uint8_t st_bitmap_trash_5x5_1[] = 
{ 
  /* 01110000 */ 0x070,
  /* 11110000 */ 0x0f0,
  /* 11111000 */ 0x0f8,
  /* 01111000 */ 0x078,
  /* 00110000 */ 0x030,
};

const uint8_t st_bitmap_trash_5x5_2[] = 
{ 
  /* 00110000 */ 0x030,
  /* 11111000 */ 0x0f8,
  /* 11111000 */ 0x0f8,
  /* 11110000 */ 0x0f0,
  /* 01110000 */ 0x070,
};

const uint8_t st_bitmap_trash_7x7[] = 
{
  /* 00111000 */ 0x038,
  /* 01111100 */ 0x07c,
  /* 11111100 */ 0x0fc,
  /* 11111110 */ 0x0fe,
  /* 11111110 */ 0x0fe,
  /* 01111110 */ 0x07e,
  /* 01111000 */ 0x078,
};

const uint8_t st_bitmap_gadget[] = 
{ 
  /* 01110000 */ 0x070,
  /* 11011000 */ 0x0d8,
  /* 10001000 */ 0x088,
  /* 11011000 */ 0x0d8,
  /* 01110000 */ 0x070,
};
uint8_t st_rnd(void) U8X8_NOINLINE;
static st_obj *st_GetObj(uint8_t objnr) U8X8_NOINLINE;
uint8_t st_GetMissleMask(uint8_t objnr);
uint8_t st_GetHitMask(uint8_t objnr);
int8_t st_FindObj(uint8_t ot) U8X8_NOINLINE;
void st_ClrObjs(void) U8X8_NOINLINE;
int8_t st_NewObj(void) U8X8_NOINLINE;
uint8_t st_CntObj(uint8_t ot);
uint8_t st_CalcXY(st_obj *o) U8X8_NOINLINE;
void st_SetXY(st_obj *o, uint8_t x, uint8_t y) U8X8_NOINLINE;

void st_FireStep(uint8_t is_auto_fire, uint8_t is_fire) U8X8_NOINLINE;

void st_InitTrash(uint8_t x, uint8_t y, int8_t dir);
void st_NewGadget(uint8_t x, uint8_t y);
void st_NewPlayerMissle(uint8_t x, uint8_t y) ;
void st_NewTrashDust(uint8_t x, uint8_t y, int ot);
void st_NewTrashDustAreaArgs(int16_t x, int16_t y, int ot); 
void st_SetupPlayer(uint8_t objnr, uint8_t ot);

char st_itoa_buf[12];
char *st_itoa(unsigned long v)
{
  volatile unsigned char i = 11;
  st_itoa_buf[11] = '\0';
  while( i > 0)
  {
      i--;
      st_itoa_buf[i] = (v % 10)+'0';
      v /= 10;
      if ( v == 0 )
  break;
  }
  return st_itoa_buf+i;
}


uint8_t st_rnd(void)
{
  return rand();
}

static st_obj *st_GetObj(uint8_t objnr)
{
  return st_objects+objnr;
}

uint8_t st_GetMissleMask(uint8_t objnr)
{
  st_obj *o = st_GetObj(objnr);
  return u8x8_pgm_read(&(st_object_types[o->ot].missle_mask));
}

uint8_t st_GetHitMask(uint8_t objnr)
{
  st_obj *o = st_GetObj(objnr);
  return u8x8_pgm_read(&(st_object_types[o->ot].hit_mask));
}

int8_t st_FindObj(uint8_t ot)
{
  int8_t i;
  for( i = 0; i < ST_OBJ_CNT; i++ )
  {
    if ( st_objects[i].ot == ot )
      return i;
  }
  return -1;
}

void st_ClrObjs(void)
{
  int8_t i;
  for( i = 0; i < ST_OBJ_CNT; i++ )
    st_objects[i].ot = 0;
}

int8_t st_NewObj(void)
{
  int8_t i;
  for( i = 0; i < ST_OBJ_CNT; i++ )
  {
    if ( st_objects[i].ot == 0 )
      return i;
  }
  return -1;
}

uint8_t st_CntObj(uint8_t ot)
{
  uint8_t i;
  uint8_t cnt = 0;
  for( i = 0; i < ST_OBJ_CNT; i++ )
  {
    if ( st_objects[i].ot == ot )
      cnt++;
  }
  return cnt;
}

uint8_t st_px_x, st_px_y; /* pixel within area */
uint8_t st_CalcXY(st_obj *o)
{
  //st_obj *o = st_GetObj(objnr);
  st_px_y = o->y>>ST_FP;
  st_px_x = o->x>>ST_FP;
  return st_px_x;
}

void st_SetXY(st_obj *o, uint8_t x, uint8_t y)
{
  o->x = ((int16_t)x) << ST_FP;
  o->y = ((int16_t)y) << ST_FP;
}
int16_t st_bbox_x0, st_bbox_y0, st_bbox_x1, st_bbox_y1;  

void st_CalcBBOX(uint8_t objnr)
{
  st_obj *o = st_GetObj(objnr);
  
  st_bbox_x0 = (uint16_t)(o->x>>ST_FP);
  st_bbox_x1 = st_bbox_x0;
  st_bbox_x0 += o->x0;
  st_bbox_x1 += o->x1;

  st_bbox_y0 = (uint16_t)(o->y>>ST_FP);
  st_bbox_y1 = st_bbox_y0;
  st_bbox_y0 += o->y0;
  st_bbox_y1 += o->y1;
}
uint8_t st_cbbox_x0, st_cbbox_y0, st_cbbox_x1, st_cbbox_y1;
uint8_t st_ClipBBOX(void)
{
  if ( st_bbox_x0 >= ST_AREA_WIDTH )
    return 0;
  if ( st_bbox_x0 >= 0 )
    st_cbbox_x0  = (uint16_t)st_bbox_x0;
  else
    st_cbbox_x0 = 0;

  if ( st_bbox_x1 < 0 )
    return 0;
  if ( st_bbox_x1 < ST_AREA_WIDTH )
    st_cbbox_x1  = (uint16_t)st_bbox_x1;
  else
    st_cbbox_x1 = ST_AREA_WIDTH-1;

  if ( st_bbox_y0 >= ST_AREA_HEIGHT )
    return 0;
  if ( st_bbox_y0 >= 0 )
    st_cbbox_y0  = (uint16_t)st_bbox_y0;
  else
    st_cbbox_y0 = 0;

  if ( st_bbox_y1 < 0 )
    return 0;
  if ( st_bbox_y1 < ST_AREA_HEIGHT )
    st_cbbox_y1  = (uint16_t)st_bbox_y1;
  else
    st_cbbox_y1 = ST_AREA_HEIGHT-1;
  
  return 1;
}
uint8_t st_IsOut(uint8_t objnr)
{
  st_CalcBBOX(objnr);
  if ( st_bbox_x0 >= ST_AREA_WIDTH )
    return 1;
  if ( st_bbox_x1 < 0 )
    return 1;
  if ( st_bbox_y0 >= ST_AREA_HEIGHT )
    return 1;
  if ( st_bbox_y1 < 0 )
    return 1;
  return 0;
}
void st_Disappear(uint8_t objnr)
{
  st_obj *o = st_GetObj(objnr);
  st_player_points += u8x8_pgm_read(&(st_object_types[o->ot].points));
  o->ot = 0;
}
void st_Move(uint8_t objnr)
{
  st_obj *o = st_GetObj(objnr);
  switch(u8x8_pgm_read(&(st_object_types[o->ot].move_fn)))
  {
    case ST_MOVE_NONE:
      break;
    case ST_MOVE_X_SLOW:
      o->x -= (1<<ST_FP)/8;
      o->x -= st_difficulty;
      o->y += (int16_t)o->tmp;
      if ( o->y >= ((ST_AREA_HEIGHT-1) << ST_FP) || o->y <= 0 )
  o->tmp = - o->tmp;
      break;
    case ST_MOVE_X_FAST:
      o->x -= (1<<ST_FP)/2;
      o->y += (int16_t)o->tmp;
      if ( o->y >= ((ST_AREA_HEIGHT-1) << ST_FP) || o->y <= 0 )
  o->tmp = - o->tmp;
      break;
    case ST_MOVE_PX_NORMAL:
      o->x += (1<<ST_FP)/4;
      break;
    case ST_MOVE_PX_FAST:
      o->x += (1<<ST_FP);
      break;
    case ST_MOVE_PLAYER:
      o->y = st_player_pos<<ST_FP;
      break;
    case ST_MOVE_PY:
      o->y += 3*ST_FP;
      break;
    case ST_MOVE_NY:
      o->y -= 3*ST_FP;
      break;
    case ST_MOVE_NXPY:
      o->y += 3*ST_FP;
      o->x -= 3*ST_FP;
      break;
    case ST_MOVE_NXNY:
      o->y -= 3*ST_FP;
      o->x -= 3*ST_FP;
      break;
    case ST_MOVE_IMPLODE:
      o->tmp++;
      if ( (o->tmp & 0x03) == 0 )
      {
  if ( o->x0 != o->x1 )
    o->x0++;
  else
      st_Disappear(objnr);
      }
      break;
    case ST_MOVE_WALL:
      o->x -= 1;
      o->x -= (st_difficulty>>1);
      break;
  }
}

void st_DrawBBOX(uint8_t objnr)
{
  uint8_t y0, y1;
  /*st_obj *o = st_GetObj(objnr);*/
  st_CalcBBOX(objnr);
  if ( st_ClipBBOX() == 0 )
    return;
  u8g2_SetDrawColor(st_u8g2, 1);
  y0 = u8g_height_minus_one - st_cbbox_y0;
  y1 = u8g_height_minus_one - st_cbbox_y1;
  
  u8g2_DrawFrame(st_u8g2, st_cbbox_x0, y1, st_cbbox_x1-st_cbbox_x0+1, y0-y1+1);

}

#ifdef FN_IS_NOT_IN_USE
void st_DrawFilledBox(uint8_t objnr)
{
  st_CalcBBOX(objnr);
  if ( st_ClipBBOX() == 0 )
    return;
  /* st_cbbox_x0, st_cbbox_y0, st_cbbox_x1, st_cbbox_y1; */
  dog_SetBox(st_cbbox_x0, st_cbbox_y0, st_cbbox_x1, st_cbbox_y1);
}
#endif

void st_DrawBitmap(uint8_t objnr, const uint8_t * bm, uint8_t w, uint8_t h)
{
  /* st_obj *o = st_GetObj(objnr); */
  st_CalcBBOX(objnr);
 u8g2_DrawBitmap(st_u8g2, st_bbox_x0, u8g_height_minus_one - st_bbox_y1, (w+7)/8, h, bm);
  
 }

void st_DrawObj(uint8_t objnr)
{
  st_obj *o = st_GetObj(objnr);
  switch(u8x8_pgm_read(&(st_object_types[o->ot].draw_fn)))
  {
    case ST_DRAW_NONE:
      break;
    case ST_DRAW_BBOX:
      st_DrawBBOX(objnr);
      break;
    case ST_DRAW_TRASH1:
      st_DrawBitmap(objnr, st_bitmap_trash_5x5_1,o->x1-o->x0+1, 5);
      break;
    case ST_DRAW_TRASH2:
      st_DrawBitmap(objnr, st_bitmap_trash_5x5_2,o->x1-o->x0+1, 5);
      break;
    case ST_DRAW_BIG_TRASH:
      st_DrawBitmap(objnr, st_bitmap_trash_7x7,o->x1-o->x0+1, 7);
      break;
    case ST_DRAW_PLAYER1:
      st_DrawBitmap(objnr, st_bitmap_player1,7,5);
      break;
    case ST_DRAW_PLAYER2:
      st_DrawBitmap(objnr, st_bitmap_player2,7,8);
      break;
    case ST_DRAW_PLAYER3:
      st_DrawBitmap(objnr, st_bitmap_player3,7,11);
      break;
    case ST_DRAW_GADGET:
         st_DrawBitmap(objnr, st_bitmap_gadget,5,5);
      break;
    case ST_DRAW_BACKSLASH:
      {
  uint8_t x;
  uint8_t y;
  x = st_CalcXY(o);
  y = st_px_y;  
  u8g2_SetDrawColor(st_u8g2, 1);  
  u8g2_DrawPixel(st_u8g2, x, u8g_height_minus_one - y);  
  x++; y--;
  u8g2_DrawPixel(st_u8g2, x, u8g_height_minus_one - y);  
  x++; y--;
  u8g2_DrawPixel(st_u8g2, x, u8g_height_minus_one - y);   
     }      
     break;
    case ST_DRAW_SLASH:
      {
  uint8_t x;
  uint8_t y;
  x = st_CalcXY(o);
  y = st_px_y;
  u8g2_SetDrawColor(st_u8g2, 1);  
  u8g2_DrawPixel(st_u8g2, x, u8g_height_minus_one - y);  
  x++; y++;
  u8g2_DrawPixel(st_u8g2, x, u8g_height_minus_one - y);  
  x++; y++;
  u8g2_DrawPixel(st_u8g2, x, u8g_height_minus_one - y);   
     }      
     break;
  }
}
uint8_t st_IsHitBBOX(uint8_t objnr, uint8_t x, uint8_t y)
{
  st_CalcBBOX(objnr);
  if ( st_ClipBBOX() == 0 ) 
    return 0; /* obj is outside (not visible) */
  if ( x < st_cbbox_x0 )
    return 0;
  if ( x > st_cbbox_x1 )
    return 0;
  if ( y < st_cbbox_y0 )
    return 0;
  if ( y > st_cbbox_y1 )
    return 0;
  return 1;
}
void st_Destroy(uint8_t objnr)
{
  int8_t nr;
  st_obj *o = st_GetObj(objnr);
  switch(u8x8_pgm_read(&(st_object_types[o->ot].destroy_fn)))
  {
    case ST_DESTROY_NONE:      /* only usefull for missels or walls which stay alife */
      break;
    case ST_DESTROY_DISAPPEAR:  /* this should be the default operation */
      st_Disappear(objnr);
      break;
    case ST_DESTROY_GADGET:
      nr = st_FindObj(ST_OT_PLAYER2);
      if ( nr >= 0 )
  st_SetupPlayer(nr, ST_OT_PLAYER3);
      else
      {
  nr = st_FindObj(ST_OT_PLAYER);
  if ( nr >= 0 )
    st_SetupPlayer(nr, ST_OT_PLAYER2);
      }
      st_NewTrashDustAreaArgs(o->x, o->y, ST_OT_DUST_PY);
      st_NewTrashDustAreaArgs(o->x, o->y, ST_OT_DUST_NY);
      o->ot = ST_OT_GADGET_IMPLODE;
      o->tmp = 0;
      break;
    case ST_DESTROY_TO_DUST:
      st_NewTrashDustAreaArgs(o->x, o->y, ST_OT_DUST_PY);
      st_NewTrashDustAreaArgs(o->x, o->y, ST_OT_DUST_NY);
      o->ot = ST_OT_TRASH_IMPLODE;
      o->tmp = 0;
      break;
    case ST_DESTROY_BIG_TRASH:
      st_NewTrashDustAreaArgs(o->x, o->y, ST_OT_DUST_PY);
      st_NewTrashDustAreaArgs(o->x, o->y, ST_OT_DUST_NY);
      st_InitTrash((o->x>>ST_FP)-1, (o->y>>ST_FP)+3, 2+(st_rnd()&3));
      st_InitTrash((o->x>>ST_FP)-2, (o->y>>ST_FP)-3, -2-(st_rnd()&3));
      st_Disappear(objnr);
      break;
    case ST_DESTROY_PLAYER:
      st_Disappear(objnr);
      st_state = ST_STATE_END;
      o->tmp = 0;
      break;
    case ST_DESTROY_PLAYER_GADGETS:
      /* o->ot = ST_OT_PLAYER; */
      st_SetupPlayer(objnr, ST_OT_PLAYER);
      break;
  }
}
uint8_t st_IsHit(uint8_t objnr, uint8_t x, uint8_t y, uint8_t missle_mask)
{
  uint8_t hit_mask = st_GetHitMask(objnr);
  st_obj *o;
  
  if ( (hit_mask & missle_mask) == 0 )
    return 0;
  
  o = st_GetObj(objnr);
  
  switch(u8x8_pgm_read(&(st_object_types[o->ot].is_hit_fn)))
  {
    case ST_IS_HIT_NONE:
      break;
    case ST_IS_HIT_BBOX:
      if ( st_IsHitBBOX(objnr, x, y) != 0 )
      {
  st_Destroy(objnr);
  return 1;
      }
      break;
    case ST_IS_HIT_WALL:
      if ( st_IsHitBBOX(objnr, x, y) != 0 )
      {
  o->x0++;
  if ( o->x0 < o->x1 )
  {
    st_NewTrashDust(x, y, ST_OT_DUST_NXPY);
    st_NewTrashDust(x, y, ST_OT_DUST_NXNY);
  }
  else
  {
    st_Destroy(objnr);
    st_NewTrashDust(x, y, ST_OT_DUST_NXPY);
    st_NewTrashDust(x, y, ST_OT_DUST_NXNY);
    st_NewTrashDust(x, y, ST_OT_DUST_NY);
    st_NewTrashDust(x, y, ST_OT_DUST_PY);
  }
  return 1;
      }
      break;
  }
  return 0;
}
uint8_t st_fire_player = 0;
uint8_t st_fire_period = 51;
uint8_t st_manual_fire_delay = 20;
uint8_t st_is_fire_last_value = 0;
void st_FireStep(uint8_t is_auto_fire, uint8_t is_fire)
{
  if ( is_auto_fire != 0 )
  {
    st_fire_player++;
    if ( st_fire_player >= st_fire_period )
      st_fire_player = 0;
  }
  else
  {
    if ( st_fire_player < st_manual_fire_delay )
    {
      st_fire_player++;
    }
    else
    {
      if ( st_is_fire_last_value == 0 )
  if ( is_fire != 0 )
    st_fire_player = 0;
    }
    st_is_fire_last_value = is_fire;
  }
}

void st_Fire(uint8_t objnr)
{
  st_obj *o = st_GetObj(objnr);
  uint8_t x;
  uint8_t y;
  
  switch(u8x8_pgm_read(&(st_object_types[o->ot].fire_fn)))
  {
    case ST_FIRE_NONE: 
      break;
    case ST_FIRE_PLAYER1: 
      if ( st_fire_player == 0 )
      {
  /* create missle at st_px_x and st_px_y */
  x = st_CalcXY(o);
  y = st_px_y;
  st_NewPlayerMissle(x , y );
      }
      break;
    case ST_FIRE_PLAYER2:
      if ( st_fire_player == 0 )
      {
  /* create missle at st_px_x and st_px_y */
  x = st_CalcXY(o);
  y = st_px_y;
  st_NewPlayerMissle(x , y );
  st_NewPlayerMissle(x , y+4 );
      }
      break;
    case ST_FIRE_PLAYER3:
      if ( st_fire_player == 0 )
      {
  /* create missle at st_px_x and st_px_y */
  x = st_CalcXY(o);
  y = st_px_y;
  st_NewPlayerMissle(x , y );
  st_NewPlayerMissle(x , y+4 );
  st_NewPlayerMissle(x , y-4 );
      }
      break;
  }
}
void st_NewGadget(uint8_t x, uint8_t y)
{
  st_obj *o;
  int8_t objnr = st_NewObj();
  if ( objnr < 0 )
    return;
  o = st_GetObj(objnr);
  st_SetXY(o, x, y);
  o->ot = ST_OT_GADGET;
  o->tmp = 8;
  o->x0 = -3;
  o->x1 = 1;
  o->y0 = -2;
  o->y1 = 2;
}
void st_InitTrash(uint8_t x, uint8_t y, int8_t dir)
{
  st_obj *o;
  int8_t objnr = st_NewObj();
  if ( objnr < 0 )
    return;
  o = st_GetObj(objnr);
  if ( (st_rnd() & 1) == 0 )
    o->ot = ST_OT_TRASH1;
  else
    o->ot = ST_OT_TRASH2;
  if ( dir == 0 )
  {
    o->tmp = 0;
    if ( st_rnd() & 1 )
    {
      if ( st_rnd() & 1 )
  o->tmp++;
      else
  o->tmp--;
    }
  }
  else
  {
    o->tmp = dir;
  }
  st_SetXY(o, x, y);
  o->x0 = -3;
  o->x1 = 1;
  o->y0 = -2;
  o->y1 = 2;
  if ( st_difficulty >= 5 )
  {
    if ( (st_rnd() & 3) == 0 )
    {
      o->ot = ST_OT_BIG_TRASH;
      o->y0--;
      o->y1++;
      o->x0--;
      o->x1++;
    }
  }
}
void st_NewTrashDust(uint8_t x, uint8_t y, int ot)
{
  st_obj *o;
  int8_t objnr = st_NewObj();
  if ( objnr < 0 )
    return;
  o = st_GetObj(objnr);
  o->ot = ot;
  st_SetXY(o, x, y);
  o->x0 = 0;
  o->x1 = 0;
  o->y0 = -2;
  o->y1 = 2;
}
void st_NewTrashDustAreaArgs(int16_t x, int16_t y, int ot)
{
  st_NewTrashDust(x>>ST_FP, y>>ST_FP, ot);
}
void st_NewWall(void)
{
  st_obj *o;
  int8_t objnr = st_NewObj();
  int8_t h;
  if ( objnr < 0 )
    return;
  o = st_GetObj(objnr);
  o->ot = ST_OT_WALL_SOLID;
  h = st_rnd();
  h &= 63;
  h = (int8_t)(((int16_t)h*(int16_t)(ST_AREA_HEIGHT/4))>>6);
  h += ST_AREA_HEIGHT/6;

  o->x0 = 0;
  o->x1 = 5;
  o->x = (ST_AREA_WIDTH-1)<<ST_FP;
 
  if ( (st_rnd() & 1) == 0 )
  {
    o->y = (ST_AREA_HEIGHT-1)<<ST_FP;
    
    o->y0 = -h;
    o->y1 = 0;
  }
  else
  {
    o->y = (0)<<ST_FP;
    o->y0 = 0;
    o->y1 = h;
  }
}
void st_NewPlayerMissle(uint8_t x, uint8_t y)
{
  st_obj *o;
  int8_t objnr = st_NewObj();
  if ( objnr < 0 )
    return;
  o = st_GetObj(objnr);
  o->ot = ST_OT_MISSLE;
  st_SetXY(o, x, y);
  o->x0 = -4;
  o->x1 = 1;
  o->y0 = 0;
  o->y1 = 0;
}

void st_SetupPlayer(uint8_t objnr, uint8_t ot)
{
  st_obj *o = st_GetObj(objnr);
  switch(ot)
  {
    case ST_OT_PLAYER:
      o->ot = ot;
      o->y0 = -2;
      o->y1 = 2;
      break;
    case ST_OT_PLAYER2:
      o->ot = ot;
      o->y0 = -2;
      o->y1 = 5;
      break;
    case ST_OT_PLAYER3:
      o->ot = ot;
      o->y0 = -5;
      o->y1 = 5;
      break;
  }
}

void st_NewPlayer(void)
{
  st_obj *o;
  int8_t objnr = st_NewObj();
  if ( objnr < 0 )
    return;
  o = st_GetObj(objnr);
  o->x = 6<<ST_FP;
  o->y = (ST_AREA_HEIGHT/2)<<ST_FP;
  o->x0 = -6;
  o->x1 = 0;
  st_SetupPlayer(objnr, ST_OT_PLAYER);
}
void st_InitDeltaWall(void)
{
  uint8_t i;
  uint8_t cnt = 0;
  uint8_t max_x = 0;
  uint8_t max_l;
  
  uint8_t min_dist_for_new = 40;
  uint8_t my_difficulty = st_difficulty;
  
  if ( st_difficulty >= 2 )
  {
    
    max_l = ST_AREA_WIDTH;
    max_l -= min_dist_for_new;
    
    if ( my_difficulty > 30 )
      my_difficulty = 30;
    min_dist_for_new -= my_difficulty;
    
    for( i = 0; i < ST_OBJ_CNT; i++ )
    {
      if ( st_objects[i].ot == ST_OT_WALL_SOLID )
      {
  cnt++;
  if ( max_x < (st_objects[i].x>>ST_FP) )
    max_x = (st_objects[i].x>>ST_FP);
      }
    }    
    /* if ( cnt < upper_trash_limit ) */
    if ( max_x < max_l ) 
    {
      st_NewWall();
    }
  }
}
void st_InitDeltaTrash(void)
{
  uint8_t i;
  uint8_t cnt = 0;
  uint8_t max_x = 0;
  uint8_t max_l;
  
  uint8_t upper_trash_limit = ST_OBJ_CNT-7;
  uint8_t min_dist_for_new = 20;
  uint8_t my_difficulty = st_difficulty;
  
  if ( my_difficulty > 14 )
    my_difficulty = 14;
  min_dist_for_new -= my_difficulty;
  
  for( i = 0; i < ST_OBJ_CNT; i++ )
  {
    if ( st_objects[i].ot == ST_OT_TRASH1 || st_objects[i].ot == ST_OT_TRASH2 || st_objects[i].ot == ST_OT_GADGET  || st_objects[i].ot == ST_OT_BIG_TRASH )
    {
      cnt++;
      if ( max_x < (st_objects[i].x>>ST_FP) )
  max_x = (st_objects[i].x>>ST_FP);
    }
  }
  
  max_l = ST_AREA_WIDTH;
  max_l -= min_dist_for_new;
  
  if ( cnt < upper_trash_limit )
    if ( max_x < max_l ) 
    {
      if (  (st_difficulty >= 3)  && ((st_rnd() & 7) == 0) )
  st_NewGadget(ST_AREA_WIDTH-1, rand() & (ST_AREA_HEIGHT-1));
      else
  st_InitTrash(ST_AREA_WIDTH-1, rand() & (ST_AREA_HEIGHT-1),0 );
    }
}
void st_InitDelta(void)
{
  st_InitDeltaTrash();
  st_InitDeltaWall();
}
void st_DrawInGame(uint8_t fps)
{
  uint8_t i;
  for( i = 0; i < ST_OBJ_CNT; i++ )
      st_DrawObj(i);
  u8g2_SetDrawColor(st_u8g2, 0);
  u8g2_DrawBox(st_u8g2, 0, u8g_height_minus_one - ST_AREA_HEIGHT-3, st_u8g2->width, 4);
  u8g2_SetDrawColor(st_u8g2, 1);
  u8g2_DrawHLine(st_u8g2, 0, u8g_height_minus_one - ST_AREA_HEIGHT+1, ST_AREA_WIDTH);
  u8g2_DrawHLine(st_u8g2, 0, u8g_height_minus_one, ST_AREA_WIDTH);
  u8g2_SetFont(st_u8g2, u8g_font_4x6r);
  u8g2_DrawStr(st_u8g2, 0, u8g_height_minus_one - ST_AREA_HEIGHT, st_itoa(st_difficulty));
  u8g2_DrawHLine(st_u8g2, 10, u8g_height_minus_one - ST_AREA_HEIGHT-3, (st_to_diff_cnt>>ST_DIFF_FP)+1);
  u8g2_DrawVLine(st_u8g2, 10, u8g_height_minus_one - ST_AREA_HEIGHT-4, 3);
  u8g2_DrawVLine(st_u8g2, 10+ST_DIFF_VIS_LEN, u8g_height_minus_one - ST_AREA_HEIGHT-4, 3);
  u8g2_DrawStr(st_u8g2, ST_AREA_WIDTH-5*4-2, u8g_height_minus_one - ST_AREA_HEIGHT, st_itoa(st_player_points_delayed));
  if ( fps > 0 )
  { i = u8g2_DrawStr(st_u8g2, ST_AREA_WIDTH-5*4-2-7*4, u8g_height_minus_one - ST_AREA_HEIGHT, "FPS:");

    //dog_DrawStr(ST_AREA_WIDTH-5*4-2-7*4+i, ST_AREA_HEIGHT, font_4x6, st_itoa(fps));
    u8g2_DrawStr(st_u8g2, ST_AREA_WIDTH-5*4-2-7*4+i, u8g_height_minus_one - ST_AREA_HEIGHT, st_itoa(fps));
  }
 }

void st_Draw(uint8_t fps)
{
  switch(st_state)
  {
    case ST_STATE_PREPARE:
    case ST_STATE_IPREPARE:
      //dog_DrawStr(0, (st_u8g2->height-6)/2, font_4x6, "SpaceTrash");
      u8g2_SetFont(st_u8g2, u8g_font_4x6r);
      u8g2_SetDrawColor(st_u8g2, 1);
      //dog_DrawStrP(0, (st_u8g2->height-6)/2, font_4x6, DOG_PSTR("SpaceTrash"));
      u8g2_DrawStr(st_u8g2, 0, u8g_height_minus_one - (st_u8g2->height-6)/2, "SpaceTrash");
      //dog_SetHLine(st_u8g2->width-st_to_diff_cnt-10, st_u8g2->width-st_to_diff_cnt, (st_u8g2->height-6)/2-1);
      u8g2_DrawHLine(st_u8g2, st_u8g2->width-st_to_diff_cnt-10, u8g_height_minus_one - (st_u8g2->height-6)/2+1, 11);
      break;
    case ST_STATE_GAME:
      st_DrawInGame(fps);
      break;
    case ST_STATE_END:
    case ST_STATE_IEND:
      u8g2_SetFont(st_u8g2, u8g_font_4x6r);
      u8g2_SetDrawColor(st_u8g2, 1);
      //dog_DrawStr(0, (st_u8g2->height-6)/2, font_4x6, "Game Over");
      //dog_DrawStrP(0, (st_u8g2->height-6)/2, font_4x6, DOG_PSTR("Game Over"));
      u8g2_DrawStr(st_u8g2, 0, u8g_height_minus_one - (st_u8g2->height-6)/2, "Game Over");
      //dog_DrawStr(50, (st_u8g2->height-6)/2, font_4x6, st_itoa(st_player_points));
      u8g2_DrawStr(st_u8g2, 50, u8g_height_minus_one - (st_u8g2->height-6)/2, st_itoa(st_player_points));
      //dog_DrawStr(75, (st_u8g2->height-6)/2, font_4x6, st_itoa(st_highscore));
      u8g2_DrawStr(st_u8g2, 75, u8g_height_minus_one - (st_u8g2->height-6)/2, st_itoa(st_highscore));
      //dog_SetHLine(st_to_diff_cnt, st_to_diff_cnt+10, (st_u8g2->height-6)/2-1);
      u8g2_DrawHLine(st_u8g2, st_to_diff_cnt, u8g_height_minus_one - (st_u8g2->height-6)/2+1, 11);
      break;
  }
}
void st_SetupInGame(void)
{
  st_player_points = 0;
  st_player_points_delayed = 0;
  st_difficulty = 1;
  st_to_diff_cnt = 0;
  st_ClrObjs();
  st_NewPlayer();
}
void st_Setup(u8g2_t *u8g)
{
  st_u8g2 = u8g;
  u8g2_SetBitmapMode(u8g, 1);
  u8g_height_minus_one = u8g->height;
  u8g_height_minus_one--;
}
void st_StepInGame(uint8_t player_pos, uint8_t is_auto_fire, uint8_t is_fire)
{
  uint8_t i, j;
  uint8_t missle_mask;
  if ( player_pos < 64 )
    st_player_pos = 0;
  else if ( player_pos >= 192 )
    st_player_pos = ST_AREA_HEIGHT-2-1;
  else 
    st_player_pos = ((uint16_t)((player_pos-64)) * (uint16_t)(ST_AREA_HEIGHT-2))/128;
  st_player_pos+=1;
  for( i = 0; i < ST_OBJ_CNT; i++ )
    st_Move(i);
  for( i = 0; i < ST_OBJ_CNT; i++ )
    if ( st_objects[i].ot != 0 )
      if ( st_IsOut(i) != 0 )
  st_Disappear(i);
  for( i = 0; i < ST_OBJ_CNT; i++ )
  {
    missle_mask = st_GetMissleMask(i);
    if ( missle_mask != 0 )           /* should we apply missle handling? */
      if ( st_CalcXY(st_objects+i) != 0 )           /* yes: calculate pixel reference point (st_px_x, st_px_y) */
  for( j = 0; j < ST_OBJ_CNT; j++ )     /* has any other object been hit? */
    if ( i != j )             /* except missle itself... */
      if ( st_IsHit(j, st_px_x, st_px_y, missle_mask) != 0 )    /* let the member function decide */
      {                 /* let the member function destroy the object if required */
        st_Destroy(i);
      }
  }
  /* handle fire counter */
  st_FireStep(is_auto_fire, is_fire);
  /* fire */
  for( i = 0; i < ST_OBJ_CNT; i++ )
    st_Fire(i); 
  /* create new objects */
  st_InitDelta();
  /* increase difficulty */     
  st_to_diff_cnt++;
  if ( st_to_diff_cnt == (ST_DIFF_VIS_LEN<<ST_DIFF_FP) )
  {
    st_to_diff_cnt = 0;
    st_difficulty++;
    st_player_points += ST_POINTS_PER_LEVEL;
  }  
  /* update visible player points */
  if ( st_player_points_delayed < st_player_points )
    st_player_points_delayed++;
} 
void st_Step(uint8_t player_pos, uint8_t is_auto_fire, uint8_t is_fire)
{
  switch(st_state)
  {
    case ST_STATE_PREPARE:
      st_to_diff_cnt = st_u8g2->width-10;   /* reuse st_to_diff_cnt */
      st_state = ST_STATE_IPREPARE;
      break;
    case ST_STATE_IPREPARE:
      st_to_diff_cnt--;
      if ( st_to_diff_cnt == 0 )
      {
  st_state = ST_STATE_GAME;
  st_SetupInGame();
      }
      break;
    case ST_STATE_GAME:
      st_StepInGame(player_pos, is_auto_fire, is_fire);
      break;
    case ST_STATE_END:
      st_to_diff_cnt = st_u8g2->width-10;   /* reuse st_to_diff_cnt */
      if ( st_highscore < st_player_points)
  st_highscore = st_player_points;
      st_state = ST_STATE_IEND;
      break;
    case ST_STATE_IEND:
      st_to_diff_cnt--;
      if ( st_to_diff_cnt == 0 )
  st_state = ST_STATE_PREPARE;
      break;
  }
}
//uint8_t a;
//uint8_t b;
uint8_t yahh = 128;

void game_1()
{
 u8g2.setFont(u8g2_font_6x10_tr);
  u8g2.setFontDirection(0);
  u8g2.setFontRefHeightAll();

  st_Setup(u8g2.getU8g2());
  while(game_xx == 1)
  {
    st_Step(yahh, /* is_auto_fire */ 0, /* is_fire */ digitalRead(done_butt));
    u8g2.firstPage();
    do
    {
      st_Draw(0);
    } while( u8g2.nextPage() );
    
    if ( digitalRead(right_butt) ) {
      yahh++;
    }
    
    if ( digitalRead(left_butt) ) {
      yahh--;
    }
  }  
}
