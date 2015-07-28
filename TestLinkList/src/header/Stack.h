/*
 * Stack.h
 *
 *  Created on: 2015年7月28日
 *      Author: juanecho
 */

#ifndef HEADER_STACK_H_
#define HEADER_STACK_H_
#include <iostream>
using namespace std;
const int maxSize = 50;
template<typename T>
class Stack{
public:
	Stack(){};
	virtual ~Stack(){};
	virtual void Push(T& x) = 0;
	virtual bool Pop(T& x) = 0;
	virtual bool getTop(T& x) const = 0; //读取栈顶元素由，x返回
	virtual bool IsEmpty() const = 0;
	virtual bool IsFull() const = 0;
	virtual int getSize() const = 0;
};




#endif /* HEADER_STACK_H_ */
