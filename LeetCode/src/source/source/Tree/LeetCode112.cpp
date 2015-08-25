/*
 * LeetCode144.cpp
 *
 *  Created on: 2015年8月3日
 *      Author: juanecho
 */

#include<iostream>
#include<vector>
#include"leetcode.h"
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
	int total;
	int flag;
	bool hasPathSum(TreeNode* root, int sum){
	    if(root == NULL){
	        	return 0;
	     }
	    if(flag) return flag;
	    total += root->val;
	    hasPathSum(root->left,sum);
	    hasPathSum(root->right,sum);
//	    cout<<"***"<<total;
	    if(total == sum && root->left == NULL && root->right == NULL){
	    	flag = true;
	    	return flag;
	    }
	    total -= root->val;
//	  	cout<< "root val = "<<root->val<< "  after husu total= "<<total<<endl;
	    return flag;
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
//		Solution * s = new Solution();
//		cout<<"output the tree--1"<<endl;
//		TreeNode* l = s->Creat();
//		s->output(l);
//		cout<<s->hasPathSum(l,4)<<endl;
//}

