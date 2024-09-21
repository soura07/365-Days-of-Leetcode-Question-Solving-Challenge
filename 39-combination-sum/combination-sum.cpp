class Solution {
public:
    void findCombination(int idx, int target, vector<int>&candidates, vector<vector<int>> &ans, vector<int> &DS){
        if(idx == candidates.size()){
            if(target == 0){
                ans.push_back(DS);
            }
            return;
        }

        if(candidates[idx] <= target){
            DS.push_back(candidates[idx]);
            findCombination(idx, target - candidates[idx], candidates, ans, DS);
            DS.pop_back();
        }
        findCombination(idx+1, target, candidates, ans, DS);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> DS;
        findCombination(0, target, candidates, ans, DS);
        return ans;
    }
};