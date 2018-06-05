/*
 * ProcessDispatch.cpp
 *
 *  Created on: 2018年6月3日
 *      Author: garvin
 */

#include <string.h>
#include "ProcessInfo.h"
#include "Dispatch.h"

void Dispatch::Show() {
	vector<process*>::iterator item;

	cout
			<< "*******************************************************************************************\n";

	cout << "ID          到达时间:        结束时间        服务时间        周转时间      带权周转时间"
			<< endl;

	for (item = this->ansvec.begin(); item != this->ansvec.end(); item++) {
		(*item)->Show();
	}
}

FCFS::FCFS() {}

FCFS* FCFS::instance = new FCFS();

FCFS* FCFS::getinstance() {
	return instance;
}

process* FCFS::selectnext(int time) {
	vector<process*>::iterator item;
	vector<process*>::iterator ans;
	ans = this->vec.begin();
	for (item = this->vec.begin(); item != this->vec.end(); item++) {
		if ((*item)->getArriveTime() < (*ans)->getArriveTime()) {
			ans = item;
		}
	}
	if ((*ans)->getArriveTime() > time)
		return NULL;
	return *ans;
}

SJF::SJF() {}

SJF* SJF::instance = new SJF();

SJF* SJF::getinstance() {
	return instance;
}

process* SJF::selectnext(int time) {
	vector<process*>::iterator item;
	vector<process*>::iterator ans;
	ans = this->vec.begin();
	for (item = this->vec.begin(); item != this->vec.end(); item++) {
		if ((*item)->getServiceTime() < (*ans)->getServiceTime()
				&& (*item)->getArriveTime() <= time) {
			ans = item;
		}
	}
	if ((*ans)->getArriveTime() > time)
		return NULL;
	return *ans;
}

HRN::HRN() {}

HRN* HRN::instance = new HRN();

HRN* HRN::getinstance() {
	return instance;
}

process* HRN::selectnext(int time) {
	vector<process*>::iterator item;
	vector<process*>::iterator ans;
	ans = this->vec.begin();
	for (item = this->vec.begin(); item != this->vec.end(); item++) {
		if ((*item)->getArriveTime() <= time
				&& ((double) time - (*item)->getArriveTime())
						/ (*item)->getServiceTime()
						> ((double) time - (*ans)->getArriveTime())
								/ (*ans)->getServiceTime()) {
			ans = item;
		}
	}
	if ((*ans)->getArriveTime() > time)
		return NULL;
	return *ans;
}


RR::RR() {}

RR* RR::instance = new RR();

RR* RR::getinstance() {
	return instance;
}

process* RR::selectnext(int time) {
	int num=this->q.size();
	process* ans=this->q.front();
	this->q.pop();
	while(num--)
	{
		if(ans->getArriveTime()>time)
		{
			this->q.push(ans);
			ans=q.front();
			q.pop();
			continue;
		}
		return ans;
	}
	return NULL;
}
