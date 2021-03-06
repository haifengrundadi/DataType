/*
 * LeetCode155.cpp
 *
 *  Created on: 2015年8月11日
 *      Author: juanecho
 */
#include"leetcode.h"

class MinStack {
public:
    void push(int x) {
    	if(!s.empty()){
    		min = min <= x? min:x;
//    		cout<<"x = "<<x<<endl;
    		s.push(x);
    	}else{
    		min = x;
//    		cout<<"x1 = "<<x<<endl;
    		s.push(x);
    	}
    }

    void pop() {
    	int top = 0;
    	if(!s.empty()){
    		top = s.top();
    		 s.pop();
//    		 cout<<"s--"<<top<<endl;
    		if(min == top){
    			if(!s.empty())
    				min = s.top();
    			else{
    				min = 0;
    				return;
    			}
    			while(!s.empty()){
    				min = min <= s.top()? min:s.top();
    				s1.push(s.top());
    				s.pop();
    			}
    			while(!s1.empty()){
    				s.push(s1.top());
    				s1.pop();
    			}
    		}
    	}
    }

    int top() {
    	if(!s.empty())
    		return s.top();
    	else
    	    return s1.top();
    }

    int getMin() {
    	return min;
    }
private:
    stack<int> s;
    stack<int> s1;
    int min;
};

//int main(){
//		stack<int> s;
//		MinStack *m = new MinStack();
//	    m->push(2147483646);
//	    m->push(2147483646);
//	    m->push(2147483647);
//	    cout<<m->top()<<"*"<<endl;
//	    m->pop();
//	    cout<<m->getMin()<<endl;
//	    m->pop();
//	    cout<<m->getMin()<<endl;
//	    m->pop();
//	    cout<<"8888"<<endl;
//	    m->push(2147483647);
//	    cout<<m->top()<<"*"<<endl;
//	    cout<<m->getMin()<<endl;
//	    m->push(-2147483648);
//	    cout<<m->top()<<"*"<<endl;
//	    cout<<m->getMin()<<endl;
//	    m->pop();
//	    cout<<m->getMin()<<endl;
////		  	  	m->push(2);
////			    m->push(0);
////			    m->push(3);
////			    m->push(0);
////			    cout<<m->getMin()<<endl;
////			    m->pop();
////			    cout<<m->getMin()<<endl;
////			    m->pop();
////			    cout<<m->getMin()<<endl;
////			    m->pop();
////			   cout<<m->getMin()<<endl;
//	    return 0;
//}
