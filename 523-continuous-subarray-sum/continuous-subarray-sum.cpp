class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size(), prefSum = 0;
        unordered_map<int, int> firstOc;
        firstOc[0] = 0;
        for(int i=0; i<n; i++){
            prefSum = (prefSum + nums[i])%k;
            if(firstOc.find(prefSum) != firstOc.end()){
                if(i+1 - firstOc[prefSum] >= 2) return true;
            }else{
                firstOc[prefSum] = i+1;
            }
        }
        return false;
    }
};