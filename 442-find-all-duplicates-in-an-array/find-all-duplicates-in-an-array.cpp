class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;

        for(int i=0; i<nums.size(); i++){
            int num = abs(nums[i]);
            int idx = num - 1;

            if(nums[idx] < 0){
                res.push_back(num);
            }
            else{
                nums[idx] = -nums[idx];
            }
        }
        return res;
    }
};