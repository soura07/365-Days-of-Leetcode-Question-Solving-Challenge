class Solution {
public:
    bool possibleToPlace(int force, vector<int> & position, int m){
        int prev = position[0];
        int countBalls = 1;

        for(int i=1; i < position.size(); i++){
            int curr = position[i];

            if(curr - prev >= force){
                countBalls++;
                prev = curr;
            }

            if(countBalls == m)
                break;
        }

        return countBalls == m;
    }
    int maxDistance(vector<int>& position, int m) {
        int n = position.size();
        sort(position.begin(), position.end());

        int minForce = 1;
        int maxForce = position[n-1] - position[0];

        int res = 0;
        while(minForce <= maxForce){
            int midForce = minForce + (maxForce - minForce)/2;

            if(possibleToPlace(midForce, position, m)){
                res = midForce;
                minForce = midForce + 1;
            }
            else{
                maxForce = midForce - 1;
            }
        }
        return res;

    }
};