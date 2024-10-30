class Solution {
public:
    #define ll long long
        ll score(vector<int>&nums, int skip){
            ll lcm = skip != 0 ? nums[0] : nums[1];
            ll gcd = skip != 0 ? nums[0] : nums[1];

            for(int i=0; i<nums.size(); i++){
                if(i == skip) continue;

                gcd = __gcd(gcd, (ll) nums[i]);
                lcm = (nums[i] * lcm)/__gcd((ll)nums[i], lcm);
            }
            return lcm * gcd;
        }
        long long maxScore(vector<int>& nums){
            if(nums.size() == 1) return nums[0]*nums[0];

            ll ans = score(nums, -1);

            for(int i=0; i<nums.size(); i++){
                ans = max(ans, score(nums, i));
            }
            
        return ans;
    }
};