/*
 * main.cpp
 *
 *  Created on: 2018年6月4日
 *      Author: garvin
 */

#include <stdlib.h>
#include <unistd.h>
#include "Replacement.h"
#define TIME 30
#define RANGE 10

int main() {
	for (int i = 0; i < TIME; i++) {
		int RamNum = random() % RANGE;
		ShowTimeInfo(i, RamNum);
		LRU::getInstance()->Push(RamNum);
		FIFO::getInstance()->Push(RamNum);
		sleep(1);
	}
	ShowInfo();
	return 0;
}

