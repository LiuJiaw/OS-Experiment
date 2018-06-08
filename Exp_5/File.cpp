/*
 * File.cpp
 *
 *  Created on: 2018年6月8日
 *      Author: garvin
 */

#include "File.h"
#include <iostream>

using namespace std;

file::file(string s, double len)
{
	this->filelength=len;
	this->blocknum = len==(int)len ? (int)len/2 : (int)len/2+1;
	this->name=s;
	this->blockstart=-1;
}

int file::getBlocknum()
{
	return this->blocknum;
}

void file::setBlockstart(int start)
{
	this->blockstart=start;
}

int file::getBlockstart()
{
	return this->blockstart;
}

string file::getName()
{
	return this->name;
}

double file::getFilelength()
{
	return this->filelength;
}

void file::show()
{
	cout<<"文件名称"<<this->getName()<<"\t\t文件起始地址:"<<this->getBlockstart()<<"\t\t文件长度:"<<this->getFilelength()<<"k\t\t文件占用盘块数"<<this->getBlocknum()<<endl;
}

