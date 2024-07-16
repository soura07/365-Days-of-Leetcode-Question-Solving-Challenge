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
private:
    TreeNode* findLCA(TreeNode* root, int start, int dest)
    {
        if(!root || root -> val == start || root -> val == dest)
            return root;
        
        TreeNode* left = findLCA(root -> left, start, dest);
        TreeNode* right = findLCA(root -> right, start, dest);

        if(!left)
            return right;
        if(!right)
            return left;
        return root;
    }
    bool findPathToTarget(TreeNode* root, int target, string &path)
    {
        if(!root)
            return false;
        if(root -> val == target)
            return true;
        
        path += 'L';
        if(findPathToTarget(root -> left, target, path))
            return true;
        path.pop_back();

        path += 'R';
        if(findPathToTarget(root -> right, target, path))
            return true;
        path.pop_back();

        return false;
    }
public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* lca = findLCA(root, startValue, destValue);

        string path = "";
        findPathToTarget(lca, startValue, path);

        for(auto &ch: path)
        {
            ch = 'U';
        }

        findPathToTarget(lca, destValue, path);

        return path;
    }
};