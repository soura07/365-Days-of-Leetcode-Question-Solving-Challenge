class Solution {
public:
    struct robot {
        int pos;
        int health;
        char dir;
    };

    static bool comp(struct robot &a, struct robot &b) {
        return a.pos < b.pos;
    }

    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        vector<struct robot> arr;
        unordered_map<int, int> mp;
        int n = positions.size();

        for (int i = 0; i < n; i++) {
            struct robot it;
            it.pos = positions[i];
            it.health = healths[i];
            it.dir = directions[i];       
            arr.push_back(it);
            mp[it.pos] = i;
        }

        sort(arr.begin(), arr.end(), comp);

        stack<struct robot> st;

        for (int i = 0; i < n; i++) {
            if (st.empty()) {
                st.push(arr[i]);
            } else {
                if (arr[i].dir == 'R') {
                    st.push(arr[i]);
                } else {
                    int fg = 0;
                    while (!st.empty() && st.top().dir == 'R') {
                        if (arr[i].health > st.top().health) {
                            arr[i].health--;
                            st.pop();
                        } else if (arr[i].health == st.top().health) {
                            fg = 1;
                            st.pop();
                            break;
                        } else {
                            st.top().health--;
                            fg = 1;
                            break;
                        }
                    }
                    if (fg == 0) {
                        st.push(arr[i]);
                    }
                }
            }
        }

        vector<int> ans(n, 0);

        while (!st.empty()) {
            ans[mp[st.top().pos]] = st.top().health;
            st.pop();
        }

        vector<int> finali;
        for (auto e : ans) {
            if (e > 0) finali.push_back(e);
        }

        return finali;
    }
};