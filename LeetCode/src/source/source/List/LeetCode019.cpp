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
	 ListNode* removeNthFromEnd(ListNode* head, int n) {
		 if(head == NULL || n == 0)return head;
		 ListNode* first = head;
		 int count = 0;
		 while(head != NULL){
			 count++;
			 head = head->next;
		 }
		 head = first;
		 if(n == count ){
			 first = first->next;
			 return first;
		 }
		 int i = 1;
		 while(i < count - n){
			 head = head->next;
			 i++;
		 }
		 head->next = head->next->next;
		 return first;
	 }
};

//int main()
//{
//	Solution* s= new Solution();
//	ListNode * arr1= new ListNode(1);
//	ListNode * arr2= new ListNode(2);
//	ListNode * arr3= new ListNode(-3);
//	ListNode * arr4= new ListNode(4);
//	ListNode * arr5= new ListNode(5);
//	ListNode * arr6= new ListNode(6);
//	arr1->next = arr2;
//	arr2->next = arr3;
//	arr3->next = arr4;
//	arr4->next = arr5;
//	arr5->next = arr6;
//	arr6->next = NULL;
//	ListNode * n = s->removeNthFromEnd(arr1,0);
//
//	cout<<"---**---"<<endl;
//	while(n != NULL)
//	{
//		cout<<n->val<<"\t";
//		n = n->next;
//	}
//	return 0;
//}


