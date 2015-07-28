/*
 * SeqStack.h
 *
 *  Created on: 2015年7月28日
 *      Author: juanecho
 */

#ifndef HEADER_SEQSTACK_H_
#define HEADER_SEQSTACK_H_
#include<assert.h>
#include"Stack.h"
const int stackIncrement = 20;
template <typename T>
class SeqStack:public Stack<T>{
public:
	SeqStack(int sz = 50);
	~SeqStack(){delete[] elements;}
	void Push(const T & x);
	//如果isfull，则溢出处理，否则把x插入到栈的栈顶
	bool Pop(T& x);
	//如果IsEmpty，则不执行退栈，返回false。否则，退掉栈顶的元素，并返回true。退出的引用通过参数x返回
	bool getTop(T& x);
	bool IsEmpty()const{return (top == -1)?true:false;}
	int getSize()const {return top = top+1;}
	void MakeEmpty(){top = -1;}
	//friend ostream& operator << (ostream& os, SeqStack<T>& s){

private:
	T * elements;//存放栈中元素的栈数组
	int top;  //栈顶指针
	int maxSize;
	void overflowProcess();    //栈的溢出处理
};

template<typename T>
SeqStack<T>::SeqStack(int sz):top(-1),maxSize(sz)
{
	elements = new T[maxSize];
	assert(elements != NULL);
}

template<typename T>
void SeqStack<T>::overflowProcess(){
	T* newArray = new T[maxSize + stackIncrement];
	if(newArray == NULL){
		cerr<<"存储分配失败"<<endl;
		exit(1);
	}
	for(int i = 0; i <= top; i++)
	{
		newArray[i] = elements[i];
	}
	maxSize = maxSize + stackIncrement;
	delete []elements;
	elements = newArray;
}

template<typename T>
void SeqStack<T>::Push(const T& x)
{
	if(IsFull == true)
		overflowProcess();
	elements[++top] = x;
}

template<typename T>
bool SeqStack<T>::Pop(T& x)
{
	if(IsEmpty() == true)
		return false;
	x = elements[top--];
	return true;
}

template<typename T>
bool SeqStack<T>::getTop(T& x)
{
	if(IsEmpty() == true)
		return false;
	x = elements[top];
	return true;
}

template<typename T>
ostream& operator<<(ostream& os, SeqStack<T>& s)
{
	os<<"Top ="<<s.top<<endl;
	for(int i = 0; i <= s; i++)
	{
		os << i<<":"<<s.elements[i]<<endl;
	}
	return os;
}
#endif /* HEADER_SEQSTACK_H_ */
