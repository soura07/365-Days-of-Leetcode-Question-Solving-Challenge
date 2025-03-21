class Solution {
public:
    int minChanges(string s) {
        const int n = s.size();
        int cnt = 0;
        for(int i=0; i<n; i+=2){
            cnt = cnt + (s[i] != s[i+1]);
        }
        return cnt;
    }
};