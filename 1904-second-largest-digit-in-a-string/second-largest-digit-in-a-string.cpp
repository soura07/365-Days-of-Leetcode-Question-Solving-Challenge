class Solution {
public:
    int secondHighest(string s) {
        int largest = -1;
        int second_largest = -1;

        for (char ch : s) {
            if (isdigit(ch)) {
                int digit = ch - '0';

                if (digit > largest) {
                    second_largest = largest;
                    largest = digit;
                } else if (digit > second_largest && digit < largest) {
                    second_largest = digit;
                }
            }
        }

        return second_largest;
    }
};