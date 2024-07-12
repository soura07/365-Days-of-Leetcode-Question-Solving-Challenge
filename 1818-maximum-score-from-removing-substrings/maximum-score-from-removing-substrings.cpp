class Solution {
public:

    int maximumGain(string s, int x, int y) {
        stack<char> st;
        int ans = 0, a1 = 0, b1 = 0;
        if (x > y) {
            for (char c : s) {
                if (c == 'b' && !st.empty() && st.top() == 'a') {
                    st.pop();
                    ans += x;
                } else {
                    st.push(c);
                }
            }
        } 
        else {
            for (char c : s) {
                if (c == 'a' && !st.empty() && st.top() == 'b') {
                    st.pop();
                    ans += y;
                } 
                else {
                    st.push(c);
                }
            }
        }
        string remaining;
        while (!st.empty()) {
            remaining.push_back(st.top());
            st.pop();
        }
        reverse(remaining.begin(), remaining.end());

    
        for (char c : remaining) {
            if (x > y) {
                if (c == 'a' && !st.empty() && st.top() == 'b') {
                    st.pop();
                    ans += y;
                } 
                else {
                    st.push(c);
                }
            } 
            else {
                if (c == 'b' && !st.empty() && st.top() == 'a') {
                    st.pop();
                    ans += x;
                } 
                else {
                    st.push(c);
                }
            }
        }

        return ans;
    }



};