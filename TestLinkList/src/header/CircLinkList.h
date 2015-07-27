/*
 * CircLinkList.h
 *
 *  Created on: 2015年7月26日
 *      Author: juanecho
 */

#ifndef HEADER_CIRCLINKLIST_H_
#define HEADER_CIRCLINKLIST_H_
#include <iostream>
#include "LinearList.h"
using namespace std;

template <class T>
struct CircLinkNode{
	T data;
	CircLinkNode<T> * link;
	CircLinkNode(CircLinkNode<T>*next = NULL):link(next)
	{
	}
	CircLinkNode(T d,CircLinkNode<T>* next = NULL):data(d),link(next){}
};

template <class T>
class CircList:public LinearList<T>
{
public:
	CircList(const T& x);
	CircList(CircList<T>& L);
	~CircList();
	int Length()const;
	bool IsEmpty()
	{
		return first->link == first?true:false;
	}
	CircLinkNode<T> *getHead()const;
	void setHead(CircLinkNode<T> * p);
	CircLinkNode<T>* Search(T x);
	CircLinkNode<T>* Locate(int i);
	T * getData(i);
	void setData(int i,T& x);
	bool Insert(int i,T& x);
	bool Remove(int i,T& x);
private:
	CircLinkNode<T> *first, *last;
};

#endif /* HEADER_CIRCLINKLIST_H_ */
