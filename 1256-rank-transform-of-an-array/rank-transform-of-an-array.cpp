class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        map<int, int> mpp;
        for(auto &val : arr){
            mpp[val]++;
        }

        int ranking = 1;
        for(auto&val : mpp){
            val.second = ranking;
            ranking++;
        }

        vector<int>ans(arr.size());
        for(int i=0; i<arr.size(); i++){
            ans[i] = mpp[arr[i]];
        }
        return ans;
    }
};