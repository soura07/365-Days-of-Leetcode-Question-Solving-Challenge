class Solution {
public:

    vector<int> vis;

    int f(int r, int c, int n, vector<vector<int>>& stones, int k)
    {
        int tc = 0;
        vis[k] = 1;
        for(int i = 0; i < n; i++)
        {
            if(!vis[i] && (stones[i][0] == r || stones[i][1] == c))
            {
                tc = tc + 1 + f(stones[i][0], stones[i][1], n, stones, i);
            }
        }
        return tc;
    }
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        int maxr = INT_MIN;
        int maxc = INT_MIN;
        int count = 0;

        vis.resize(n, 0);
        for(int i = 0; i < n; i++)
        {
            int r = stones[i][0];
            int c = stones[i][1];
            int tc = 0;
            
            if(!vis[i])
            {
                tc = f(r, c, n, stones, i);
            }
            count += tc;

        }
        return count;
    }
};