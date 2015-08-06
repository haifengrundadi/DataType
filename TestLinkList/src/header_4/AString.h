/*
 * AString.h
 *
 *  Created on: 2015年8月2日
 *      Author: juanecho
 */

#ifndef HEADER_4_ASTRING_H_
#define HEADER_4_ASTRING_H_
#define defaultSize = 128;
#include<iostream>
#include<string.h>
using namespace std;

class AString
{
public:
	AString(int sz);
	AString(const char* init);
	AString(const AString& ob);
	~AString(){delete []ch;}
	int Length()const{return curLength;}
	AString& operator()(int pos,int len);
	int operator==(AString& ob)const{return strcmp(ch,ob.ch)==0;}
	int operator != (AString& ob)const{return strcmp(ch, ob.ch) != 0;}
	int operator!()const{return curLength == 0;}
	AString& operator=(AString& ob);
	AString& operator+=(AString& ob);
	char& operator[](int i);
	int Find(AString& pat)const;
private:
	char* ch;
	int curLength;
	int maxSize;
};

AString::AString(int sz)
{
	maxSize = sz;
	ch = new char[maxSize + 1];
	if(ch == NULL)
	{
		cerr<<"error"<<endl;
		exit(1);
	}
	curLength = 0;
	ch[0] = '\0';
}

AString::AString(const char*init)
{
	int len = strlen(init);
	maxSize = len > defaultSize?len:defaultSize;
	ch = new char[maxSize + 1];
	if(ch == NULL)
	{
		cerr<<"Allocation error\n";
		exit(1);
	}
	curLength = len;
	strcpy(ch,init);
}

#endif /* HEADER_4_ASTRING_H_ */
