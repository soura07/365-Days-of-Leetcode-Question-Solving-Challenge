class Solution {
public:
    int dr[4]={1,-1,0,0};
    int dc[4]={0,0,1,-1};
    typedef pair<int,int> pii;
    int minimumObstacles(vector<vector<int>>& grid) {
      int m=grid.size(),n=grid[0].size();

      vector<vector<int>> dist(m,vector<int>(n,INT_MAX));

      dist[0][0]=0;

      deque <pii> dq;

      dq.push_back({0,0});

      while(!dq.empty()){
        int r=dq.front().first;
        int c=dq.front().second;

        dq.pop_front();


        for(int i=0;i<4;i++){
            int nr=r+dr[i],nc=c+dc[i];

            if(nr>=0 && nr<m && nc<n && nc>=0 &&  dist[nr][nc]>dist[r][c]+grid[nr][nc]){
                   dist[nr][nc]=dist[r][c]+grid[nr][nc];

                   if(grid[nr][nc]){
                    dq.push_back({nr,nc});

                   }

                   else 
                   dq.push_front({nr,nc});


            }
        }
      }


      return dist[m-1][n-1];



    }
};