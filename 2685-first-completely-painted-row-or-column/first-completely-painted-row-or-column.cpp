class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        map<int, int> mp;
        for (int i = 0; i < arr.size(); i++) {
            mp[arr[i]] = i;
        }

        int miniR = INT_MAX;
        for (int i = 0; i < n; i++) {
            int maxiR = INT_MIN;
            for (int j = 0; j < m; j++) {
                int ele = mat[i][j];
                int ind = mp[ele];
                maxiR = max(maxiR, ind);
            }
            miniR = min(miniR, maxiR);
        }

        int miniC = INT_MAX;
        for (int j = 0; j < m; j++) {
            int maxiC = INT_MIN;
            for (int i = 0; i < n; i++) {
                int ele = mat[i][j]; 
                int ind = mp[ele];
                maxiC = max(maxiC, ind);
            }
            miniC = min(miniC, maxiC);
        }

        return min(miniR, miniC);
    }
};