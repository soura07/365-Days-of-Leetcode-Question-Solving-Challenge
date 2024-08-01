class Solution {
public:
    int countSeniors(vector<string>& details) {
        int cnt = 0;
        for(int i=0; i<details.size(); i++){
            string str = details[i];
            int a = (str[11] - '0') * 10;
            int b = (str[12] - '0');

            int check = a + b;

            if(check > 60 && (str[10] == 'M' || str[10] == 'F' || str[10] == 'O')){
                cnt++;
            }
            
        }
            return cnt;
    }
};