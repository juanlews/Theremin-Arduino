#include "pitches.h"
#include "Volume3.h" // Include the Volume library
#include <Ultrasonic.h>

#define speakerPin 9
#define ledPin 5
//int incomingData;
Ultrasonic ultrasonicFreq(12, 13);
Ultrasonic ultrasonicVolume(11, 10);


/*int noteJujuDurations[] = {       //duration of the notes
  6,2,4,4,12,4,12,4,8,8,16
  };
int melodiaJuju[]={
   NOTE_C4, NOTE_C4, NOTE_D4, NOTE_E4,  NOTE_C4, NOTE_E4, NOTE_D4, NOTE_E4, NOTE_C4, NOTE_A3, NOTE_C4, END
  };
*/
  
  uint16_t volume = 20;
  uint16_t frequency = 4186;
  bool testado = false;
  
  void setup() {
     Serial.begin(9600);
  }
  void loop() {
  
  while(!testado){
     testaComponentes();
  } 
  Serial.print("\n frequencia: ");
  Serial.print(frequency);//ultrasonicFreq.distanceRead());
  Serial.print("\n Volume: ");
  // analogWrite(3, constrain((5 *(ultrasonicVolume.distanceRead())), 0, 100));
  Serial.println(constrain((20 *(ultrasonicVolume.distanceRead())), 0, 255));
   
  toca(frequency = constrain((30*(ultrasonicFreq.distanceRead())),0, 4186), constrain((20 *(ultrasonicVolume.distanceRead())), 0, 255));
  
}
void toca(uint16_t freq, float volume){
  if(freq != NULL){
     vol.tone(speakerPin, freq, volume); 
  }
}
void testaComponentes(){
  for (int i=0; i<4186; i++){
   vol.tone(speakerPin, i, 255);
   delay(1);   
  }
  delay(200);
  for (int i=0; i<255; i++){
   vol.tone(speakerPin, 3000, i);
   delay(10);   
  }
  delay(500);
  for (int i=255; i>0; i--){
   vol.tone(speakerPin, 3000, i);
   delay(10);   
  }
  
  delay(200);
  testado=true;
  vol.noTone();
}
