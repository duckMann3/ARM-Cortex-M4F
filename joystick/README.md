# TM4C123GH6PM - Joystick Module
This folder contains code for interfacing a simple joystick module with the TM4C123.

## Objective
Interface a standard analog joystick module (2-axis + button). This requires ADC (Analog-to-Digital Converter) peripheral for position mapping (X/Y) and GPIO (General Purpose Input/Output) peripherals for the pushbutton.

# Design & Specifications:
* NOTE:
    * The joystick will output a voltage between 0V and 3.3V.
    * This maps to a 12-bit value of 0 - 4095.
* **Analog Pin:*** PE3 & PE2
* **GPIO Pin:** PB6
# Design Notes:
## 1. Joystick Pins:
*For personal learning & design planning*
1. GND
2. 5V
3. V_RX
4. V_RY
5. SW
## 2. Analog Joystick Positions (X & Y-axes):
* **ADC0 or ADC1** (12-bit resolution, 0-4095 Range)
* **Pins:** Analog Pins *AIN0-AIN11* (i.e: PE3, PE2, PE1, or PE0)
* **Key Registers:**
    * `SYSCTL_RCGCADC:` Enable the clock for the ADC module.
    * `SYSCTL_RCGCPGIO_R:` Enable the clock for GPIO port.
    * `GPIO_PORTE_AFSEL_R:` Set the pins to Alternate Function (analog).
    * `GPIO_PORTE_AMSEL_R:` Disables digital function & enables analog function (set bits to 1).
    * `ADC0_ACTSS_R:` Disables the ADC sequencer during configuration (i.e: SS3 for 1 channel or SS2 for 4 channels).
    * `ADC0_EMUX_R:` Sets the trigger source (i.e: processor-trigger or timer).
    * `ADC0_SSMUX3/2_R:` Selects the input channels (AIN).
    * `ADC0_SSCTL3/2_R:` Configures sample control (end of sequence, interrupts).
    * `ADC0_PSSI_R:` Initiates the conversion.
    * `ADC0_SSFIFO3/2_R:` Reads the 12-bit digital result.
     
## 3. Pushbutton:
* GPIO: Port B, Pin 6 (SW Pin)
* **Key Registers:**
    * `SYSCTL_RCGCGPIO_R:` Enable clock.
    * `GPIO_PORTB_DIR_R:` Set the pin direction (Input).
    * `GPIO_PORTB_PUR_R:` Enable internal pull-up resistor.
    * `GPIO_PORTB_DEN_R:` Enable the digital function of the pin.
    * `GPIO_PORTB_DATA_R:` Read status of the button.
    * Interrupt Masks: `_IS`, `_IBE`, `_IEV`, `_IM` 
