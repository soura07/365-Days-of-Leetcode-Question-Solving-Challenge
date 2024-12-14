#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        long long result = 0;
        int start = 0;  
        multiset<int> window;  
        
        for (int end = 0; end < nums.size(); ++end) {
            window.insert(nums[end]);
            
            while (*window.rbegin() - *window.begin() > 2) {
                window.erase(window.find(nums[start]));
                ++start;
            }
            
            result = result + (end - start + 1);
        }
        
        return result;
    }
};
