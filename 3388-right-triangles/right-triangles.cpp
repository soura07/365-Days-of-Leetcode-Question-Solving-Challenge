class Solution {
public:
    long long numberOfRightTriangles(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        vector<long long> rowcnt(n, 0), colcnt(m, 0);

        for(int i=0; i<n; i++){
          int cnt = 0;
          for(int j=0; j<m; j++){
            if(grid[i][j] == 1) cnt++;
          }
          rowcnt[i] = cnt;
        }

        for(int j=0; j<m; j++){
          int cnt = 0;
          for(int i=0; i<n; i++){
              if(grid[i][j] == 1) cnt++;
          }
          colcnt[j] = cnt;
        }

        long long ans = 0;
        for(int i=0; i<n; i++){
          for(int j=0; j<m; j++){
            if(grid[i][j] == 1){
              ans = ans + (rowcnt[i]-1) *(colcnt[j]-1);
            }
          }
        }
        return ans;
    }
};