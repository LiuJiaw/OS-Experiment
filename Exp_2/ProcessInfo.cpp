/*
 * ProcessInfo.cpp
 *
 *  Created on: 2018年6月3日
 *      Author: garvin
 */
#include "ProcessInfo.h"

using namespace std;

process::process(int ID, int ArriveTime, int ServiceTime) {
	this->ID = ID;
	this->ArriveTime = ArriveTime;
	this->ServiceTime = ServiceTime;
	this->FinishTime = ArriveTime;
	this->LeftTime = ServiceTime;
}

void process::run() {
	this->LeftTime--;
}

void process::setFinishTime(int time) {
	this->FinishTime = time;
}

int process::getArriveTime() {
	return this->ArriveTime;
}

int process::getServiceTime() {
	return this->ServiceTime;
}

int process::getFinishTime() {
	return this->FinishTime;
}

int process::getTATime() {
	return this->FinishTime - this->ArriveTime;
}

double process::getATATime() {
	return ((double) this->FinishTime - this->ArriveTime) / this->ServiceTime;
}

bool process::IsFinish() {
	return this->LeftTime == 0;
}

void process::Show() {
	cout << this->ID << "\t\t" << this->getArriveTime() << "\t\t"
			<< this->getFinishTime() << "\t\t" << this->getServiceTime()
			<< "\t\t" << this->getTATime() << "\t\t" << this->getATATime()
			<< endl;
}

