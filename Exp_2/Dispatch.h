/*
 * Dispatch.h
 *
 *  Created on: 2018年6月3日
 *      Author: garvin
 */

#include <vector>
#include <queue>
#include "ProcessInfo.h"

using namespace std;

class Dispatch {
public:
	vector<process*> vec;
	vector<process*> ansvec;
public:
	void Show();
	virtual process* selectnext(int)=0;
};

class FCFS: public Dispatch {
private:
	FCFS();
	~FCFS();
	FCFS(const FCFS&);
	FCFS& operator =(const FCFS&);
	static FCFS* instance;
public:
	static FCFS* getinstance();
	process* selectnext(int);
};

class SJF: public Dispatch {
private:
	SJF();
	~SJF();
	SJF(const SJF&);
	SJF& operator =(const SJF&);
	static SJF* instance;
public:
	static SJF* getinstance();
	process* selectnext(int);
};

class HRN: public Dispatch {
private:
	HRN();
	~HRN();
	HRN(const HRN&);
	HRN& operator =(const HRN&);
	static HRN* instance;
public:
	static HRN* getinstance();
	process* selectnext(int);
};

class RR:public Dispatch
{
private:
	RR();
	~RR();
	RR(const RR&);
	RR& operator =(const RR&);
	static RR* instance;
public:
	queue<process*> q;
public:
	static RR* getinstance();
	process* selectnext(int);
};
