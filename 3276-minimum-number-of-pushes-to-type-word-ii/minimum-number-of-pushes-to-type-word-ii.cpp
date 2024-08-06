class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char, int> um;
        for (char c : word) {
            um[c]++;
        }

        vector<int> count;
        for (auto x : um) {
            count.push_back(x.second);
        }

        sort(count.rbegin(), count.rend());

        int ans = 0, row = 1;
        for (int i = 0; i < count.size(); i++) {
            if (i > 7 && i % 8 == 0) {
                row++;
            }
            ans += row * count[i];
        }

        return ans;
    }
};