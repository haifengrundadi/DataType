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


  struct TreeLinkNode {
  int val;
  TreeLinkNode *left, *right, *next;
  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 };

class Solution {
public:
    void connect(TreeLinkNode *root) {
    	if(root == NULL) return;
    	queue<TreeLinkNode*> v;
    	TreeLinkNode * tem;
    	v.push(root);
    	while(!v.empty()){
    		tem = v.front();
    		v.pop();
    		if(tem->left != NULL){
    			tem->left->next = tem->right;
    			v.push(tem->left);
    		}
    		if(tem->right != NULL){
    			if(tem->next != NULL)
    				tem->right->next = tem->next->left;
    			v.push(tem->right);
    		}
    	}
    }

    TreeLinkNode* Creat( )
		{
    	TreeLinkNode* root;
			int ch;
			cout<<"请输入创建一棵二叉树的结点数据"<<endl;
		 	 cin>>ch;
		    if (ch==-1)
		    	root = NULL;
		    else
		    {
		    	 root = new TreeLinkNode(ch);       //生成一个结点
		         root->left   =  Creat( );    //递归建立左子树
		         root->right = Creat( );    //递归建立右子树
		    }
		    return root;
		}

		void  output(TreeLinkNode* root )
		{
		  if(root == NULL)
			  return;
		  cout<<root->val<<endl;
		  output(root->left);
		  output(root->right);
		}
};
//
//int main()
//{
//		Solution * s = new Solution();
//		cout<<"output the tree--1"<<endl;
//		TreeLinkNode* l = s->Creat();
//		s->output(l);
//		s->connect(l);
//}

