/*
 * main.cpp
 *
 *  Created on: 2018年6月4日
 *      Author: garvin
 */

#include <time.h>
#include <algorithm>
#include "Head.h"

#define RANGE 100
#define TIME 10

using namespace std;

void getram(vector<int>&, vector<int>&);
void SSTF(vector<int>&);
void SCAN(vector<int>&);

int main() {
	vector<int> SSTFramnum;
	vector<int> SCANramnum;
	getram(SSTFramnum, SCANramnum);
	SSTF(SSTFramnum);
	SCAN(SCANramnum);
}

void getram(vector<int>& ramnum, vector<int>& ramnum1) {
	srand((unsigned) time(NULL));
	for (int i = 0; i < TIME; i++) {
		int ram = random() % RANGE;
		ramnum.push_back(ram);
		ramnum1.push_back(ram);
	}
	sort(ramnum.begin(), ramnum.end());
	sort(ramnum1.begin(), ramnum1.end());
}

void SSTF(vector<int>& ramnum) {
	SSTFHead* SSTFins = SSTFHead::getinstance();
	int distance=0;
	SSTFins->tolocation(RANGE / 2);
	cout << "*****************SSTF:********************" << endl;
	while (ramnum.size()) {
		int loc = SSTFins->selectnext(SSTFins->getlocation(), ramnum);
		cout << "当前所处位置:" << SSTFins->getlocation() << "\t下一处位置:" << loc
				<< endl;
		distance+= abs(loc-SSTFins->getlocation());
		SSTFins->tolocation(loc, ramnum);
	}
	cout<<"磁头总移动距离为:"<<distance<<endl;
}

void SCAN(vector<int>& ramnum) {
	SCANHead* SCANins = SCANHead::getinstance();
	int distance=0;
	SCANins->tolocation(RANGE / 2);
	cout << "*****************SCAN:********************" << endl;
	while (ramnum.size()) {
		int loc = SCANins->selectnext(SCANins->getlocation(), ramnum);
		cout << "当前所处位置:" << SCANins->getlocation() << "\t下一处位置:" << loc
				<< endl;
		distance+=abs(loc-SCANins->getlocation());
		SCANins->tolocation(loc, ramnum);
	}
	cout<<"磁头总移动距离为:"<<distance<<endl;
}
