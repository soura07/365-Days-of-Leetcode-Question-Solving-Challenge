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
  void sumLeft(TreeNode* root, int isLeft, int &ans){
    if(root == 0) return;

    if(root->left == 0 and root->right == 0 and isLeft){
      ans = ans + root->val;
      return;
    }

    sumLeft(root->left, true, ans);
    sumLeft(root->right, false, ans);
    
  }
public:
    int sumOfLeftLeaves(TreeNode* root) {
        int ans = 0;
        sumLeft(root, false, ans);
        return ans;
    }
};