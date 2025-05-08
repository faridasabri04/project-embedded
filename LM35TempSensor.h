

#ifndef LM35_SENSOR_H_
#define LM35_SENSOR_H_

#include "std_types.h"


#define TEMP_THRESHOLD_1  25  // 25°C
#define TEMP_THRESHOLD_2  30  // 30°C
#define TEMP_THRESHOLD_3  35  // 35°C
#define TEMP_THRESHOLD_4  40  // 40°C


#define SENSOR_CHANNEL_ID         1
#define SENSOR_MAX_VOLT_VALUE     1.5
#define SENSOR_MAX_TEMPERATURE    150


uint8 LM35_getTemperature(void);

#endif /* LM35_SENSOR_H_ */

