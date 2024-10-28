
class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {

        unordered_set<int>s(nums.begin(),nums.end());

        int maxi=0;
        for(auto it:nums){
            long long newnum=it;
            int cnt=0;
            while(s.find(newnum)!=s.end()){
                cnt++;
                newnum=1ll*newnum*newnum;
                if(newnum>100000){
                    break;
                }
            }

            maxi=max(cnt,maxi);
        }
        return maxi==1?-1:maxi;
    }
};