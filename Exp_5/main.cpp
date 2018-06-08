/*
 * main.cpp
 *
 *  Created on: 2018年6月8日
 *      Author: garvin
 */

#include "File.h"
#include "Algorithm.h"
#include <stdlib.h>
#include <iostream>
#include <sstream>

#define FILE_NUM 50
#define BLOCK_NUM 1024

using namespace std;

void createFile(vector<file*>&);
void removeFile(vector<file*>&);
void createOtherFile(vector<file*>&);
void ShowFile(vector<file*>);
void Show(vector<kxbrow>);

int main() {
	vector<file*> fvec;
	kxb* instance = kxb::getinstance();
	createFile(fvec);
	ShowFile(fvec);
	Show(instance->getkxbvec());
	removeFile(fvec);
	ShowFile(fvec);
	Show(instance->getkxbvec());
	createOtherFile(fvec);
	ShowFile(fvec);
	Show(instance->getkxbvec());
	return 0;
}

string to_string(int i)
{
	ostringstream stream;
	stream<<i;
	return stream.str();
}

void createFile(vector<file*>& v) {
	kxb* instance = kxb::getinstance();
	for (int i = 1; i <= FILE_NUM; i++) {
		double len = (double)(random() % 90 + 10)/10;
		string name=to_string(i)+".txt";
		file* f = new file(name, len);
		v.push_back(f);
		instance->addfile(f);
	}
}

void removeFile(vector<file*>& fvec) {
	kxb* instance = kxb::getinstance();
	vector<file*>::iterator item;
	for (item = fvec.begin(); item != fvec.end(); item++) {
		string name=(*item)->getName();
		if ( (name[1]=='.'&&(name[0]-'0')%2) || (name[2]=='.'&&(name[1]-'0')%2) ) {
			instance->removefile(*item);
			fvec.erase(item);
			item--;
		}
	}
}

void createOtherFile(vector<file*>& fvec) {
	kxb* instance = kxb::getinstance();
	file* f1 = new file("A.txt", 7);
	file* f2 = new file("B.txt", 5);
	file* f3 = new file("C.txt", 2);
	file* f4 = new file("D.txt", 9);
	file* f5 = new file("E.txt", 3.5);
	instance->addfile(f1);
	fvec.push_back(f1);
	instance->addfile(f2);
	fvec.push_back(f2);
	instance->addfile(f3);
	fvec.push_back(f3);
	instance->addfile(f4);
	fvec.push_back(f4);
	instance->addfile(f5);
	fvec.push_back(f5);
}

void ShowFile(vector<file*> fvec)
{
	vector<file*>::iterator item;
	for(item=fvec.begin();item!=fvec.end();item++)
	{
		(*item)->show();
	}
	cout<<endl;
}

void Show(vector<kxbrow> v)
{
	bool status[BLOCK_NUM];
	for(int i=0;i<BLOCK_NUM;i++)
		*(status+i)=false;
	vector<kxbrow>::iterator item;
	for(item=v.begin();item!=v.end();item++)
	{
		int len=(*item).length;
		int start=(*item).start;
		while(len--)
			*(status+start+len-1)=true;
	}
	for(int i=0;i<BLOCK_NUM/4;i++)
	{
		if(i%32==0)
			cout<<"||";
		if(*(status+i)==false)
			cout<<"* ";
		else
			cout<<"  ";
		if(i%32==31)
			cout<<"||\n";
	}
}

