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
private:
};




#endif /* HEADER_SEQSTACK_H_ */
