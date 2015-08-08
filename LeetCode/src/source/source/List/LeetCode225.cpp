/*
 * LeetCode243.cpp
 *
 *  Created on: 2015年8月1日
 *      Author: juanecho
 */
#include "leetcode.h"
#include <queue>
 class Stack {
public:
    // Push element x onto stack.
    void push(int x) {
    	q.push(x);
    }

    void move(){
    	if(q.empty()) return;
    	else{
    		while(q.size()){
    			qout.push(q.front());
    			q.pop();
    		}
    	}
    }

    // Removes the element on top of the stack.
    void pop() {
    	if(qout.empty())
    		move();
    	if(!qout.empty())
    		qout.pop();
    }

    // Get the top element.
    int top() {
    	int x = 0;
    	if(qout.empty())
    		move();
		if(!qout.empty())
			 x = qout.back();
		return x;
    }

    // Return whether the stack is empty.
    bool empty() {
    	return qout.empty() && q.empty();
    }

private:
    queue<int> q;
    queue<int> qout;
};


int main()
{
	Stack* q = new Stack();
	cout<<q->empty()<<endl;
	q->push(1);
	q->push(2);
	q->push(3);
	q->push(4);
	cout<<q->empty()<<endl;
	cout<<q->top()<<endl;
	q->pop();
	cout<<q->top()<<endl;
	q->push(5);
	cout<<q->top()<<endl;
	return 0;
}
