class Solution {
public:
    int findNextP(int n,  int k){
        n=max(2,n);
        while(n<k){
            bool flag=true;
            for(int i=2;i*i<=n;i++){
                if(n%i==0){
                    flag=false;
                    break;
                }
            }
            if(flag) return n;
            n++;
        }
        return 0;
    }
    bool primeSubOperation(vector<int>& nums) {
        int n=nums.size();
        for(int i=n-1;i>0;i--){
            if(nums[i-1]>=nums[i]){
                nums[i-1]-=findNextP(nums[i-1]-nums[i]+1,nums[i-1]);
                if(nums[i-1]>=nums[i]) return false;
            }
        }
        return true;
    }
};