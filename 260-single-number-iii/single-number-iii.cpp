class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long xorr = 0;
        for(int &num : nums){
            xorr = xorr ^ num;
        }

        int mask = (xorr) & (-xorr);

        int grp_a = 0;
        int grp_b = 0;

        for(int &num : nums){
            if(num & mask){
                grp_a = grp_a ^ num;
            }
            else{
                grp_b = grp_b ^ num;
            }
        }
        return {grp_a, grp_b};
    }
};