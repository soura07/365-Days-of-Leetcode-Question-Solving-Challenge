class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int max_ending_here = 0;
        int min_ending_here = 0;
        int max_so_far = 0;

        for (int num : nums) {
            max_ending_here = max(num, max_ending_here + num);
            min_ending_here = min(num, min_ending_here + num);
            max_so_far = max(max_so_far, max(abs(max_ending_here), abs(min_ending_here)));
        }

        return max_so_far;
    }
};