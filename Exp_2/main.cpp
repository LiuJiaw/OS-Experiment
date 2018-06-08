/*
 * main.cpp
 *
 *  Created on: 2018年6月3日
 *      Author: garvin
 */

#include <stdlib.h>
#include <time.h>
#include "Dispatch.h"

#define NUM 10
#define ARRIVERANGE 10
#define SERVICERANGE 10

using namespace std;

void createRamProcess();
void Do();
void ShowProcess();
void Erase(process*, vector<process*>&);

int main() {
	//创造10个随机进程信息
	createRamProcess();
	//分别使用各种进程调度机制
	Do();
	//展示进程信息
	ShowProcess();

	return 0;
}

void createRamProcess() {
	srand((unsigned) time(NULL));
	FCFS* fcfsins = FCFS::getinstance();
	RR* rrins = RR::getinstance();
	SJF* sjfins = SJF::getinstance();
	HRN* hrnins = HRN::getinstance();
	for (int i = 0; i < NUM; i++) {
		int arriveram = random() % ARRIVERANGE;
		int serviceram = random() % SERVICERANGE + 1;
		process* tmp1 = new process(i, arriveram, serviceram);
		fcfsins->vec.push_back(tmp1);
		process* tmp2 = new process(i, arriveram, serviceram);
		rrins->q.push(tmp2);
		process* tmp3 = new process(i, arriveram, serviceram);
		sjfins->vec.push_back(tmp3);
		process* tmp4 = new process(i, arriveram, serviceram);
		hrnins->vec.push_back(tmp4);
	}
}

void FCFSDo() {
	FCFS* fcfsins = FCFS::getinstance();
	int time = 0;
	while (fcfsins->vec.size()) {
		process* next = fcfsins->selectnext(time);
		if (next != NULL) {
			time += next->getServiceTime();
			next->setFinishTime(time);
			fcfsins->ansvec.push_back(next);
			Erase(next, fcfsins->vec);
		} else {
			time++;
		}
	}
}

void SJFDo() {
	SJF* sjfins = SJF::getinstance();
	int time = 0;
	while (sjfins->vec.size()) {
		process* next = sjfins->selectnext(time);
		time++;
		if (next == NULL) {
			continue;
		}
		next->run();
		if (next->IsFinish()) {
			next->setFinishTime(time);
			sjfins->ansvec.push_back(next);
			Erase(next, sjfins->vec);
		}
	}
}

void HRNDo() {
	HRN* HRNins = HRN::getinstance();
	int time = 0;
	while (HRNins->vec.size()) {
		process* next = HRNins->selectnext(time);
		time++;
		if (next == NULL) {
			continue;
		}
		next->run();
		if (next->IsFinish()) {
			next->setFinishTime(time);
			HRNins->ansvec.push_back(next);
			Erase(next, HRNins->vec);
		}
	}
}

void RRDo() {
	RR* RRins = RR::getinstance();
	int time = 0;
	while (RRins->q.size()) {
		process* next = RRins->selectnext(time);
		time++;
		if (next == NULL) {
			continue;
		}
		next->run();
		if (next->IsFinish()) {
			next->setFinishTime(time);
			RRins->ansvec.push_back(next);
		}
		else
		{
			RRins->q.push(next);
		}
	}
}

void Do() {
	FCFSDo();
	RRDo();
	SJFDo();
	HRNDo();
}

void ShowProcess() {
	FCFS* fcfsins = FCFS::getinstance();
	fcfsins->Show();
	RR* rrins = RR::getinstance();
	rrins->Show();
	SJF* sjfins = SJF::getinstance();
	sjfins->Show();
	HRN* hrnins = HRN::getinstance();
	hrnins->Show();
}

void Erase(process* pro, vector<process*>& vec) {
	vector<process*>::iterator item;
	for (item = vec.begin(); item != vec.end(); item++) {
		if (pro == *item) {
			vec.erase(item);
			break;
		}
	}
}
