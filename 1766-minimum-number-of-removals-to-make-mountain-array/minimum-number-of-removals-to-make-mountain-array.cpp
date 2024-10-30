class Solution {
public:
    void calc_left(vector<int>& nums, int i, int n, vector<int> &left){
        int ele = 1; 
        while(ele < n) {
            left[ele] = ele;
            for(int j = ele - 1; j >= 0; j--) {
                if(nums[ele] > nums[j]) {
                   
                    left[ele] = min(ele - j - 1 + left[j], left[ele]);
                }
            }
            ele++;
        }
    }

    void calc_right(vector<int>& nums, int i, int n, vector<int> &right){
        int ele = n - 2;  
        while(ele >= 0) {
            right[ele] = n - ele - 1; 
            for(int j = ele + 1; j < n; j++) {
                if(nums[ele] > nums[j]) {
                    right[ele] = min(j - ele - 1 + right[j], right[ele]);
                }
            }
            ele--;
        }
    }

    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();  
        vector<int> left(n, 0);  
        vector<int> right(n, 0);  
        int ans = INT_MAX; 

        calc_left(nums, 0, n, left);
        calc_right(nums, 0, n, right);

        for(int i = 1; i < n - 1; i++) {
            if(left[i] != i && right[i] != n - i - 1)
                ans = min(ans, left[i] + right[i]);
        }
        return ans;
    }
};