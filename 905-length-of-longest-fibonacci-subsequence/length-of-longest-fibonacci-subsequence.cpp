class Solution
{
public:
    int lenLongestFibSubseq(vector<int> &arr)
    {
        int n = arr.size(), maxi = 0;
        vector<vector<int>> DP(n, vector<int>(n, 2));
        unordered_map<int, int> idx;
        for (int i = 0; i < n; i++)
            idx[arr[i]] = i;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int next = arr[i] + arr[j];
                if (idx.find(next) == idx.end())
                    continue;
                int k = idx[next];
                DP[j][k] = max(DP[j][k], 1 + DP[i][j]);
                maxi = max(maxi, DP[j][k]);
            }
        }
        return maxi >= 3 ? maxi : 0;
    }
};