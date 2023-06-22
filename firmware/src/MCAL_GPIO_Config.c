#include "../inc/MCAL_GPIO_Interface.h"

GPIO_CfgType GPIO_OUT_Config = {
		.GPIO_Mode = GPIO_MODE_OUT_PP,
		.GPIO_Speed = GPIO_SPEED_MEDIUM,
};

GPIO_CfgType GPIO_IN_Config = {
		.GPIO_Mode = GPIO_MODE_IN_PU,
};
