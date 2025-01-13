class Solution {
public:
    int minimumLength(string s) {
        int n = s.length();
        vector<int> frq(26,0);

        for(int i=0; i<n; i++){
            frq[s[i] - 'a'] += 1;
            
            if(frq[s[i] - 'a'] == 3){
                frq[s[i] - 'a'] -= 2;
            }
        }

        int res = 0;
        for(int i=0; i<26; i++){
            if(frq[i] == 0) continue;
            res += frq[i];
        }
        return res;
    }
};