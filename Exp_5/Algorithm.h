/*
 * Algorithm.h
 *
 *  Created on: 2018年6月8日
 *      Author: garvin
 */

#ifndef EXP_5_ALGORITHM_H_
#define EXP_5_ALGORITHM_H_

#include <vector>
#include "File.h"

using namespace std;

struct kxbrow
{
	int start;
	int length;
public:
	kxbrow(int s,int l)
	{
		this->start=s, this->length=l;
	}
	bool operator < (const kxbrow& k)
	{
		if(this->start<k.start)
			return true;
		return false;
	}
};

class kxb
{
private:
	kxb();
	~kxb();
	kxb(const kxb&);
	kxb& operator = (const kxb&);
	vector<kxbrow> kxbvec;
	static kxb* instance;
public:
	static kxb* getinstance();
	vector<kxbrow>& getkxbvec();
	void addfile(file*);
	void removefile(file*);

};

#endif /* EXP_5_ALGORITHM_H_ */
