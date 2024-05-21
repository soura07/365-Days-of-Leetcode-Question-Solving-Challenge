class Solution {
public:
    typedef long long ll;
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        if(nums.empty()){
            return ans;
        }
        int n = nums.size();
        sort(nums.begin(), nums.end());

        for(int i=0; i<n;i++){
            for(int j= i+1; j<n;j++){
                ll target_2 = (ll)target - nums[j] - nums[i];
                int front = j + 1;
                int back = n - 1;

                while(front < back){
                    int two_sum = nums[front] + nums[back];

                    if(two_sum < target_2) front++;
                    
                    else if(two_sum > target_2) back--;

                    else{
                        vector<int> quodruplet(4, 0);
                        quodruplet[0] = nums[i];
                        quodruplet[1] = nums[j];
                        quodruplet[2] = nums[front];
                        quodruplet[3] = nums[back];
                        ans.push_back(quodruplet);

                        while(front < back && nums[front] == quodruplet[2]) ++front;

                        while(front < back && nums[back] == quodruplet[3]) --back;

                    }

                }

                while(j + 1 < n && nums[j+1] == nums[j]) ++j;
            }

            while(i + 1 < n && nums[i+1] == nums[i]) ++i;
        }
        return ans;
    }
};