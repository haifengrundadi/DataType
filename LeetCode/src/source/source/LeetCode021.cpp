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
	 //递归
	 ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
	 {
		 if(l1 ==NULL)return l2;
		 if(l2 == NULL)return l1;
		 ListNode *ret = NULL;
		 if(l1->val > l2->val)
		 {
			 ret = l2;
			 ret->next =  mergeTwoLists(l1,l2->next);
		 }else{
			 ret = l1;
			 ret->next = mergeTwoLists(l1->next,l2);
		 }
		 return ret;
	 }
};
	 /*methon 1
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
    {
    	if(l1 ==NULL)
        	return l2;
        if(l2 == NULL)
        	return l1;
        ListNode* firstOfList= NULL;
        ListNode* current = l2;
        ListNode* tem = NULL;
        if(l1->val >= l2->val)
        	firstOfList = l2;
        else
        {
        	firstOfList = l1;
        	l1= l2;
        	l2 = firstOfList;
        }
        while(l1 != NULL && l2 != NULL)
        {
			while(l1->val >= l2->val)
			{
				if(l2->next == NULL)
				{
					l2->next = l1;
					return firstOfList;
				}
				current = l2;
				l2 = l2->next;
			}

			tem = l1->next;
			l1->next = current->next;
			current->next = l1;
			current = l1;
			l1 = tem;
        }
        return firstOfList;
    }
};

int main()
{
	Solution* s= new Solution();
	ListNode * arr1= new ListNode(-9);
	ListNode * arr2= new ListNode(-6);
	ListNode * arr3= new ListNode(-3);
	ListNode * arr4= new ListNode(-1);
	ListNode * arr5= new ListNode(1);
	ListNode * arr6= new ListNode(6);
	arr1->next = arr2;
	arr2->next = arr3;
	arr3->next = arr4;
	arr4->next = arr5;
	arr5->next = arr6;
	arr6->next = NULL;
	ListNode * arr7= new ListNode(-2);
	ListNode * arr8= new ListNode(-5);
	arr7->next = arr8;
	arr8->next = NULL;
	ListNode * n = s->mergeTwoLists(arr1,arr7);

	cout<<"---**---"<<endl;
	while(n->next != NULL)
	{
		cout<<n->val<<"\t";
		n = n->next;
	}
	return 0;
}*/


