class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> hcopy(heights);
        sort(hcopy.begin(), hcopy.end());
        int ans = 0;
        for(int i=0; i<hcopy.size(); i++){
            if(hcopy[i] != heights[i]){
                ans++;
            }
        }
        return ans;
    }
};