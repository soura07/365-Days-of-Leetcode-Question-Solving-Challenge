class Solution {
 public:
  int tupleSameProduct(vector<int>& nums) {
    int result = 0;
    unordered_map<int, int> count;
    for (int i = 0; i < nums.size(); ++i){
      for (int j = 0; j < i; ++j)
        result = result + count[nums[i] * nums[j]]++ * 8;
    }
    return result;
  }
};