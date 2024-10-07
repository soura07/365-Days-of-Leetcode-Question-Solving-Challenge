class Solution {
public:
    string DecimalToBinary(int num) {
        string str;
        while(num){
            str += (num & 1) ? '1' : '0';
            num >>= 1;
        }
        reverse(str.begin(), str.end());
        return str;
    }

    int maxGoodNumber(vector<int> & nums){
        string num1_binary = DecimalToBinary(nums[0]);
        string num2_binary = DecimalToBinary(nums[1]);
        string num3_binary = DecimalToBinary(nums[2]);


        vector<string> patterns;
        patterns.push_back(num1_binary + num2_binary + num3_binary);
        patterns.push_back(num1_binary + num3_binary + num2_binary);
        patterns.push_back(num2_binary + num1_binary + num3_binary);
        patterns.push_back(num2_binary + num3_binary + num1_binary);
        patterns.push_back(num3_binary + num1_binary + num2_binary);
        patterns.push_back(num3_binary + num2_binary + num1_binary);


        int max_value = 0;
        for(string & pattern : patterns){
            int decimal_value = stoi(pattern, NULL, 2);
            max_value = max(max_value, decimal_value);
        }

        return max_value;
    }
};