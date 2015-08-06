/*
 * LeetCode100.h
 *
 *  Created on: 2015年8月3日
 *      Author: juanecho
 */
#include<iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL)
        	return true;
        if(p != NULL && q!= NULL &&( p->val == q->val )&& isSameTree(p->left, q->left) && isSameTree(p->right,q->right))
        	return true;
        return false;
    }
};

