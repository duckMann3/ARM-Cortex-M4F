#include "tm4c123gh6pm.h"

#define ENABLE_PB6      0x40
#define 

void PortB_Init(void) {
  SYSCTL_RCGCGPIO_R1 |= ENABLE_PB6;  
  while((SYSCTL_RCGCGPIO_R1&ENABLE_PB6) != 0) {}

  GPIO_PORTB_PCTL_R  &=  0xFF000000;     // Set GPIO Function
  GPIO_PORTB_AMSEL_R &= ~ENABLE_PB6;     // Disable Analog Function
  GPIO_PORTB_DIR_R   |=  ENABLE_PB6;     // Set Output
  GPIO_PORTB_AFSEL   &= ~ENABLE_PB6;     // Regular Port Function
  GPIO_PORTB_DEN_R   |=  ENABLE_PB6;     // Set Digital Enable PB6
  GPIO_PORTB_PUR_R   |=  ENABLE_PB6;     // Set Pull Up Resistor
}

void PortB_Interrupt(void) {

}
