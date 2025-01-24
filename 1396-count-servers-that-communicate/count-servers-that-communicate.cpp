class Solution {
    public:
    int countServers(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int total = 0;
        int removes = 0;
        for(int i=0;i<n;i++){
            int cnt = 0;
            int idx = -1;
            for(int j=0;j<m;j++){
                if(grid[i][j]) cnt++,idx=j,total++;
            }
            if(cnt == 1){
                int cnt2 = 0;
                for(int k=0;k<n;k++){
                    if(grid[k][idx]) cnt2++;
                }
                if(cnt2==1) removes++;
            }
        }
        return total - removes;
    }
};