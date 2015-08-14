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
	 ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
//		 if(headA == NULL || headB == NULL) return NULL;
//		 if(headA ==  headB ) return headA;
//		 ListNode* interNode, *slow, * fast,*first;
//		 first = headA;
//		 slow = fast = headA;
//		 while(headA->next!= NULL){
//			 headA = headA->next;
//		 }
//    	 interNode = headA;
//		 headA->next = headB;
//			 while(fast){
//				 fast  = fast->next;
//				 if(fast)
//					fast = fast->next;
//				 else
//					 return NULL;
//				 slow = slow->next;
//				 if(slow== fast){
//					while(first != fast){
//						    first = first->next;
//							fast = fast->next;
//					}
//					interNode->next = NULL;
//					return fast;
//				}
//			}
//		 return NULL;

	        if(headA == NULL || headB == NULL)
	            return NULL;
	        ListNode* iter1 = headA;
	        ListNode* iter2 = headB;
	        int len1 = 1;
	        while(iter1->next != NULL)
	        {
	            iter1 = iter1->next;
	            len1 ++;
	        }
	        int len2 = 1;
	        while(iter2->next != NULL)
	        {
	            iter2 = iter2->next;
	            len2 ++;
	        }
	        if(iter1 != iter2)
	            return NULL;
	        if(len1 > len2)
	        {
	            for(int i = 0; i < len1-len2; i ++)
	                headA = headA->next;
	        }
	        else if(len2 > len1)
	        {
	            for(int i = 0; i < len2-len1; i ++)
	                headB = headB->next;
	        }
	        while(headA != headB)
	        {
	            headA = headA->next;
	            headB = headB->next;
	        }
	        return headA;

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
//	  ListNode * head ,*head1;
////	  while(head!=NULL)
////	  {
////		  cout<<char(head->val)<<endl;
////		  head = head->next;
////	  }
////	  fstream in;
////	  char buffer[256];
////	  in.open("src/source/source/List/in.txt",ios::in);
////	  if(in.is_open())
////	  {
////		  while(!in.eof())
////		  {
////			  in.getline(buffer,256);
//	  string str("135");
//			  head = s->creat(str);
//			  ListNode * newnode = new ListNode('2');
//			  cout<<char(s->getIntersectionNode(head,newnode)->val)<<endl;
////		  }
////	  }
//	  return 0;
//}
