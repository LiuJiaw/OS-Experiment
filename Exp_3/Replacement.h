/*
 * Replacement.h
 *
 *  Created on: 2018年6月4日
 *      Author: garvin
 */

#ifndef EXP_3_REPLACEMENT_H_
#define EXP_3_REPLACEMENT_H_

#include <vector>

using namespace std;

class LRU {
private:
	LRU();
	~LRU();
	LRU(const LRU&);
	LRU& operator =(const LRU&);
	vector<int> lruvec;
	vector<bool> lruexict;
	static LRU* instance;
	int times;
public:
	static LRU* getInstance();
	void Push(int);
	int gettimes();
};

class FIFO {
private:
	FIFO();
	~FIFO();
	FIFO(const FIFO&);
	FIFO& operator =(const FIFO&);
	vector<int> fifovec;
	vector<bool> fifoexict;
	static FIFO* instance;
	int times;
public:
	static FIFO* getInstance();
	void Push(int);
	int gettimes();
};

void ShowInfo();
void ShowTimeInfo(int, int);

#endif /* EXP_3_REPLACEMENT_H_ */
