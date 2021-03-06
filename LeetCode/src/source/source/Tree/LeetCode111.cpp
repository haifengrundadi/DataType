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
	int minDepth(TreeNode* root) {
	      if(root == NULL){
	        return 0;
	       }
	      int left  = 0;
	      int right  = 0;
	      if(root->right == 0 && root->left != 0){
	      	    	   return  minDepth(root->left)+1;
	      }else if(root->right != 0 && root->left == 0){
	      	    	   return minDepth(root->right)+1;
	      }else if(root->right == 0 && root->left == 0){
	      	    	   return 1;
	      }else{
	    	  left = minDepth(root->left);
	    	  right = minDepth(root->right);
	    	  return left<right?left+1:right+1;
	    }
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
//		cout<<s->minDepth(l)<<endl;
//}

