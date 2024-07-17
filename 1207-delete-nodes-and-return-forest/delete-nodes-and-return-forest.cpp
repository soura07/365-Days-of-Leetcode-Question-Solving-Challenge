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
    vector<TreeNode*> ans;
    TreeNode* dfs(TreeNode* root, set<int>& st) {
        if (root == nullptr) return root;

        root -> left = dfs(root -> left, st);
        root -> right = dfs(root -> right, st);
        if (st.find(root -> val) != st.end()) {
            if (root -> left != nullptr) ans.push_back(root -> left);
            if (root -> right != nullptr) ans.push_back(root -> right);
            return nullptr;
        }

        return root;
    }

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        set<int> st(to_delete.begin(), to_delete.end());

        TreeNode* rootNode = dfs(root, st);
        if (rootNode != nullptr) ans.push_back(rootNode);
        return ans;
    }
};