#include<iostream>
using namespace std;

 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void deleteNode(ListNode* node) {
    	//没有前置结点
    	//用后一个接点覆盖当前的值
        node->val = node->next->val;
        node->next = node->next->next;
    }
};
