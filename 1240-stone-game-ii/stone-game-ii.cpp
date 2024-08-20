class Solution {
public:
    int f(int p, int i, int m, int n, vector<int>& piles, vector<vector<vector<int>>>& dp) {
        if (i >= n) {
            return 0;
        }
        if (dp[p][i][m] != -1) {
            return dp[p][i][m];
        }
        int stones = 0;
        int maxi = (p == 0) ? -1 : INT_MAX; 

        for (int x = 1; x <= min(2 * m, n - i); x++) {
            stones += piles[i + x - 1]; 

            if (p == 0) {
          
                maxi = max(maxi, stones + f(1, i + x, max(m, x), n, piles, dp));
            } else {

                maxi = min(maxi, f(0, i + x, max(m, x), n, piles, dp));
            }
        }
        return dp[p][i][m] = maxi;
    }

    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<vector<vector<int>>> dp(2, vector<vector<int>>(n + 1, vector<int>(n + 1, -1)));
        return f(0, 0, 1, n, piles, dp);
    }
};