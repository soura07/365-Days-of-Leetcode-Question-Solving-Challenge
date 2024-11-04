class Solution {
public:
    string compressedString(string word) {
        int n = word.length();
        ostringstream comp;
        int i = 0;
        while(i < n){
            int cnt = 0;
            char ch = word[i];
            while(i < n && cnt < 9 && word[i] == ch){
                cnt++;
                i++;
            }
            comp << cnt << ch;
            
        }
        return comp.str();
    }
};