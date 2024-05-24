class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int maxlen = 0;
        for(int i=0; i<n; i++){
            int hash[255];
            memset(hash, 0, sizeof(hash));
            for(int j=i; j<n; j++){
                if(hash[s[j]] == 1) break;
                int len = j - i + 1;
                maxlen = max(len, maxlen);
                hash[s[j]] = 1;
            }
        
        }
        return maxlen;
    }
};