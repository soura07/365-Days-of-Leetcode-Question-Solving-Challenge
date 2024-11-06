class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> arr(n);

        for(int i=0; i<n; i++){
            int num = nums[i];
            int count = 0;
            while(num > 0) {
                count = count + (num & 1);
                num = num/2;
            }
            arr[i] = {nums[i], count};
        }

        for(int i=0; i< n-1; i++){
            for(int j=0; j<n-1-i; j++){
                if(arr[j].first > arr[j+1].first){
                    if(arr[j].second != arr[j+1].second){
                        return false;
                    }
                    swap(arr[j], arr[j+1]);
                }
            }
        }
        return true;
    }
};