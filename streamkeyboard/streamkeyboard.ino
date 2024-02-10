/*
 *  Project     'Stream Cheap' Mini Macro Keyboard
 *  @author     David Madison
 *  @link       partsnotincluded.com/electronics/diy-stream-deck-mini-macro-keyboard
 *  @license    MIT - Copyright (c) 2018 David Madison
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 *
 */
#include <HID-Project.h>                   
#include <HID-Settings.h>


// ---------------------------------
// Key definitions
// #define BUTTON_KEY1 MEDIA_PLAY_PAUSE
// #define BUTTON_KEY2 MEDIA_PLAY_PAUSE
// #define BUTTON_KEY3 MEDIA_PLAY_PAUSE
// #define BUTTON_KEY4 MEDIA_PLAY_PAUSE
// #define BUTTON_KEY5 MEDIA_PLAY_PAUSE
// #define BUTTON_KEY6 MEDIA_PLAY_PAUSE
// #define BUTTON_KEY7 MEDIA_PLAY_PAUSE
// #define BUTTON_KEY8 MEDIA_PLAY_PAUSE
// #define BUTTON_KEY9 MEDIA_PLAY_PAUSE


// Pin definitions
#define BUTTON_PIN1 2
#define BUTTON_PIN2 3
#define BUTTON_PIN3 4
#define BUTTON_PIN4 5
#define BUTTON_PIN5 6
#define BUTTON_PIN6 7
#define BUTTON_PIN7 8
#define BUTTON_PIN8 9
#define BUTTON_PIN9 10 

// ---------------------------------


// Button helper class for handling press/release and debouncing
class button {
  public:
  const char key;
  const uint8_t pin;

  button(
    //uint8_t k, 
    uint8_t p) : 
    //key(k), 
    pin(p){}

  void press(boolean state){
    if(state == pressed || (millis() - lastPressed  <= debounceTime)){
      return; // Nothing to see here, folks
    }
    
    lastPressed = millis();
    if (state) {
      if (pin == BUTTON_PIN1) {
        Keyboard.write(KEY_1);
      }
      if (pin == BUTTON_PIN2) {
        Keyboard.write(KEY_2);
      }
      if (pin == BUTTON_PIN3) {
        Keyboard.write(KEY_3);
      }
      if (pin == BUTTON_PIN4) {
        Keyboard.write(KEY_4);
      }
      if (pin == BUTTON_PIN5) {
        Keyboard.write(KEY_5);
      }
      if (pin == BUTTON_PIN6) {
        Keyboard.write(KEY_6);
      }
      if (pin == BUTTON_PIN7) {
        Keyboard.write(KEY_7);
      }
      if (pin == BUTTON_PIN8) {
        Keyboard.write(KEY_8);
      }
      if (pin == BUTTON_PIN9) {
        Keyboard.write(KEY_9);
      }
    }
    pressed = state;
  }

  void update(){
    press(!digitalRead(pin));
  }

  private:
  const unsigned long debounceTime = 30;
  unsigned long lastPressed = 0;
  boolean pressed = 0;
} ;


void failsafe(){
  for(;;){} // Just going to hang out here for awhile :D
}