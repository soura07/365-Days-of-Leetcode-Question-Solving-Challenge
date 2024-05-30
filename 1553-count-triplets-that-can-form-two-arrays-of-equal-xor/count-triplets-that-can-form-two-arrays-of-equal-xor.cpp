class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int res = 0;
        for (int start = 0; start < arr.size() - 1; start++) {
            int xor_first_arr = 0; 
            for (int second_start = start + 1; second_start < arr.size(); second_start++) {
                xor_first_arr ^= arr[second_start - 1]; 
                int xor_second_arr = 0; 
                for (int end = second_start; end < arr.size(); end++) {
                    xor_second_arr ^= arr[end]; 
                    if (xor_first_arr == xor_second_arr) { 
                        res++;
                    }
                }
            }
        }
        return res;
    }
};