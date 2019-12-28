#include "FastLED.h"
#define DATA_PIN 3
#define LED_TYPE WS2812B
#define COLOR_ORDER GRB
#define NUM_LEDS 150
#define BRIGHTNESS 40
CRGB leds[NUM_LEDS];
void setup() {
  // put your setup code here, to run once:
   delay(3000); // initial delay of a few seconds is recommended
  FastLED.addLeds<LED_TYPE,DATA_PIN,COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip); // initializes LED strip
  FastLED.setBrightness(BRIGHTNESS);// global brightness

}
boolean ifOdd(int i){
  if (i%2 != 0){
    return true;
  }
  return false;
}
//switches off all leds
void showProgramCleanUp(long delayTime) {
  for (int i = 0; i < NUM_LEDS; ++i) {
    leds[i] = CRGB::Black;
  }
  FastLED.show();
  delay(delayTime);
}
void colorSwitch(CRGB color1, CRGB color2, long delayTime,int num) {
  for (int n=num; n>0; n--){
  
  for (int i = 0; i < NUM_LEDS; ++i) {
    leds[i] = color1;
  }
  FastLED.show();
  delay(delayTime);
    for (int i = 0; i < NUM_LEDS; ++i) {
    leds[i] = color2;
  }
  FastLED.show();
  delay(delayTime);
}
}

  //takes to color lights and makes them follow each other. 
    //varibles needed: 2 colors, time between flashes, number of lights same color, 
    void follow( CRGB color1, CRGB color2,  long delayTime){
   CRGB newPixel = CRGB::Black;
   for (int i = 0; i < NUM_LEDS; ++i) { 
    if(ifOdd(i)==true){
      newPixel = color2;
    }
    else if (ifOdd(i)== false){
      newPixel= color1;
    }
     for (int j = i; j > 0; --j) {
      leds[j] = leds[j-1];
    }
    leds[0] = newPixel;
    FastLED.show();
    delay(delayTime);
   }
   
  }

  
    
    
    
  //flashes 2 differnt colors in alternating paterns 
    //varibles needed: 2 colors, time between flashes, number of lights same color, overall time
    void checkerFlashD( CRGB color1, CRGB color2,  long timeDelay){
 
    double delayTime = timeDelay;
    while (delayTime > 50){
       for (int i = 0; i < NUM_LEDS; ++i) { 
       
    if(ifOdd(i)==true){
     leds[i] = color2;
    }
    else if (ifOdd(i)== false){
      leds[i]= color1;
    }
      
       }
    FastLED.show();
   delay(delayTime);
   showProgramCleanUp(10);
   
     for (int i = 0; i < NUM_LEDS; ++i) { 
       
    if(ifOdd(i)==true){
     leds[i] = color1;
    }
    else if (ifOdd(i)== false){
  leds[i]= color2;
    }
     
       }
     FastLED.show();
   delay(delayTime);
   showProgramCleanUp(10);
    delayTime = delayTime*.25;
    }
    }
   void checkerFlash( CRGB color1, CRGB color2,  long delayTime, int num){
 
 for (int n = num; n>0; --n) {
       for (int i = 0; i < NUM_LEDS; ++i) { 
       
    if(ifOdd(i)==true){
     leds[i] = color2;
    }
    else if (ifOdd(i)== false){
      leds[i]= color1;
    }
      
       }
    FastLED.show();
   delay(delayTime);
   showProgramCleanUp(10);
   
     for (int i = 0; i < NUM_LEDS; ++i) { 
       
    if(ifOdd(i)==true){
     leds[i] = color1;
    }
    else if (ifOdd(i)== false){
  leds[i]= color2;
    }
     
       }
     FastLED.show();
   delay(delayTime);
   showProgramCleanUp(10);

    }
    }
// follows then follows back
void backwards (  long delayTime){

   for (int i = NUM_LEDS; i > 0; --i) { 
   
    leds[i] = CRGB::Black;
    FastLED.show();
    delay(delayTime);
   }
}
  void coil ( CRGB color1, CRGB color2,  long delayTime){
  follow(color1, color2, delayTime);
  backwards(delayTime);

  
}
   
  // has two lights chase eachother 
     //varibles needed: 2 colors, time between flashes, number of lights same color, overall time
     
  // one color  and makes it pulse 
     //varibles needed: 1 colors, time between flashes, number of lights same color, min and max brightness, overall time
     
  //checkers the lights
      //varibles needed: 2 colors, time, number of lights same color
      
  //checkers lights and pulses them
     //varibles needed: 1 colors, time between flashes, number of lights same color, min and max brightness, overall time
     
  //one color wave
    //varibles needed: 1 colors, time between flashes, number of lights same color, min and max brightness, overall time
    
  //one color shooting star
    //varibles needed: 1 colors, time between flashes, number of lights same color, min and max brightness, overall time
    
  // two color shooting star
    //varibles needed: 2 colors, time between flashes, number of lights same color, min and max brightness, overall time
  

  //Functions that do everything with 2 colors
  void show(CRGB color1,CRGB color2){
     showProgramCleanUp(1000);
    checkerFlashD( color1, color2,  1500);
    coil (color1, color2, 100);
    checkerFlash( color1, color2,  500,10);
  }
  
  //functions that do one tast with differnt color combos
  

void loop() {
  // put your main code here, to run repeatedly:
   checkerFlash(CRGB::Blue,CRGB::Red,  500, 5);
    colorSwitch(CRGB::Blue,CRGB::Red,  500, 5);
    
   checkerFlash(CRGB::Blue,CRGB::Yellow,  500,5);
     colorSwitch(CRGB::Blue,CRGB::Yellow,  500,5);
   
    
    checkerFlash(CRGB::Yellow,CRGB::Red,  500,5);
      colorSwitch(CRGB::Yellow,CRGB::Red,  500,5);
    
    checkerFlash(CRGB::Blue,CRGB::Orange,  500,5);
      colorSwitch(CRGB::Blue,CRGB::Orange,  500,5);
    
    checkerFlash(CRGB::Green,CRGB::Red,  500,5);
     colorSwitch (CRGB::Green,CRGB::Red,  500,5);
    
  checkerFlash(CRGB::Purple,CRGB::Yellow,  500,5);
    colorSwitch(CRGB::Purple,CRGB::Yellow,  500,5);
  
    checkerFlash(CRGB::Red,CRGB::White,  500,5);
      colorSwitch(CRGB::Red,CRGB::White,  500,5);
    
   checkerFlash(CRGB::Orange,CRGB::White,  500,5);
   colorSwitch  (CRGB::Orange,CRGB::White,  500,5);
   
  checkerFlash(CRGB::Yellow,CRGB::White,  500,5);
   colorSwitch (CRGB::Yellow,CRGB::White,  500,5);
  
    checkerFlash(CRGB::Green,CRGB::White,  500,5);
      colorSwitch(CRGB::Green,CRGB::White,  500,5);
    
  checkerFlash(CRGB::Blue,CRGB::White,  500,5);
    colorSwitch(CRGB::Blue,CRGB::White,  500,5);
  
    checkerFlash(CRGB::Purple,CRGB::White,  500,5);
     colorSwitch (CRGB::Purple,CRGB::White,  500,5);
    
 checkerFlash(CRGB::Green,CRGB::Yellow,  500,5);
   colorSwitch(CRGB::Green,CRGB::Yellow,  500,5);
 
 checkerFlash(CRGB::Black,CRGB::Yellow,  500,5);
 (CRGB::Black,CRGB::Yellow,  500,5);
 
   checkerFlash(CRGB::Orange,CRGB::Maroon,  500,5);
   colorSwitch  (CRGB::Orange,CRGB::Maroon,  500,5);
   
   checkerFlash(CRGB::Red,CRGB::White,  500,5);
    colorSwitch (CRGB::Red,CRGB::White,  500,5);

   
    coil(CRGB::Blue,CRGB::Red,75);
   coil(CRGB::Blue,CRGB::Yellow,75);
 coil(CRGB::Yellow,CRGB::Red,75);
 coil(CRGB::Blue,CRGB::Orange,75);
   coil(CRGB::Green,CRGB::Red,75);
 coil(CRGB::Purple,CRGB::Yellow,75);
 coil(CRGB::Red,CRGB::White,75);
 coil(CRGB::Orange,CRGB::White,75);
 coil(CRGB::Yellow,CRGB::White,75);
  coil(CRGB::Green,CRGB::White,75);
  coil(CRGB::Blue,CRGB::White,75);
    coil(CRGB::Purple,CRGB::White,75);
  coil(CRGB::Green,CRGB::Yellow,75);
 coil(CRGB::Black,CRGB::Yellow,75);
 coil(CRGB::Orange,CRGB::Maroon,75);
 coil(CRGB::Red,CRGB::White,75);

 
   

}
