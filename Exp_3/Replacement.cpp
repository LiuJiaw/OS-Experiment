/*
 * Replacement.cpp
 *
 *  Created on: 2018年6月4日
 *      Author: garvin
 */
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include "Replacement.h"
#define CAPACITY 5
#define RANGE 10
#define TIME 30

using namespace std;

void ShowVector(vector<int> vec) {
	vector<int>::iterator item;
	for (item = vec.begin(); item != vec.end(); item++) {
		cout << *item << " ";
	}
	cout << endl;
}

LRU::LRU() {
	this->lruvec.reserve(CAPACITY);
	this->lruexict.resize(RANGE, false);
	this->times = 0;
}

int LRU::gettimes() {
	return this->times;
}

LRU* LRU::instance = new LRU();

LRU* LRU::getInstance() {
	return instance;
}

void LRU::Push(int num) {
	if (true == this->lruexict[num]) {
		vector<int>::iterator item;
		for (item = this->lruvec.begin(); item != this->lruvec.end(); item++) {
			if (*item == num) {
				this->lruvec.erase(item);
				this->lruvec.push_back(num);
				break;
			}
		}
	} else {
		if (this->lruvec.size() < CAPACITY) {
			this->lruvec.push_back(num);
			this->lruexict[num] = true;
		} else {
			this->lruexict[this->lruvec.front()] = false;
			this->lruexict[num] = true;
			this->lruvec.erase(this->lruvec.begin());
			this->lruvec.push_back(num);
		}
		this->times++;
	}
	cout << "LRU:";
	ShowVector(this->lruvec);
}

FIFO::FIFO() {
	this->fifovec.reserve(CAPACITY);
	this->fifoexict.resize(RANGE, false);
	this->times = 0;
}

int FIFO::gettimes() {
	return this->times;
}

FIFO* FIFO::instance = new FIFO();

FIFO* FIFO::getInstance() {
	return instance;
}

void FIFO::Push(int num) {
	if (true == this->fifoexict[num]) {

	} else {
		if (this->fifovec.size() < CAPACITY) {
			this->fifovec.push_back(num);
			this->fifoexict[num] = true;
		} else {
			this->fifoexict[this->fifovec.front()] = false;
			this->fifoexict[num] = true;
			this->fifovec.erase(this->fifovec.begin());
			this->fifovec.push_back(num);
		}
		this->times++;
	}
	cout << "FIFO:";
	ShowVector(this->fifovec);
}

void ShowInfo() {
	cout << "LRU的缺页次数为:" << LRU::getInstance()->gettimes() << "\t缺页率为"
			<< (float) LRU::getInstance()->gettimes() / TIME << endl;
	cout << "FIFO的缺页次数为:" << FIFO::getInstance()->gettimes() << "\t缺页率为"
			<< (float) FIFO::getInstance()->gettimes() / TIME << endl;
}

void ShowTimeInfo(int time, int ramnum) {
	cout << "第" << time << "次添加数据,所添加数据为" << ramnum << endl;
}

