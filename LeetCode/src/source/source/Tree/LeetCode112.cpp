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
	map<int,int> m;
	bool hasPathSum(TreeNode* root, int sum){
	    if(root == NULL){
	        	return 0;
	     }
	    total += root->val;
//	    cout<<"total="<<total<<endl;
	    hasPathSum(root->left,sum);
	    hasPathSum(root->right,sum);
//	    cout<<"***"<<total;
	    if(total == sum && root->left == NULL && root->right == NULL){
//	    	m.insert(pair<int,int>(total, 1));
	    	return true;
	    }
	    total -= root->val;
//	  	cout<< "root val = "<<root->val<< "  husu = "<<total<<endl;
	    return total;
	 }

//	 bool hasPathSum(TreeNode* root, int sum) {
//		 	 	 //深度优先算法DFS
//		         if(root == NULL)
//		         {
//		         	return 0;
//		         }
//		         int left = maxDepth(root->left);
//		         int right = maxDepth(root->right);
//		         return left>right?left+1:right+1;
//		         //若直接 return maxDepth(root->left)>maxDepth(root->right)?maxDepth(root->left)+1:maxDepth(root->right)+1;
//		         //会通不过，因为用了两次的maxDepth()
//	    }

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
//		cout<<s->hasPathSum(l,3)<<endl;
//}

