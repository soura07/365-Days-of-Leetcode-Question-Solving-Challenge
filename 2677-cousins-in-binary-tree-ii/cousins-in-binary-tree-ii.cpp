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
    TreeNode* replaceValueInTree(TreeNode* root) {
        queue<TreeNode *> q;
        q.push(root);
        int prev_sum = root->val;

        while(!q.empty()) {
            int sz = q.size();
            int level_sum = 0;
            for(int i = 0; i < sz; i++) {
                auto it = q.front();
                q.pop();
                it->val = prev_sum - it->val;
                int sum = 0;
                sum += (it->right) ? it->right->val : 0;
                sum += (it->left) ? it->left->val : 0;
                if(it->right) {
                    it->right->val = sum;
                    q.push(it->right);
                }
                if(it->left) {
                    it->left->val = sum;
                    q.push(it->left);
                }
                level_sum += sum;
            }
            prev_sum = level_sum;
    
        }
        return root;
    }
};