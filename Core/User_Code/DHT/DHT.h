/*
 * DHT.h
 *
 *  Created on: Jun 28, 2020
 *      Author: Controllerstech.com
 */

#ifndef DHT_H_
#define DHT_H_
#include <stdbool.h>


typedef struct
{
	float Temperature;
	float Humidity;
}DHT_DataTypedef;


bool DHT_GetData (DHT_DataTypedef *DHT_Data);

#endif /* INC_DHT_H_ */
