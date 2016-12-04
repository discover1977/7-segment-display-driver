/*
 * main.c
 *
 *  Created on: 3 дек. 2016 г.
 *      Author: gavrilov.iv
 */

#include <avr/io.h>
#include <util/delay.h>
#include "SPI_Indicator.h"

int main() {
	IND_Init();
	_delay_ms(100);

	IND_OutSym("HELLO", 5);
	_delay_ms(1000);
	IND_Clear();
	_delay_ms(500);

	int16_t Cnt = -1000;

	while(1) {
		IND_OutInt(Cnt, 1, 1, 5);
		if (++Cnt == 1000) Cnt = -1000;
		_delay_ms(100);
	}
}
