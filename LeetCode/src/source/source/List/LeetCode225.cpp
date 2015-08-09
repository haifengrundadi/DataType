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
    	if(qout.empty()){
    	    qout.push(x);
    	    return;
    	}else{
    		qout.push(x);
    	}
    }

    // Removes the element on top of the stack.
    void pop() {
    	if(!q.empty()){
    		while(q.size() - 1){
    			qout.push(q.front());
    			q.pop();
    		}
    		q.pop();
    	}else{
    		while(qout.size() - 1){
    		    q.push(qout.front());
    		    qout.pop();
    		 }
    		qout.pop();
    		printque(qout);
    	}
    }

    void printque(queue<int> q){
    	if(q.size() < 1) return;
    	while(q.size()){
    		cout<<q.front()<<"--";
    		q.pop();
    	}
    	cout<<endl;
    }
    // Get the top element.
    int top() {
    	int x = 0;
		if(!qout.empty())
			 x = qout.back();
		else if(!q.empty())
			x = q.back();
		return x;
    }

    // Return whether the stack is empty.
    bool empty() {
    	return qout.empty() && q.empty();
    }

    queue<int> q;
    queue<int> qout;
};


//int main()
//{
//	Stack* q = new Stack();
//	q->push(1);
//	q->push(2);
//	q->push(3);
//	q->push(4);
//	cout<<"___"<<endl;
//	q->printque(q->q);
//	cout<<"-----"<<endl;
//	q->printque(q->qout);
//	cout<<"___"<<endl;
//	q->pop();
//	cout<<q->top()<<endl;
//	q->push(5);
//	cout<<q->top()<<endl;
//	return 0;
//}
