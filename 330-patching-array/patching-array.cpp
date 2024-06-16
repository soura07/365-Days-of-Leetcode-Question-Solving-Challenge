class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
         long int addpatch = 0;
         long int maxnum = 0 ;
         long int i =0 ;

        while( maxnum < n){
            if( i < nums.size() && maxnum + 1 >= nums[i]){
                maxnum += nums[i];
                i++;
            }
            else{
                addpatch += 1;
                maxnum = maxnum + (maxnum + 1);
            }
        }
        return addpatch;
        
    }
};