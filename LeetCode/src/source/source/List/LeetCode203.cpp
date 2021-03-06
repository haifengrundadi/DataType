/*
 * LeetCode243.cpp
 *
 *  Created on: 2015年8月1日
 *      Author: juanecho
 */
#include "leetcode.h"
/*
 * Given a singly linked list, determine if it is a palindrome.
 * Follow up:
 * Could you do it in O(n) time and O(1) space?
 */
 struct ListNode {
   int val;
   ListNode *next;
   ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
	 ListNode* removeElements(ListNode* head, char val) {
		 ListNode *first,*cur;
		 while(head!= NULL &&head->val == val ){
				 head = head->next;
		 }
		first = head;
		cur = head;
		 while(head != NULL){
			 if(head->val == val){
				 cur->next = head->next;
				 head = head->next;
			 }else{
				 cur = head;
				 head = head->next;
			 }
		 }
		 return first;
	 }

	ListNode* creat(string str){
		ListNode *head,*first;
		int i = 0, len = str.length();
		if(len >= 1)
		{
			head = new ListNode(str[i]);
			first = head;
		}
		while((i+1)<len)
		{
			ListNode* listNode = new ListNode(str[i+1]);
			head->next = listNode;
			head = listNode;
			i++;
		}
		return first;
	}
};
//int main()
//{
//	  Solution * s= new Solution();
//	  ListNode * head,*copyhead, *newHead ;
////	  while(head!=NULL)
////	  {
////		  cout<<char(head->val)<<endl;
////		  head = head->next;
////	  }
//	  fstream in;
//	  char buffer[256];
//	  in.open("src/source/source/List/in.txt",ios::in);
//	  if(in.is_open())
//	  {
//		  while(!in.eof())
//		  {
//			  in.getline(buffer,256);
//			  head = s->creat(buffer);
//			  copyhead = head;;
//			  while(head!=NULL)
//			 			  	  {
//				  cout<<char(head->val)<<"\t";
//			 			  		  head = head->next;
//			 			  	  }
//		  	  cout<<endl;
//			  newHead = s->removeElements(copyhead, '6');
//			  	  while(newHead!=NULL)
//			  	  {
//			  		  cout<<char(newHead->val)<<"\t";
//			  		newHead = newHead->next;
//			  	  }
//			  	  cout<<endl;
//		  }
//	  }
//	  return 0;
//}
