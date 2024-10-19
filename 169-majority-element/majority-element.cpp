class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //using moore's formula 
        int frq = 0;
        int ans = 0;
        for(int i=0; i<nums.size(); i++){
            if(frq == 0){
                ans = nums[i];
            }
            if(ans == nums[i]){
                frq++;
            }
            else{
                frq--;
            }
        }
        return ans;
    }
};