class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        long long ans = 0; 
        int curr = 0; 
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] % 2 == 1) {
                curr = i - curr + 1;
            }
            ans += curr;
        }
        long long mod = pow(10,9) + 7;
        return ans % mod;
    }
};