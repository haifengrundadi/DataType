/*
 * LeetCode141.cpp
 *
 *  Created on: 2015年8月3日
 *      Author: juanecho
 */

#include<iostream>
using namespace std;

  struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
  };

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL)
        	return false;
        ListNode* fast,*slow;
        fast = slow = head;
       while(fast != NULL)
       {
    	   fast = fast->next;
    	   if(fast)
    		   fast = fast->next;
    	   else
    		   return false;
    	   slow = slow->next;
    	   if(slow == fast)
    		   return true;
       }
        return false;
    }
};

