class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        int cnt = 0;
        int flag = 0;
        vector<int> partial(nums.size() + 1);
        for (int i = 0; i < nums.size(); i++) {
            nums[i] ^= flag ^= partial[i];
            if (i + k - 1 < nums.size()) {
                cnt += !nums[i];
                flag ^= !nums[i];
                partial[i + k] ^= !nums[i];
            }
            else if (!nums[i]) {
                return -1;
            }
        }
        return cnt;
    }
};