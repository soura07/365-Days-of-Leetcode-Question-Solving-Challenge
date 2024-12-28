class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ps(n + 1, 0); // Prefix sum array
        for (int i = 0; i < n; ++i) {
            ps[i + 1] = ps[i] + nums[i];
        }

        vector<int> le(n, 0); 
        vector<int> rt(n, n - k);

        int mls = ps[k] - ps[0];
        for (int i = k; i < n; ++i) {
            if (ps[i + 1] - ps[i + 1 - k] > mls) {
                mls = ps[i + 1] - ps[i + 1 - k];
                le[i] = i + 1 - k;
            } else {
                le[i] = le[i - 1];
            }
        }

        int mrs = ps[n] - ps[n - k];
        for (int i = n - k - 1; i >= 0; --i) {
            if (ps[i + k] - ps[i] >= mrs) {
                mrs = ps[i + k] - ps[i];
                rt[i] = i;
            } else {
                rt[i] = rt[i + 1];
            }
        }

        vector<int> ans(3); 
        int ms = 0; 
        for (int mid = k; mid <= n - 2 * k; ++mid) {
            int l = le[mid - 1];
            int r = rt[mid + k];
            int ts = (ps[l + k] - ps[l]) +
                     (ps[mid + k] - ps[mid]) +
                     (ps[r + k] - ps[r]);
            if (ts > ms) {
                ms = ts;
                ans = {l, mid, r};
            }
        }

        return ans;
    }
};