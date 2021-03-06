/*
 * LeetCode144.cpp
 *
 *  Created on: 2015年8月3日
 *      Author: juanecho
 */

#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
	 vector<int> preorderTraversal(TreeNode* root) {
	        vector<TreeNode*> s;
	        vector<int > result;
	        TreeNode*p=  root;
	        s.push_back(NULL);
	        while(p!=NULL)
	        {
	        	result.push_back(p->val);
	        	if(p->right!= NULL)
	        		s.push_back(p->right);
	        	if(p->left!=NULL)
	        		p = p->left;
	        	else
	        	{
	        		p = s.back();
	        		s.pop_back();
	        	}
	        }
	        return result;
	 }

	 /*void CreateBinTree(ifstream& in, TreeNode* &subTree)
	 {
		 int item;
		 if(!in.eof())
		 {
			 in>>item;
			 if(item!= 0)
			 {
				 subTree = new TreeNode(item);
				 CreateBinTree(in, subTree->left);
				 CreateBinTree(in, subTree->right);
			 }else
				 subTree = NULL;
		 }
	 }*/
};


