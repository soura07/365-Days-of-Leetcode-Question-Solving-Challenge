class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        while(k--){
            auto min_itr = min_element(nums.begin(),nums.end());
            *min_itr = (*min_itr)*multiplier;
        }
        return nums;
    }
};