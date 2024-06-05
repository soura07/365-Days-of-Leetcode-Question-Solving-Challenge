class Solution {
public:
    void countfill(string& word, int cnt[26]){
        for(char &ch : word){
            cnt[ch - 'a']++;
        }
    }
    vector<string> commonChars(vector<string>& words) {
        vector<string> result;
        int n = words.size();

        int cnt[26] = {0};

        countfill(words[0], cnt);

        for(int i=1; i<n; i++){
            int temp[26] = {0};

            countfill(words[i], temp);;

            for(int j=0; j<26; j++){
                cnt[j] = min(cnt[j], temp[j]);
            }
        }


        for(int i=0; i<26; i++){
            int c = cnt[i];
            while(c--){

                result.push_back(string(1, i +'a'));
            }
        }
        return result;

    }
};