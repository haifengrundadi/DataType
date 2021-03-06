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
	int CheckHeight(TreeNode* root, bool& ans)
	    {
	        if(!root || !ans)//if is is not a balance tree already, we just return
	            return 0;
	        int leftHeight = CheckHeight(root->left, ans);
	        int rightHeight = CheckHeight(root->right, ans);
	        if(abs(leftHeight-rightHeight) > 1)
	            ans = false;
	        return max(leftHeight, rightHeight)+1;
	    }
	    bool isBalanced(TreeNode *root) {
	        bool ans = true;
	        CheckHeight(root, ans);
	        return ans;
	    }

	//题目理解有偏差
//	bool isBalanced(TreeNode* root) {
//		//层次遍历二叉树
//		if (root == NULL)
//			return true;
//		queue<TreeNode*> q;
//		queue<int> qInt;
//		TreeNode *tree;
//		int i = 1;
//		int flag = 0;
//		q.push(root);
//		qInt.push(1);
//		while (!q.empty()) {
//			tree = q.front();
//			q.pop();
//			i = qInt.front();
//			qInt.pop();
//			if (i - flag >= 2 && flag != 0) {
//				return false;
//			}
//			if (tree->left != NULL) {
//				q.push(tree->left);
//				qInt.push(i + 1);
//			} else if (flag == 0) {
//				flag = i;
//				cout<<"flag " <<flag<<endl;
//			}
//			if (tree->right != NULL) {
//				q.push(tree->right);
//				qInt.push(i + 1);
//			} else if (flag == 0) {
//				flag = i;
//			}
//		}
//		return true;
//	}

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
//	cout << "is Balanced:" << endl;
//	cout << s->isBalanced(l) << endl;
//}

