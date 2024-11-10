class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int l = 0, r = 0, N = nums.size(), ans = INT_MAX;
        vector<int> freq(32, 0);
    
        while (r < N) {
            if (convertToNum(freq) < k) {
                update(freq, nums[r], 1);
            } 

            while (l <= r && convertToNum(freq) >= k) {
                ans = min(ans, r - l + 1);
                update(freq, nums[l], -1);
                l++;
            }
            r++;
        }
        
        return ans == INT_MAX ? -1 : ans; 
    }

    void update(vector<int>& freq, int num, int delta) { 
        vector<int> bits = convert(num);
        for (int i = 0; i < 32; i++) {
            freq[i] += bits[i] * delta;
        }
    }

    vector<int> convert(int num) {
        vector<int> bits(32); 
        for (int i = 0; i < 32; i++) {
            bits[i] = (num >> i) & 1;
        }
        return bits;
    }
    
    int convertToNum(vector<int>& freq) {
        int result = 0;
        for (int i = 0; i < 32; i++) {
            if (freq[i] > 0) {
                result |= (1 << i);
            }
        }
        return result;
    }
};
