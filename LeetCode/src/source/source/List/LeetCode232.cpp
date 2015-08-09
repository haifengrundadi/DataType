/*
 * LeetCode243.cpp
 *
 *  Created on: 2015年8月1日
 *      Author: juanecho
 */
#include "leetcode.h"
#include <stack>
 class Queue {
 public:
     // Push element x to the back of queue.
     void push(int x) {
    	 in.push(x);
     }

     void move(){
             while(!in.empty())
             {
                 int x = in.top();
                 in.pop();
                 out.push(x);
             }
         }
     // Removes the element from in front of queue.
     void pop(void) {
    	 if (out.empty())
    	         {
    	             move();
    	         }
    	         if (!out.empty())
    	         {
    	             out.pop();
    	         }
     }

     // Get the front element.
     int peek(void) {
    	 int result = 0;
    	 if (out.empty())
    	         {
    	             move();
    	         }
    	         if (!out.empty())
    	         {
    	        	 result =    out.top();
    	         }
    	         return result;
     }

     // Return whether the queue is empty.
     bool empty(void) {
         return in.empty() && out.empty();
     }
private:
    stack<int> in;
    stack<int> out;
 };
//int main()
//{
//	Queue* q = new Queue();
//	cout<<q->empty()<<endl;
//	return 0;
//}
