/*
 * Head.cpp
 *
 *  Created on: 2018年6月4日
 *      Author: garvin
 */

#include "Head.h"

using namespace std;

SSTFHead::SSTFHead() {
	this->location = 0;
	this->direction = false;
}

int SSTFHead::getlocation() {
	return this->location;
}

bool SSTFHead::getdirection() {
	return this->direction;
}

void SSTFHead::tolocation(int loc) {
	this->location = loc;
}

void SSTFHead::tolocation(int loc, vector<int>& vec) {
	this->location = loc;
	vector<int>::iterator item;
	for (item = vec.begin(); item != vec.end(); item++) {
		if (loc == *item) {
			vec.erase(item);
			break;
		}
	}
}

SSTFHead* SSTFHead::instance = new SSTFHead();

SSTFHead* SSTFHead::getinstance() {
	return instance;
}

int SSTFHead::selectnext(int loc, vector<int> vec) {
	int distance = abs(vec.front() - loc);
	int ans = vec.front();
	vector<int>::iterator item;
	for (item = vec.begin(); item != vec.end(); item++) {
		if (distance > abs(*item - loc)) {
			distance = abs(*item - loc);
			ans = *item;
		}
	}
	return ans;
}

SCANHead::SCANHead() {
	this->location = 0;
	this->direction = false;
}

int SCANHead::getlocation() {
	return this->location;
}

bool SCANHead::getdirection() {
	return this->direction;
}

void SCANHead::tolocation(int loc) {
	this->location = loc;
}

void SCANHead::tolocation(int loc, vector<int>& vec) {
	this->location = loc;
	vector<int>::iterator item;
	for (item = vec.begin(); item != vec.end(); item++) {
		if (loc == *item) {
			vec.erase(item);
			break;
		}
	}
}

void SCANHead::setdirection(bool bol) {
	this->direction = bol;
}

int SCANHead::selectnext(int loc, vector<int> vec) {
	vector<int>::iterator item;
	int ans=-1;
	while (-1 == ans) {
		if (false == this->getdirection()) {
			for (item = vec.end()-1; item != vec.begin()-1; item--) {
				if (*item <= loc) {
					ans = *item;
					return ans;
				}
			}
			this->setdirection(true);
		} else {
			for (item = vec.begin(); item != vec.end(); item++) {
				if (*item >= loc) {
					ans = *item;
					return ans;
				}
			}
			this->setdirection(false);
		}
	}
}

SCANHead* SCANHead::instance = new SCANHead();

SCANHead* SCANHead::getinstance() {
	return instance;
}

