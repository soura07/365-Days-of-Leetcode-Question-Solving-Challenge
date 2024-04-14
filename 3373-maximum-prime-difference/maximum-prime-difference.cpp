class Solution {
public:
  
  void sieve(vector<int> &prime){
    prime[0] = prime[1] = false;

    for(int i=2; i*i <= 104; i++){
      if(prime[i]){
        for(int j=i*i; j<= 104; j = j+i){
          prime[j] = false;
        }
      }
    }
  }
    int maximumPrimeDifference(vector<int>& nums) {
      vector<int> prime(105, true); // Corrected type and initialization

      sieve(prime); // Passing prime vector to the sieve function

      int ans = 0, firstId = -1;

      for(int i=0; i<nums.size(); i++){
        if(prime[nums[i]]){
          if(firstId == -1){
            firstId = i;
          }
          else{
            ans = i - firstId;
          }
        }
      }
      return ans;
    }
};
