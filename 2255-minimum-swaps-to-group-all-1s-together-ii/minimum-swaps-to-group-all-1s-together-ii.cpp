class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        for(int i=0; i<n; i++){
            if(nums[i] == 1){
                cnt++;
            }
        }
        if(cnt == 0) return 0; 
        vector<int> v(n*2);
        for(int i=0; i<n*2; i++){
            v[i] = nums[i%n];
        }
        int i=0;
        int j=0;
        int ans = INT_MAX;
        int countOne = 0;

        while(j < n*2){
            if(v[j] == 1){
                countOne++;
            }
            if(j - i + 1 == cnt){
                ans = min(ans, cnt - countOne);
                if(v[i] == 1){
                    countOne--;
                }
                i++;
            }
            j++;
        }
        return ans;
        
    }
};