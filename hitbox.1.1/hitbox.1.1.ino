#include <Keypad.h>
#include <Keyboard.h>

const byte ROWS = 4; //four rows
const byte COLS = 4; //three columns
char keys[ROWS][COLS] = {
  {'x','l','o', 'w'},
  {'e','k','i', 'a'},
  {'g','j','u', 's'},
  {'z','h','y', 'd'}
};
byte rowPins[ROWS] = {18, 19, 20, 21}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {9, 10, 16, 14}; //connect to the column pinouts of the keypad

Keypad kpd = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

unsigned long loopCount;
unsigned long startTime;
String msg;


void setup() {
    delay(10000);
    Serial.begin(9600);
    loopCount = 0;
    startTime = millis();
    msg = "";
    Keyboard.begin();
}


void loop() {
    loopCount++;
    if ( (millis()-startTime)>5000 ) {
        Serial.print("Average loops per second = ");
        Serial.println(loopCount/5);
        startTime = millis();
        loopCount = 0;
    }

    // Fills kpd.key[ ] array with up-to 10 active keys.
    // Returns true if there are ANY active keys.
    if (kpd.getKeys())
    {
        for (int i=0; i<LIST_MAX; i++)   // Scan the whole key list.
        {
            if ( kpd.key[i].stateChanged )   // Only find keys that have changed state.
            {
                switch (kpd.key[i].kstate) {  // Report active key state : IDLE, PRESSED, HOLD, or RELEASED
                    case PRESSED:
                    msg = " PRESSED.";
                    Keyboard.press(kpd.key[i].kchar);
                break;
                    case HOLD:
                    msg = " HOLD.";
                break;
                    case RELEASED:
                    msg = " RELEASED.";
                    Keyboard.release(kpd.key[i].kchar);
                break;
                    case IDLE:
                    msg = " IDLE.";
                }
                Serial.print("Key ");
                Serial.print(kpd.key[i].kchar);
                Serial.println(msg);
                
            }
        }
    }
}  // End loop
