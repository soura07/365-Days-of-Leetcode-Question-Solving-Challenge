class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        long long Atribute = 0;
        multiset <long long> start;
        
        for(int j=0;j<nums.size();j++)
            start.insert(nums[j]);
            
        while(start.size()>1 && *(start.begin())<k)
        {
            long long T1 = *(start.begin());
            start.erase(start.begin());
            long long T2 = *(start.begin());
            start.erase(start.begin());
            T1 *= 2;
            T1 += T2;
            start.insert(T1);
            Atribute++;
        }
        return Atribute;
     
    }
};