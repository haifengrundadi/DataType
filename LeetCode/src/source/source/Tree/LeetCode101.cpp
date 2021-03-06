#include<iostream>
#include<vector>
#include"leetcode.h"
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};

class Solution {
public:
	 bool isSameTree(TreeNode* left, TreeNode* right, bool ans){
		 if(!ans)return ans;
		 if(left==NULL && right==NULL){
			 return true;
		 }else if(left != NULL && right != NULL){
			 if(left->val == right->val){
				 ans = true;
			 }else{
				 ans =false;
			 }
			 return ans && isSameTree(left->left,right->right,ans) && isSameTree(left->right, right->left,ans);
		 }else{
			 return false;
		 }
	 }

	 bool isSymmetric(TreeNode* root) {
		 if(root == NULL) return true;
	     bool ans = true;
	     return isSameTree(root->left,root->right, ans);
	 }

	TreeNode* Creat() {
		TreeNode* root;
		int ch;
		cout << "请输入创建一棵二叉树的结点数据" << endl;
		cin >> ch;
		if (ch == -1)
			root = NULL;
		else {
			root = new TreeNode(ch);       //生成一个结点
			root->left = Creat();    //递归建立左子树
			root->right = Creat();    //递归建立右子树
		}
		return root;
	}

	void output(TreeNode* root) {
		if (root == NULL)
			return;
		cout << root->val << endl;
		output(root->left);
		output(root->right);
	}
};

//int main() {
//	Solution * s = new Solution();
//	cout << "output the tree--1" << endl;
//	TreeNode* l = s->Creat();
//	s->output(l);
//	cout<<s->isSymmetric(l);
//	return 0;
//}

