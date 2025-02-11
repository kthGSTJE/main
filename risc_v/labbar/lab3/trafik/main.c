#include "gd32vf103.h"
#include "drivers.h"
#include "adc.h"
#include "pwm.h"

#define LENGTH 64
#define ROAD 7

void DecodeADC(int *pAdcr);
void DisplayScore(int score);

int main(void){
    int ms=0, s=0, key, pKey=-1, c=0, idle=0, adcr, tmpr;
    int delay = 500;
    int shift = 1;
    int dead = 0;
    int lookUpTbl[16]={1,4,7,14,2,5,8,0,3,6,9,15,10,11,12,13};
    int traffic[LENGTH]={
      0xAB,0xAB,0x00,0x00,0x00,0x00,0xC3,0xC3,
      0xC3,0xC3,0x00,0x00,0xF0,0xF0,0xF0,0xF0,
      0x00,0x00,0x0F,0x0F,0x0F,0x0F,0x00,0x00,
      0xA5,0xA5,0xA5,0xA5,0x00,0x00,0xD9,0xD9,
      0xD9,0xD9,0x00,0x00,0xC1,0xC1,0xC1,0xC1,
      0x00,0x00,0x44,0x44,0x44,0x44,0x00,0x00,
      0x7E,0x7E,0x7E,0x7E,0x00,0x00,0xAB,0xAB,
      0xAB,0xAB,0x00,0x00,0x00,0x00,0x00,0x00};

    t5omsi();                                     // Initialize timer5 1kHz
    colinit();                                    // Initialize column toolbox
    l88init();                                    // Initialize 8*8 led toolbox
    keyinit();                                    // Initialize keyboard toolbox
    ADC3powerUpInit(0);                           // Initialize ADC0, Ch3

    while (1) {
        idle++;                                   // Manage Async events

        if (adc_flag_get(ADC0,ADC_FLAG_EOC)==SET) { // ...ADC done?
            adcr = adc_regular_data_read(ADC0);   // ......get data
                               // ......(view each ms)
            adc_flag_clear(ADC0, ADC_FLAG_EOC);   // ......clear IF
        }
 
        if (t5expq()) {                           // Manage periodic tasks
            l88row(colset());                     // ...8*8LED and Keyboard
            ms++;                                 // ...One second heart beat
            DecodeADC(&adcr);
            l88mem(7,adcr); 
            if (dead)
            {
                DisplayScore(s);
            }
            
            else
            {
              if (ms%delay==0)
              {
                //display road
                for (int i = 0; i < ROAD; i++)
                {
                  l88mem(i, traffic[LENGTH-(shift+ROAD-1-i)]);
                }
                //crash check
                if ((adcr|traffic[LENGTH-shift+1]) == traffic[LENGTH-shift+1])
                {
                  dead=1;
                }
                //if road done loop
                if (shift+6>LENGTH)
                {
                  shift = 3;
                }
                else {
                  shift++;
                }
              }
              
              if (ms==1000){
                ms=0;
                s++;
                if (delay>50)
                {
                  delay -= 10;
                }
              }
            }
            
            
            /*
            l88mem(2,idle>>8);                    // ...Performance monitor
            l88mem(3,idle); idle=0;*/
            adc_software_trigger_enable(ADC0,     //Trigger another ADC conversion!
                                        ADC_REGULAR_CHANNEL);
        }
    }
}

void DecodeADC(int *pAdcr){
  int demuxVal =0;
  demuxVal = *pAdcr/512;
  switch (demuxVal)
  {
  case 0:
    *pAdcr=0x01;
    break;
  case 1:
    *pAdcr=0x02;
    break;
  case 2:
    *pAdcr=0x04;
    break;
  case 3:
    *pAdcr=0x08;
    break;
  case 4:
    *pAdcr=0x10;
    break;
  case 5:
    *pAdcr=0x20;
    break;
  case 6:
    *pAdcr=0x40;
    break;
  case 7:
    *pAdcr=0x80;
    break;
  default:
    *pAdcr= 0;
    break;
  }
}
void DisplayScore(int score){
  for (int i = 0; i < ROAD; i++)  
    {
      if (i==3){
          l88mem(3, score);
      }
      else{
        l88mem(i, 0x00);
      }         
    }
}