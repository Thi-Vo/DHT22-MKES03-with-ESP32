#include <stdio.h>
#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "freertos/FreeRTOSConfig.h"

#include "MKES03.h"


int brightness_level = 1;

void app_main(void)
{
	xTaskCreate(readSensorValue, "Light", 8000, (void*)&brightness_level, 10, NULL);
}
