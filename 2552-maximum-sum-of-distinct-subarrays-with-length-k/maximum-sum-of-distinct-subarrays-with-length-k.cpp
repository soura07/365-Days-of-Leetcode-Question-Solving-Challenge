class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long result = 0, sum = 0;
        int f[100001] = {0};
        for(int i=0, j=0; i<nums.size(); ++i){
            while(i - j + 1 > k || f[nums[i]])
                sum -= nums[j], f[nums[j++]]--;
            sum += nums[i];
            f[nums[i]]++;

            if(i - j + 1 == k)
                result = max(result, sum);
            
        }

        return result;
    }
};