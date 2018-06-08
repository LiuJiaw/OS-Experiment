/*
 * Algorithm.cpp
 *
 *  Created on: 2018年6月8日
 *      Author: garvin
 */

#include "Algorithm.h"
#include <algorithm>
#include <iostream>
#define BLOCKNUM 1024

using namespace std;

kxb::kxb(){
	this->kxbvec.push_back(kxbrow(0, BLOCKNUM));
}

vector<kxbrow>& kxb::getkxbvec()
{
	return this->kxbvec;
}

kxb* kxb::instance=new kxb();

kxb* kxb::getinstance()
{
	return instance;
}

void kxb::addfile(file* f)
{
	vector<kxbrow>::iterator item;
	for(item=this->kxbvec.begin();item!=this->kxbvec.end();item++)
	{
		if( (*item).length>=f->getBlocknum() )
		{
			(*item).length-=f->getBlocknum();
			f->setBlockstart( (*item).start );
			(*item).start+=f->getBlocknum();
			break;
		}
	}
	if(item==this->kxbvec.end())
		throw 1;
}

void kxb::removefile(file* f)
{
	vector<kxbrow>::iterator item;
	int status=0;
	for(item=this->kxbvec.begin();item!=this->kxbvec.end();item++)
	{
		if( (*item).start==f->getBlockstart()+f->getBlocknum() )
		{
			(*item).start=f->getBlockstart();
			(*item).length+=f->getBlocknum();
			status++;
		}
		else if( (*item).start+(*item).length == f->getBlockstart() )
		{
			(*item).length+=f->getBlocknum();
			status++;
		}
	}
	if(status==0)
	{
		kxbrow k=kxbrow(f->getBlockstart(), f->getBlocknum());
		this->getkxbvec().push_back(k);
		sort(this->getkxbvec().begin(), this->getkxbvec().end());
	}
}

