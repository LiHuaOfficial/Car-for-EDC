#include "OpticalSensor.h"

uint8_t OpticalSensor_getLevel(uint16_t OPTICAL_PIN){
    return HAL_GPIO_ReadPin(OPTICAL_PIN_PORT,OPTICAL_PIN);
}

void OpticalSensor_CheckAll(void){
    printf("X1:%d X2:%d X3:%d X4 %d\n",OpticalSensor_getLevel(OPTICAL_PIN_X1),OpticalSensor_getLevel(OPTICAL_PIN_X2),
                                    OpticalSensor_getLevel(OPTICAL_PIN_X3),OpticalSensor_getLevel(OPTICAL_PIN_X4));
}


