/*
 * File.h
 *
 *  Created on: 2018年6月8日
 *      Author: garvin
 */

#ifndef EXP_5_FILE_H_
#define EXP_5_FILE_H_

#include <string>

using namespace std;

class file
{
private:
    string name;
	int blockstart;
	int blocknum;
	double filelength;
public:
	file(string, double);
	void setBlockstart(int);
	int getBlockstart();
	int getBlocknum();
	double getFilelength();
	string getName();
	void show();
};


#endif /* EXP_5_FILE_H_ */
