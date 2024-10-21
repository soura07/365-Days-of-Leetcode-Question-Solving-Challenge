class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        map<int, int> mp;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                mp[grid[i][j]]++;
            }
        }
        int a = -1, b = -1;
        for(int i=0; i<= n*n; i++){
            if(mp[i] == 2){
                a = i;
            }
            else{
                if(mp[i] == 0){
                    b = i;
                }
            }
        }
        vector<int> ans;
        ans.push_back(a);
        ans.push_back(b);
        return ans;
    }
};