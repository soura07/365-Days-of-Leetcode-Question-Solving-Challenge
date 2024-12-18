class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        stack<int> st;
        vector<int> res(begin(prices), end(prices));
        for(int i=0; i< n; i++){

            while(!st.empty() && prices[i] <= prices[st.top()]){
                res[st.top()] -= prices[i];
                st.pop();
            }
            st.push(i);
        }

        return res;
    }
};