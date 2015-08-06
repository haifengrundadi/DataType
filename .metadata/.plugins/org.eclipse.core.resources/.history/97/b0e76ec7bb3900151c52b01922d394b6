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
    int maxDepth(TreeNode* root) {
    	//深度优先算法DFS
        if(root == NULL)
        {
        	return 0;
        }
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        return left>right?left+1:right+1;
        //若直接 return maxDepth(root->left)>maxDepth(root->right)?maxDepth(root->left)+1:maxDepth(root->right)+1;
        //会通不过，因为用了两次的maxDepth()
    }
};
