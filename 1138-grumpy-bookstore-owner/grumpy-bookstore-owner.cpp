class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        int total_satisfied = 0;
        for (int i = 0; i < n; ++i) {
            if (grumpy[i] == 0) {
                total_satisfied += customers[i];
            }
        }
        
        int additional_satisfied = 0;
        for (int i = 0; i < minutes; ++i) {
            if (grumpy[i] == 1) {
                additional_satisfied += customers[i];
            }
        }
        
        int max_additional_satisfied = additional_satisfied;
        
        for (int i = minutes; i < n; ++i) {
            if (grumpy[i] == 1) {
                additional_satisfied += customers[i];
            }
            if (grumpy[i - minutes] == 1) {
                additional_satisfied -= customers[i - minutes];
            }
            max_additional_satisfied = max(max_additional_satisfied, additional_satisfied);
        }
        
        return total_satisfied + max_additional_satisfied;
    }
};