/*
 * SeqLinkedStack.h
 *
 *  Created on: 2015年7月28日
 *      Author: juanecho
 */

#ifndef HEADER_SEQLINKEDSTACK_H_
#define HEADER_SEQLINKEDSTACK_H_
#include <iostream>
#include"LinkedList.h"
#include"Stack.h"
template<typename T>
class SeqLinkedStack:public Stack<T>
{
public:
	SeqLinkedStack():top(NULL){};
	~SeqLinkedStack(){makeEmpty();}
	void Push(const T& x);
	bool Pop(T& x);
	bool getTop(T& x)const;
	bool IsEmpty()const{return (top==NULL)?true:false;}
	int getSize()const;
	void makeEmpty();
	friend ostream& operator<<(ostream& os,SeqLinkedStack<T> s);
private:
	LinkNode<T> * top;
};

template<typename T>
void SeqLinkedStack<T>::makeEmpty()
{
	LinkNode<T> * p;
	while(top != NULL)
	{
		p = top;
		top = top->link;
		delete p;
	}
}
template<typename T>
void SeqLinkedStack<T>::Push(const T& x)
{
	top = new LinkNode<T>(x, top);
	assert(top != NULL);
}

template<typename T>
bool SeqLinkedStack<T>::Pop( T& x)
{
	if(IsEmpty() == true)
		return false;
	LinkNode<T>* p = top;
	top = top->link;
	x = p->data;
	delete p;
	return true;
}

template<typename T>
bool SeqLinkedStack<T>::getTop(T& x) const
{
	if(IsEmpty() == true)
		return false;
	x = top->data;
	return false;
}

template<typename T>
int SeqLinkedStack<T>::getSize()const
{
	LinkNode<T>* p = top;
	int k = 0;
	while(top != NULL)
	{
		top = top->link;
		k++;
	}
	return k;
}

template<typename T>
ostream& operator<<(ostream& os,SeqLinkedStack<T> s)
{
	os<<"栈中的元素个数"<<s.getSize()<<endl;
	LinkNode<T>* p = s.top;
	int i = 0;
	while(p!= NULL)
	{
		os<<++i<<":"<<p->data<<endl;
		p = p->link;
	}
	return os;
}
#endif /* HEADER_SEQLINKEDSTACK_H_ */
