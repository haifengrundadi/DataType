/*
 * LeetCode226.cpp
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
	TreeNode* invertTree(TreeNode* root)
	{
	        if(root == NULL)
	        	return NULL;
	        TreeNode* dest = new TreeNode(root->val);
	        dest->left = invertTree(root->right);
	        dest->right = invertTree(root->left);
	        return dest;
	 }


	TreeNode* Creat( )
	{
		TreeNode* root;
		int ch;
		cout<<"请输入创建一棵二叉树的结点数据"<<endl;
	 	 cin>>ch;
	    if (ch==-1)
	    	root = NULL;
	    else
	    {
	    	 root = new TreeNode(ch);       //生成一个结点
	         root->left   =  Creat( );    //递归建立左子树
	         root->right = Creat( );    //递归建立右子树
	    }
	    return root;
	}

	void  output(TreeNode* root )
	{
	  if(root == NULL)
		  return;
	  cout<<root->val<<endl;
	  output(root->left);
	  output(root->right);
	}
};

/*int main()
{
	Solution * s = new Solution();
	cout<<"output the tree--1"<<endl;
	TreeNode* l = s->Creat();
	s->output(l);
	l = s->invertTree(l);
	cout<<"output the tree--2"<<endl;
	s->output(l);
}*/

