class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();

        unordered_map<int, long> mp;
        for(int &num : nums1){
            mp[num] += n;
        }

        for(int &num : nums2){
            mp[num] += m;
        }

        int result = 0;
        for(auto &it : mp){
            int num = it.first;
            int frq = it.second;

            if(frq %2 != 0){
                result = result ^ num;
            }
        }
        return result;
    } 
};