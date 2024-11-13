class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long ans = 0;
        sort(nums.begin(), nums.end());
        for(int i = 0; i<nums.size(); i++){
           int x = lower-nums[i]; 
           int y = upper-nums[i]; 
           auto itx = lower_bound(nums.begin()+i+1, nums.end(), x);
           auto ity = upper_bound(nums.begin()+i+1, nums.end(), y);
           ans += ity-itx; 
        }
        return ans;
    }
};