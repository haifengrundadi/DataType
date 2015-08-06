/*
 * LeetCode002.cpp
 *
 *  Created on: 2015年8月4日
 *      Author: juanecho
 */

#include<iostream>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

/*
 * 思路：
 * 主要是解决最后相加是否为10，和中间的进位问题。
 * 设置flag，用与判定是否超过10。如果不超过，则添加在新的链表里，如果超过，取mod然后判定是否为最后一个结点。
 */
class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
	{
		if(l1 == NULL)
			return l2;
		if(l2 == NULL)
			return l1;
		int flag = 0;
		int sum = 0;
 		ListNode* fisrt, *tail,*current;
 		int k = 0;
		while(l1!=NULL && l2 != NULL)
		{
			sum = l1->val + l2->val + flag;
			flag = 0;
			if(sum >= 10)
			{
				flag = 1;
				sum = sum % 10;
			}
			current = new ListNode(sum);
			if( k == 0)
			{
				fisrt = current;
				tail = current;
				k = k+ 1;
			}else
			{
				tail->next = current;
				tail = current;
			}
			l1 = l1->next;
			l2= l2->next;
		}
		if(l1 == NULL && l2 == NULL)
		{
			if(flag)
				tail->next = new ListNode(1);
			return fisrt;
		}
		if(l1 == NULL && l2 != NULL)
		{
			l1 = l2;
		}
		while( l1!= NULL)
		{
			sum= l1->val + flag;
			flag = 0;
			if(sum >= 10)
			{
				flag = 1;
				sum= sum % 10;
				if(l1->next == NULL)
				{
					tail->next = new ListNode(0);
					tail->next->next = new ListNode(1);
					return fisrt ;
				}
			}
			current = new ListNode(sum);
			tail->next = current;
			tail = current;
			l1 = l1->next;
		}
		return fisrt;
	}
};


