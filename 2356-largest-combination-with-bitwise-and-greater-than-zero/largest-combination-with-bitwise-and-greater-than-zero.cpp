class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        vector<int> cnt(24, 0);
        int ans = 0;
        for(int i=0; i<24; i++){
            for(int &num : candidates){
                if((num & (1 << i)) != 0){
                    cnt[i]++;
                }
            }
            ans = max(ans, cnt[i]);
        }
        return ans;
    }
};