/*
 * LeetCode235.cpp
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

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    	TreeNode* comNode;
    	if(root == NULL)return NULL;
    	if(p == NULL)  return q;
    	if(q == NULL)  return p;
    	if(p->val < root->val && q->val < root->val){
    		comNode = lowestCommonAncestor(root->left,p,q);
    	}else if(p->val > root->val && q->val > root->val){
    		comNode = lowestCommonAncestor(root->right,p,q);
    	}else{
    		comNode = root;
    	}
    	return comNode;
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

//int main()
//{
//	Solution * s = new Solution();
//	cout<<"output the tree--1"<<endl;
//	TreeNode* root = s->Creat();
//	TreeNode* p = new TreeNode(2);
//	TreeNode* q = new TreeNode(4);
//	cout<<s->lowestCommonAncestor(root,p,q)->val;
//}

