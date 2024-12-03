class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string result;
        int space_idx=0, n=spaces.size();
        for(int i=0; i<s.size(); ++i){
            if(space_idx<n and i==spaces[space_idx]){
                result+=' ';
                ++space_idx;
            }
            result+=s[i];
        }
        return result;
    }
};