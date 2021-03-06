/*
 * LinkedQueue.h
 *
 *  Created on: 2015年7月28日
 *      Author: juanecho
 */

#ifndef HEADER_LINKEDQUEUE_H_
#define HEADER_LINKEDQUEUE_H_
#include "LinkedList.h"
#include "Queue.h"
template <typename T>
class LinkedQueue:public Queue<T>
{
public:
	LinkedQueue():rear(NULL),front(NULL){}
	~LinkedQueue(makeEmpty());
	bool EnQueue(const T&  x);
	bool DeQueue(T& x);
	bool getFront(T& x)const;
	void makeEmpty();
	bool IsEmpty()const{return (front == NULL)?true:false;}
	int getSize()const;
	friend ostream& operator<<(ostream& os,LinkedQueue<T>& Q);
private:
	LinkNode<T>*front, *rear;
};


template <typename T>
bool LinkedQueue<T>::EnQueue(const T&  x)
{
	if(front == NULL)
	{
		return true;
	}
}



#endif /* HEADER_LINKEDQUEUE_H_ */
