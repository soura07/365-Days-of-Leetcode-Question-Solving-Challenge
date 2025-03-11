class Solution {
public:
    long long countOfSubstrings(string word, int k) {
        int n = word.length();

        auto isVowel = [&](char a) {
            return a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u';
        };

        auto func = [&](int k) -> long long {
            int con = 0;
            unordered_map<char, int> vow;
            long long cnt = 0;
            int l = 0, r = 0;
            while(r < n) {
                if(isVowel(word[r])) vow[word[r]]++;
                else con++;
                while(vow.size() == 5 && con >= k) {
                    cnt += (n - r);
                    if(!isVowel(word[l])) con--;
                    else {
                        vow[word[l]]--;
                        if(vow[word[l]] == 0) {
                            vow.erase(word[l]);
                        }
                    }
                    l++;
                }
                r++;
            }
            return cnt;
        };

        return func(k) - func(k + 1);
    }
};