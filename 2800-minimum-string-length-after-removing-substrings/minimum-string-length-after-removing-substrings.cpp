class Solution {
public:
    int minLength(string& s) {
        int n = s.size();
        string st;
        st.push_back(s[0]);
        for (int i = 1; i < n; i++) {
            if (st.size() > 0 && ((st.back() == 'A' && s[i] == 'B') ||
                (st.back() == 'C' && s[i] == 'D'))) {
                st.pop_back();
            } else {
                st.push_back(s[i]);
            }
        }
        return st.size();
    }
};