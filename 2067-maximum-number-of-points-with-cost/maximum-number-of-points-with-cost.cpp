class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        
        int m = points.size(), n = points[0].size();
        long long currMax;
        vector<long long> maxPoints(n), rightRow(n);
        for(auto row: points){
            currMax = 0;

            for(int j = n-1; j >= 0; j--){
                currMax = max(currMax, maxPoints[j]);
                rightRow[j] = currMax--;
            }

            currMax = 0; 
            for(int j = 0; j < n; j++){
                currMax = max(currMax, maxPoints[j]);

                maxPoints[j] = max(currMax--, rightRow[j]) + row[j];
            }
        }
        
        return *max_element(maxPoints.begin(), maxPoints.end());
    }
};