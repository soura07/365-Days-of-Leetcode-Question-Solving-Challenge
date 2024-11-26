class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        bitset<100> b; for (int i = n; i--;) b[i] = 1;
        for (auto e: edges) b[e[1]] = 0;
        return b.count() == 1 ? b._Find_first() : -1;
    }
};