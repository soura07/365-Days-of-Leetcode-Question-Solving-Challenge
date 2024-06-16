class Solution {
public:
    typedef long long ll;
    int countCompleteDayPairs(vector<int>& hours) {
        ll ans = 0;
        unordered_map<int, int> mp;
        for(auto hour : hours){
            ans = ans + mp[(24 - hour%24) % 24];
            mp[hour%24]++;
        }
        return ans;
    }
};