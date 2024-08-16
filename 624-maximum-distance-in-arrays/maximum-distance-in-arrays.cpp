class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int MAX = arrays[0].back();
        int MIN = arrays[0].front();

        int result = 0;
        for(int i=1; i<arrays.size(); i++){
            int currMaxi = arrays[i].back();
            int currMini = arrays[i].front();

            result = max({result, abs(currMaxi - MIN), abs(currMini - MAX)});

            MAX = max(MAX, currMaxi);
            MIN = min(MIN, currMini);

        }
        return result;
    }
};