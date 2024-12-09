class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> problem(nums.size(), 0);
        for(int i = 1; i<nums.size(); i++){
            problem[i] = problem[i-1] + (nums[i]%2 == nums[i-1]%2);
        }

        vector<bool> ans;
        for(auto &x : queries){
            int p = problem[x[1]] - problem[x[0]];
            if(p > 0) ans.push_back(false);
            else ans.push_back(true);
        }

        return ans;
    }
};