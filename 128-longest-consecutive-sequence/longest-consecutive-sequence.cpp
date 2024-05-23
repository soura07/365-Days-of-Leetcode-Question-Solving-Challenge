class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;

        sort(nums.begin(), nums.end());
        int maxCount = 1; // Initialize with at least 1 for the case of a single element.
        int currentCount = 1;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1] + 1) {
                currentCount++;
            } else if (nums[i] != nums[i - 1]) { // Skip duplicates
                maxCount = max(maxCount, currentCount);
                currentCount = 1; // Reset the count for a new sequence
            }
        }

        return max(maxCount, currentCount); // Consider the final sequence length as well
    }
};
