class Solution {
public:
    int passThePillow(int n, int time) {
        int round = time/(n-1);
        int rem = time%(n-1);

        if(round%2){
            return n-rem;
        }
        else{
            return rem+1;
        }
    }
};