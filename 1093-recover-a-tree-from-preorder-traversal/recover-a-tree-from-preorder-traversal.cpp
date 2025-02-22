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
    TreeNode* recoverFromPreorder(string t) {
        int n = t.size();
        int height = 0;
        int value = 0;
        vector<int> nodeValues, nodeHeight;

        for(int i = 0; i < n; i++)
        {
            char c = t[i];
            int v = c-'0';

            if(0 <= v && v <= 9) {
                if(!value) {
                    nodeHeight.push_back(height);
                    height = 0;
                }
                value = value*10 + v;
            } else {
                if(!height) {
                    nodeValues.push_back(value);
                    value = 0;
                }
                height++;
            }
        }

        nodeValues.push_back(value);

        // for(int x:nodeValues) cout << x << " ";
        // cout << endl;
        // for(int x:nodeHeight) cout << x << " ";
        // cout << endl;

        int m = nodeHeight.size();
        vector<TreeNode*> nodes(m, NULL);

        nodes[0] = new TreeNode(nodeValues[0]);

        for(int i = 1; i < m; i++) {
            const int& currHeight = nodeHeight[i];
            const int& currValue = nodeValues[i];
            TreeNode* currNode = new TreeNode(currValue);

            for(int j = i-1; j >= 0; j--) {
                const int& prevHeight = nodeHeight[j];
                
                if(prevHeight+1 == currHeight) {
                    nodes[i] = currNode;
                    TreeNode*& prevNode = nodes[j];
                    if(prevNode -> left == NULL) prevNode -> left = currNode;
                    else prevNode -> right = currNode;
                    break;
                }
                
            }
        }

        return nodes[0];
    }
};