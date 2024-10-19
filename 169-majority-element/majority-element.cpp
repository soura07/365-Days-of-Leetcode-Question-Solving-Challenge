class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int frq = 1;
        int ans = nums[0];

        for(int i=1; i<n; i++){
            if(nums[i] == nums[i-1]){
                frq++;
            }
            else{
                frq = 1;
                ans = nums[i];
            }

            if(frq > n/2){
                return ans;
            }
        }
        return ans;
    }
};