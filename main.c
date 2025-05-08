#include "avr/io.h"
#include <util/delay.h>
#include "lcd.h"
#include "led.h"
#include "adc.h"
#include "LM35TempSensor.h"
#include "LDR.h"
#include "FlameSensor.h"
#include "pwm.h"
#include "Buzzer.h"
#include "DcMotor.h"
#include "gpio.h"

int main(void) {

    // Initialize all components
    LCD_init();
    LED_init();
    ADC_init();
    FlameSensor_init();
    Buzzer_init();
    DcMotor_Init();

    uint8 flameDetected = 0;      // Flag for flame detection


    while (1)
    {
        // Read temperature and light intensity
        uint8 temperature = LM35_getTemperature();
        uint16 lightIntensity = LDR_getLightIntensity();

        LED_on();

        // Control fan speed based on temperature
		if (temperature >= TEMP_THRESHOLD_4) {
			DcMotor_Rotate(CW, 100);  // Set motor to 100% speed for temperature ≥ 40°C
		} else if (temperature >= TEMP_THRESHOLD_3) {
			DcMotor_Rotate(CW, 75);   // Set motor to 75% speed for temperature ≥ 35°C and < 40°C
		} else if (temperature >= TEMP_THRESHOLD_2) {
			DcMotor_Rotate(CW, 50);   // Set motor to 50% speed for temperature ≥ 30°C and < 35°C
		} else if (temperature >= TEMP_THRESHOLD_1) {
			DcMotor_Rotate(CW, 25);   // Set motor to 25% speed for temperature ≥ 25°C and < 30°C
		} else {
			DcMotor_Rotate(STOP, 0);  // Stop motor for temperature < 25°C
		}


        flameDetected = FlameSensor_getValue(); // Get flame sensor value

        if (flameDetected)
        {
			//Check the flame sensor
        	LCD_displayStringRowColumn(0, 0, "                "); // To clear first row
			LCD_displayStringRowColumn(1, 0, " Critical alert! ");

			Buzzer_on();  // Turn on the buzzer
        }
        else
        {
        	if (temperature >= TEMP_THRESHOLD_1)
        	{
				LCD_displayStringRowColumn(0, 0, "   FAN is ON  ");
			}
        	else
        	{
				LCD_displayStringRowColumn(0, 0, "   FAN is OFF ");
			}

			LCD_moveCursor(1, 0); // Move to the second row, first column
			LCD_displayString("Tmp="); // Display static text for temperature
			LCD_intgerToString(temperature); // Display temperature
			LCD_displayCharacter('C'); // Display the degree symbol
			LCD_moveCursor(1, 9);
			LCD_displayString("LDR="); // Display static text for LDR
			LCD_intgerToString(lightIntensity); // Display light intensity
			LCD_displayString("% "); // Display the percentage symbol

			Buzzer_off();
        }


    }

    return 0;
}
