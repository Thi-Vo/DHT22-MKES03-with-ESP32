/*
 * MKES03.c
 *
 *  Created on: 27 Nov 2023
 *      Author: DLCH
 */

#include "MKES03.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#define INPUT_PIN_32	ADC1_CHANNEL_4

int converter[] = {4000,3000,2000,1000};

static esp_adc_cal_characteristics_t adc1_chars;

//read and print raw value [4095,0]
//return value through pvParameter. 5 level of brightness [1,5]. 5 is the highest
void readSensorValue(void* pvParameter){
    esp_adc_cal_characterize(ADC_UNIT_1, ADC_ATTEN_DB_11, ADC_WIDTH_BIT_DEFAULT, 0, &adc1_chars);
	adc1_config_width(ADC_WIDTH_BIT_12);
	adc1_config_channel_atten(INPUT_PIN_32, ADC_ATTEN_DB_11);

	int *return_value = (int*)pvParameter;
	while(1){
		int reading =  adc1_get_raw(INPUT_PIN_32);
		printf("%d\n",reading);
		if(reading > converter[0]){
			*return_value = 1;
		}
		else if(reading <= converter[0] && reading > converter[1]){
			*return_value = 2;
		}
		else if(reading <= converter[1] && reading > converter[2]){
			*return_value = 3;
		}
		else if(reading <= converter[2] && reading > converter[3]){
			*return_value = 4;
		}
		else *return_value = 5;

//		printf("%d\n",*return_value);
		vTaskDelay(pdMS_TO_TICKS(300));
	}
	vTaskDelete(NULL);
}
