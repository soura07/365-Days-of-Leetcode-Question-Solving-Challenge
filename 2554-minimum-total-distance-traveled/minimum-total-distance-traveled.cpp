class Solution {
#define ll long long
public:
    ll solve(int i, int j, int limit, vector<int>& robot,
             vector<vector<int>>& f, vector<vector<vector<ll>>>& dp) {

        int n = robot.size(), m = f.size();

        if (i == n || j == m) {
            return 0;
        }

        if (dp[i][j][limit] != -1) {
            return dp[i][j][limit];
        }

        ll pos = f[j][0], take = LLONG_MAX, notTake = LLONG_MAX / 2;
        if (limit > 0) {
            take =
                abs(robot[i] - pos) + solve(i + 1, j, limit - 1, robot, f, dp);
        }
        if (j + 1 < m) {
            notTake = solve(i, j + 1, f[j + 1][1], robot, f, dp);
        }

        return dp[i][j][limit] = min(take, notTake);
    }

    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& f) {
        ios_base ::sync_with_stdio(false), cin.tie(0), cout.tie(0);
        int n = robot.size();
        int m = f.size();
        sort(robot.begin(), robot.end());
        sort(f.begin(), f.end());
        vector<vector<vector<ll>>> dp(
            n, vector<vector<ll>>(m, vector<ll>(n + 1, -1)));
        ll minRes = solve(0, 0, f[0][1], robot, f, dp);
        return minRes;
    }
};