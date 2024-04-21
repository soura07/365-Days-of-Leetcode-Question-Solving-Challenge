class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> upper(26, -1), lower(26, -1);
        for(int i=0; i<word.size();i++){
          char ch = word[i];
          if(islower(ch))
            lower[ch - 'a'] = i;
          else if(upper[ch - 'A'] == -1)
            upper[ch - 'A'] = i;
        }
        int result = 0;
        for(int ch=0; ch < 26; ch++){
          if(lower[ch] != -1 and upper[ch] != -1 and upper[ch] > lower[ch]){
            result++;
          }
        }
        return result;
    }
};