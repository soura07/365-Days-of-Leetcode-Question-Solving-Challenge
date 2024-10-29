class Solution {
public:
    int m,n;
    vector<int> directions = {-1, 0, 1};
    int DFS(int row, int col, vector<vector<int>>& grid, vector<vector<int>> &t){
        if(t[row][col] != -1){
            return t[row][col];
        }
        int moves = 0;
        for(int &dir : directions){
            int newRow = row + dir;
            int newCol = col + 1;

            if(newRow >= 0 && newRow < m && newCol >= 0 && newCol < n && grid[newRow][newCol] > grid[row][col]){
                moves = max(moves,1 + DFS(newRow, newCol, grid, t));
            }
        }
        return t[row][col] = moves;

    }
    int maxMoves(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        int result = 0;
        vector<vector<int>> t(m, vector<int>(n, -1));
        for(int row = 0; row<m; row++){
            result = max(result, DFS(row, 0, grid,t));
        }

        return result;
    }
};