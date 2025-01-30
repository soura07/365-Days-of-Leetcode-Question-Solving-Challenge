class Solution {
public:
    int countLevels(int ind, vector<vector<int>>& adj, int n) {
        queue<int> q;
        vector<bool> Visited(n + 1, false);
        q.push(ind);
        Visited[ind] = true;

        int level = 0;
        while (!q.empty()) {
            int currentSize = q.size();
            level++;
            while (currentSize--) {
                int current = q.front();
                q.pop();
                for (auto& nbr : adj[current]) {
                    if (!Visited[nbr]) {
                        Visited[nbr] = true;
                        q.push(nbr);
                    }
                }
            }
        }

        return level;
    }

    bool isBiPartite(int index, vector<vector<int>>& adj, int n, vector<int>& state) {
        queue<int> q;
        state[index] = 1;
        q.push(index);
        while (!q.empty()) {
            int current = q.front();
            q.pop();
            for (auto& entry : adj[current]) {
                if (state[entry] == 0) {
                    state[entry] = -state[current];
                    q.push(entry);
                } else if (state[entry] == state[current]) {
                    return false;
                }
            }
        }
        return true;
    }

    bool checkBipartite(vector<vector<int>>& adj, int n, vector<int>& state) {
        for (int i = 1; i <= n; i++) {
            if (state[i] == 0 && !isBiPartite(i, adj, n, state)) {
                return false;
            }
        }
        return true;
    }

    int findMaxi(int i, vector<vector<int>>& adj, vector<bool>& Visited, vector<int>& maxi, int n) {
        int maximum = maxi[i];
        queue<int> q;
        q.push(i);
        Visited[i] = true;

        while (!q.empty()) {
            int currentSize = q.size();
            while (currentSize--) {
                int current = q.front();
                q.pop();
                for (auto& nbr : adj[current]) {
                    if (!Visited[nbr]) {
                        Visited[nbr] = true;
                        q.push(nbr);
                        maximum = max(maximum, maxi[nbr]);
                    }
                }
            }
        }

        return maximum;
    }

    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n + 1);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<int> state(n + 1, 0);
        bool Bipartite = checkBipartite(adj, n, state);
        if (!Bipartite) return -1;
        vector<int> maxi(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            maxi[i] = countLevels(i, adj, n);
        }

        vector<bool> Visited(n + 1, false);
        int result = 0;
        for (int i = 1; i <= n; i++) {
            if (!Visited[i]) {
                result += findMaxi(i, adj, Visited, maxi, n);
            }
        }

        return result;
    }
};