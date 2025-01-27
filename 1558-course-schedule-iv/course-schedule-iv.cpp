class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) 
    {
         set<pair<int, int>> prereqSet;
    
    for (const auto& prereq : prerequisites) {
        prereqSet.insert({prereq[0], prereq[1]});
    }

    for (int k = 0; k < numCourses; k++) {
        for (int i = 0; i < numCourses; i++) {
            for (int j = 0; j < numCourses; j++) {
                if (prereqSet.count({i, k}) && prereqSet.count({k, j})) {
                    prereqSet.insert({i, j});  
                }
            }
        }
    }

    vector<bool> result;
    for (const auto& query : queries) {
        result.push_back(prereqSet.find({query[0], query[1]}) != prereqSet.end());
    }
    
    return result;
    }
};