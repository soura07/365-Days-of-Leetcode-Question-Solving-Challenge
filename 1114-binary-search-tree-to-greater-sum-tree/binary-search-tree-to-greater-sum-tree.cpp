/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int help(TreeNode*root, int &val){
        if(!root) return 0;
        help(root->right, val); 
        root->val += val; 
        val = root->val;
        help(root->left, val);
        return val;
    }
    TreeNode* bstToGst(TreeNode* root) {
		int total = 0;
        help(root, total);
        return root; 
    }
};