/*
 * SSTFHead.h
 *
 *  Created on: 2018年6月4日
 *      Author: garvin
 */

#ifndef EXP_4_SSTFHead_H_
#define EXP_4_SSTFHead_H_

#include <vector>
#include <stdlib.h>
#include <iostream>

using namespace std;

class SSTFHead {
private:
	SSTFHead();
	~SSTFHead();
	SSTFHead(const SSTFHead&);
	SSTFHead& operator =(const SSTFHead&);
	int location;
	bool direction;
	static SSTFHead* instance;
public:
	int getlocation();
	bool getdirection();
	void tolocation(int);
	void tolocation(int, vector<int>&);
	int selectnext(int, vector<int>);
	static SSTFHead* getinstance();
};

class SCANHead {
private:
	SCANHead();
	~SCANHead();
	SCANHead(const SCANHead&);
	SCANHead& operator =(const SCANHead&);
	int location;
	bool direction;
	static SCANHead* instance;
public:
	int getlocation();
	bool getdirection();
	void tolocation(int);
	void tolocation(int, vector<int>&);
	void setdirection(bool);
	int selectnext(int, vector<int>);
	static SCANHead* getinstance();
};

#endif /* EXP_4_SSTFHead_H_ */
