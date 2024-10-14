class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) 
    {
        priority_queue<long long> max_heap(nums.begin(), nums.end());

        long long score = 0;

        for (int i = 0; i < k; i++) 
        {
            long long top = max_heap.top();
            max_heap.pop();
            score += top;
            long long newElement = (top + 2) / 3; 
            max_heap.push(newElement);
        }

        return score;
    }
};