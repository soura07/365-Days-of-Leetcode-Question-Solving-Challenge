class Solution {
public:
    bool check(unordered_map<int, vector<int>> &mp, int S, int D,vector<bool> &visited){
      if(S == D)
        return true;
      if(visited[S] == true)
        return false;
      
      visited[S] = true;

      for(auto &node : mp[S]){
        if(check(mp, node, D, visited) == true){
          return true;
        }
        
      }
      return false;
    } 
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int, vector<int>> mp;

        for(vector<int> &edge : edges){
          int u = edge[0];
          int v = edge[1];

          mp[u].push_back(v);
          mp[v].push_back(u);
        }

        vector<bool> visited(n, false);
        return check(mp, source, destination, visited);
    }
};