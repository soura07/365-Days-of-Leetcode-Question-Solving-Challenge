class Solution {
public:
  
    vector<int> LPS(string pat) {
        int n = pat.size();
        vector<int> lps(n, 0);
        int i = 1, j = 0;

        while (i < n) {
            if (pat[i] == pat[j]) {
                lps[i++] = ++j;
            } else {
                if (j == 0) {
                    lps[i++] = 0;
                } else {
                    j = lps[j - 1];
                }
            }
        }
        return lps;
    }

    string shortestPalindrome(string s) {
        if (s.empty()) return "";

        string revs = s;
        reverse(revs.begin(), revs.end());
        string combined = s + "#" + revs;

 
        vector<int> lps = LPS(combined);

        int len = lps.back();
        string to_add = s.substr(len);  
        reverse(to_add.begin(), to_add.end());

        return to_add + s; 
    }
};