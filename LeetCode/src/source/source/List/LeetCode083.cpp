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
	ListNode* deleteDuplicates(ListNode* head) {
		 if(head==NULL)return head;
		 ListNode * cur ,*first;
		 cur = first = head;
		 while(head!= NULL){
				 while(cur!= NULL && head->val == cur->val ){
					 cur = cur->next;
				 }
				 head->next = cur;
				 head = cur;
		 }
		 return first;
	}
};

//int main()
//{
//	Solution* s= new Solution();
//	ListNode * arr1= new ListNode(-1);
//	ListNode * arr2= new ListNode(-1);
////	ListNode * arr3= new ListNode(-1);
////	ListNode * arr4= new ListNode(-1);
////	ListNode * arr5= new ListNode(1);
////	ListNode * arr6= new ListNode(2);
//	arr1->next = arr2;
//	arr2->next = NULL;
////	arr3->next = arr4;
////	arr4->next = arr5;
////	arr5->next = arr6;
////	arr6->next = NULL;
//	ListNode * n = s->deleteDuplicates(arr1);
//
//	cout<<"---**---"<<endl;
//	while(n != NULL)
//	{
//		cout<<n->val<<"\t";
//		n = n->next;
//	}
//	return 0;
//}


