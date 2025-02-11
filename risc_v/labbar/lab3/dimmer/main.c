#include "gd32vf103.h"
#include "drivers.h"
#include "adc.h"
#include "pwm.h"

int StateZero(int key, int *pState);
int StateOne(int key, int *pState, int *pDimmer);
void StateTwo(int key, int *pState, int *pDimmer);

int main(void){
    int ms=0, key, s=0, pressedKey=-1, c=0, idle=0, tmpr;
    int state = 0;
    int keyOne = 0; 
    int keyTwo = 0;
    int dimmerValue = 0;
    int lookUpTbl[16]={1,4,7,14,2,5,8,0,3,6,9,15,10,11,12,13};

    t5omsi();                                     // Initialize timer5 1kHz
    colinit();                                    // Initialize column toolbox
    l88init();                                    // Initialize 8*8 led toolbox
    keyinit();                                    // Initialize keyboard toolbox
    ADC3powerUpInit(0);                           // Initialize ADC0, Ch3
    T1powerUpInitPWM(0x1);                      // Timer #1, Ch #2 & 3 PWM
    
    while (1) {
        idle++;                                   // Manage Async events

 
        if (t5expq()) {                           // Manage periodic tasks
            l88row(colset());                     // ...8*8LED and Keyboard
            ms++;                                 // ...One second heart beat
            if (ms==1000){
              ms=0;
              l88mem(0,s++);
            }

            key=keyscan();

            if (key>=0) {             // ...Any key pressed?
              pressedKey=lookUpTbl[key];
              switch (state)
              {
              case 0:
                keyOne = StateZero(pressedKey, &state);
                dimmerValue = keyOne;
                break;
              case 1:
                keyTwo = StateOne(pressedKey, &state, &dimmerValue);
                dimmerValue = keyOne*10+keyTwo;
                break;
              case 2:
                StateTwo(pressedKey, &state, &dimmerValue);
                dimmerValue= keyOne;
                break;
              
              default:
                break;
              }
            }

            l88mem(2,idle>>8);                    // ...Performance monitor
            l88mem(3,idle); idle=0;
        }
    }
}


int StateZero(int key, int *pState){
  switch (key)
  {
  case 10:
    T1setPWMch0(8000);
    break;
  case 11:
    T1setPWMch0(4000);
    break;
  case 12:
    T1setPWMch0(0);
    break;
  case 13:
  case 14:
  case 15:
    *pState=0;
    break;
  
  default:
    *pState=1;
    return key;

    break;
  }
  return 0;

}
int StateOne(int key, int *pState, int *pDimmer){
  switch (key)
  {
  case 10:
    T1setPWMch0(8000);
    *pState = 0;
    break;
  case 11:
    T1setPWMch0(4000);
    *pState = 0;
    break;
  case 12:
    T1setPWMch0(0);
    *pState = 0;
    break;
  case 13:
    T1setPWMch0(80*(*pDimmer));
    *pState=0;
    break;
  case 14:
  case 15:
    *pState=0;
    break;
  
  default:
    *pState=2;
    return key;

    break;
  }
  return 0;
}
void StateTwo(int key, int *pState, int *pDimmer){
  switch (key)
  {
  case 10:
    T1setPWMch0(8000);
    *pState = 0;
    break;
  case 11:
    T1setPWMch0(4000);
    *pState = 0;
    break;
  case 12:
    T1setPWMch0(0);
    *pState = 0;
    break;
  case 13:
    T1setPWMch0(80*(*pDimmer));
    *pState=0;
    break;
  case 14:
    *pState=1;
    break;
  case 15:
    *pState=0;
    break;
  
  default:
    break;
  }
}