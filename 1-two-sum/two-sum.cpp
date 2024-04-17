class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> mpp;
        for(int i=0; i<nums.size(); i++){
          int a = nums[i];
          int moreAdded = target - a;
          if(mpp.find(moreAdded) != mpp.end()){
            return {mpp[moreAdded], i};
          }
          mpp[a] = i;
        }
        return {-1,-1};
    }
};