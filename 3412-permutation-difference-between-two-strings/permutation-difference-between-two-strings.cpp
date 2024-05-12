class Solution {
public:
    int findPermutationDifference(string s, string t) {
        unordered_map<char, int> sind;
        int pdiff = 0;
        for(int i=0; i<s.length(); i++){
            sind[s[i]] = i;
        }
        for(int i=0; i<t.length(); i++){
            pdiff = pdiff + abs(sind[t[i]] - i);
        }
        return pdiff;
    }
};