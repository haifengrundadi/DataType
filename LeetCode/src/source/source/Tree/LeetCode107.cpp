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
	 vector<vector<int> > levelOrderBottom(TreeNode* root) {
		 vector<vector<int> > v,v1;
			//层次遍历二叉树
			if (root == NULL)
				return v;
			vector<int> v_in;
			queue<TreeNode*> q;
			queue<int> qInt;
			TreeNode *tree;
			q.push(root);
			qInt.push(0);
			int i = 0;
			v.push_back(v_in);
			while (!q.empty()) {
				tree = q.front();
				q.pop();
				i = qInt.front();
				qInt.pop();
				if(v.size() < i+1){
					v.push_back(v_in);
				}
				v[i].push_back(tree->val);
				if (tree->left != NULL) {
					q.push(tree->left);
					qInt.push(i+1);
				}
				if (tree->right != NULL) {
					q.push(tree->right);
					qInt.push(i+1);
				}
			}
			int size = v.size();
//			cout<<"size="<<size<<endl;
			for(int i = 0 ; i < size; i++){
					v1.push_back(v.back());
					v.pop_back();
			}
			return v1;
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
//
//int main() {
//	Solution * s = new Solution();
//	cout << "output the tree--1" << endl;
//	TreeNode* l = s->Creat();
//	s->output(l);
//	vector<vector<int> > v;
//	v = s->levelOrderBottom(l);
//	vector<int>::iterator it;
//	for(int i = 0 ; i < v.size(); i++){
//		cout<<"*******"<<i<<"********"<<endl;
//		for(it = v[i].begin();it!= v[i].end(); it++){
//			cout<<"----"<<*it;
//		}
//		cout<<endl;
//	}
//}

