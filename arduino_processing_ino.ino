#include "pitches.h"
#include "Volume3.h" // Include the Volume library
#include <Ultrasonic.h>

#define speakerPin 9

int incomingData;
Ultrasonic ultrasonic(12, 13);

int noteJujuDurations[] = {       //duration of the notes
  6,2,4,4,12,4,12,4,8,8,16
  };
int melodiaJuju[]={
   NOTE_C4, NOTE_C4, NOTE_D4, NOTE_E4,  NOTE_C4, NOTE_E4, NOTE_D4, NOTE_E4, NOTE_C4, NOTE_A3, NOTE_C4, END
  };

  
  uint16_t volume = 1023;
  uint16_t frequency = 3000;
  
  void setup() {
    Serial.begin(9600);
  }
  void loop() {

  Serial.print(ultrasonic.distanceRead());
    //while(frequency != freq){
     /*if(frequency <= freq){
       freq+= 1;
       //Serial.print(ultrasonic.distanceRead());
     }
     else if(frequency >= freq){
        freq-= 1; 
        //Serial.print(ultrasonic.distanceRead());
     }*/ 
         vol.tone(speakerPin, (frequency / (ultrasonic.distanceRead()+1)), volume);
    //}
   delay(10);  
}

