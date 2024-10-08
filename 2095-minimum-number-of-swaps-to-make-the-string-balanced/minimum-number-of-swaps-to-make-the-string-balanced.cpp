class Solution {
public:
    int minSwaps(string s) {
        int imbalance = 0;
        for(const char &c : s){
            if(c == ']'){
                if(imbalance == 0){
                    imbalance++;
                }
                else{
                    imbalance--;
                }
            }
            else{
                imbalance++;
            }
        }
        return (imbalance + 1) / 2;
    }
};