#include <Keypad.h>

const byte rows = 4; //four rows
const byte cols = 4; //three columns
char keys[rows][cols] = {
  {'1','2','3','4'},
  {'5','6','7','8'},
  {'9','a','b','c'},
  {'d','e','f','g'}
};

  byte rowPins[rows] = {9, 10, 16, 14}; //connect to the row pinouts of the keypad
  byte colPins[cols] = {18, 19, 20, 21}; //connect to the column pinouts of the keypad
  
  Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, rows, cols );


void setup() {

}

void loop() {
  char key = keypad.getKey();

  if (key != NO_KEY){
    Serial.println(key);
  }
}
