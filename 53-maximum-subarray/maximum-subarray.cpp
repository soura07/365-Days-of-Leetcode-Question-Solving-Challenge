class Solution {
public:
    typedef long long ll;
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        ll maxi = LONG_MIN;
        ll sum = 0;
        for(int i=0; i<n; i++){
            sum = sum + nums[i];

            if(sum > maxi){
                maxi = sum;
            }

            if(sum < 0){
                sum = 0;
            }
            // maxi = max(sum, maxi);
            
        }
        return maxi;
        
    }
};