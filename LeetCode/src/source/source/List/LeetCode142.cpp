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
	  ListNode *detectCycle(ListNode *head) {
        if(head == NULL)
        	return NULL;
        ListNode* fast,*slow;
        fast = slow = head;
       while(fast != NULL)
       {
    	   fast = fast->next;
    	   if(fast)
    		   fast = fast->next;
    	   else
    		   return NULL;
    	   slow = slow->next;
    	   if(slow == fast)
    	   {
    		   while(head != fast)
    		   {
				   head = head->next;
				   fast = fast->next;
    		   }
    		   return head;
    	   }
       }
        return NULL;
    }
};

