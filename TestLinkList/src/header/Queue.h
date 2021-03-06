/*
 * Queue.h
 *
 *  Created on: 2015年7月28日
 *      Author: juanecho
 */

#ifndef HEADER_QUEUE_H_
#define HEADER_QUEUE_H_
#include<iostream>
using namespace std;
template <typename T>
class Queue{
public:
	Queue(){};
	virtual ~Queue(){};
	virtual void EnQueue(const T& x) = 0;
	virtual bool DeQueue(T& x) = 0;
	virtual bool getFront(T& x) = 0;
	virtual bool IsEmpty()const = 0;
	virtual bool IsFull() const = 0;
	virtual int getSize()const = 0;
};




#endif /* HEADER_QUEUE_H_ */
