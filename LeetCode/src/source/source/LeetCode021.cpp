/*
 * LeetCode21.cpp
 *
 *  Created on: 2015年7月28日
 *      Author: juanecho
 */

#include <iostream>
using namespace std;
 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
    {
    	if(l1 ==NULL)
        	return l2;
        if(l2 == NULL)
        	return l1;
        ListNode* firstOfList;
        ListNode* current = l2;
        if(l1->val >= l2->val)
        	firstOfList = l2;
        else
        {
			cout<<"$$$$"<<endl;
        	firstOfList = l1;
        	l1= l2;
        	l2 = firstOfList;
        }
        while(l1 != NULL && l2 != NULL)
        {
			while(l1->val >= l2->val)
			{
				cout<<"---"<<endl;
				if(l2->next == NULL)
				{
					l2->next = l1;
					return firstOfList;
				}
				current = l2;
				l2 = l2->next;
			}
			if(l1->next == NULL)
			{
				l1->next = current->next;
				current->next = l1;
				return firstOfList;
			}
			l1->next = current->next;
			current->next = l1;
			current = l1;
			l1 = l1->next;
        }
        return firstOfList;
    }
};

int main()
{
	Solution* s= new Solution();
	ListNode * arr1= new ListNode(-10);
	ListNode * arr2= new ListNode(-10);
	ListNode * arr3= new ListNode(-9);
	ListNode * arr4= new ListNode(1);
	ListNode * arr5= new ListNode(6);
	arr1->next = arr2;
	arr2->next = arr3;
	arr3->next = arr4;
	arr4->next = arr5;
	arr5->next = NULL;
	ListNode * arr6= new ListNode(-7);
	arr6->next = NULL;
	ListNode * n = s->mergeTwoLists(arr1,arr6);

	cout<<"---**---"<<endl;
	while(n->next != NULL)
	{
		cout<<n->val<<"\t";
	}
	return 0;
}


