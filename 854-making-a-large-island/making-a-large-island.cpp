class Solution {
public:

    void dfs(vector<vector<int>>& grid, vector<vector<pair<int, int>>>& vis, int& count, int k, int i, int j, int n) {
        if (i < 0 || i >= n || j < 0 || j >= n) return;
        if (grid[i][j] == 0) return;
        if (vis[i][j].first == 1) return;

        vis[i][j].first = 1;
        vis[i][j].second = k;
        count++;

        dfs(grid, vis, count, k, i + 1, j, n);
        dfs(grid, vis, count, k, i - 1, j, n);
        dfs(grid, vis, count, k, i, j + 1, n);
        dfs(grid, vis, count, k, i, j - 1, n);
    }

    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<pair<int, int>>> vis(n, vector<pair<int, int>>(n, {0, -1}));

        int k = 0;
        vector<int> ans(n * n, 0);  
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && vis[i][j].first == 0) {
                    int count = 0;
                    dfs(grid, vis, count, k, i, j, n);
                    ans[k] = count;
                    k++;
                }
            }
        }

        int maxSize = 0;
        for (int x : ans) maxSize = max(maxSize, x);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) continue;

                set<int> uniqueIslands;
                if (i > 0 && vis[i - 1][j].second != -1) uniqueIslands.insert(vis[i - 1][j].second);
                if (i < n - 1 && vis[i + 1][j].second != -1) uniqueIslands.insert(vis[i + 1][j].second);
                if (j > 0 && vis[i][j - 1].second != -1) uniqueIslands.insert(vis[i][j - 1].second);
                if (j < n - 1 && vis[i][j + 1].second != -1) uniqueIslands.insert(vis[i][j + 1].second);

                int newSize = 1;
                for (int id : uniqueIslands) {
                    newSize += ans[id];
                }

                maxSize = max(maxSize, newSize);
            }
        }

        return maxSize;
    }
};