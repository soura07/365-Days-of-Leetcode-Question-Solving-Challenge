class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> mp(k, 0);
        for(auto& num : arr){
            int reminder = (num % k + k) % k;
            mp[reminder]++;
        }

        if(mp[0] % 2 != 0){
            return false;
        }

        for(int i=1; i<= k/2; i++){
            int x = k - i;
            if(mp[i] != mp[x]){
                return false;
            }
        }
        return true;
    }
};