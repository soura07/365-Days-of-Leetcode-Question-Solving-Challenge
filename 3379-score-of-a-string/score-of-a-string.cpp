class Solution {
public:
    int scoreOfString(string s) {
        int scc = 0;
        for(int i=0; i<s.length()-1; i++){
            scc = scc + abs(s[i] - s[i+1]);
        }
        return scc;
    }
};