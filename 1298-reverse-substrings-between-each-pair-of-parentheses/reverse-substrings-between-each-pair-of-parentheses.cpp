class Solution {
public:
    static string reverseParentheses(string& s) {
        int n=s.size(), level = 0;
        vector<short> next(n, -1);
        vector<int> stack;

        for (int i = 0; i < n; i++) {
            bool odd=level&1;
            switch (s[i]) {
                case '(':
                    stack.push_back(i);
                    level++;
                    break;
                case ')': { 
                    int j = stack.back();
                    stack.pop_back();
                    next[i]=j; //wormhole
                    next[j]=i; //wormhole
                    level--;
                    break;
                }
                default://next char is upon the pairity of level
                    next[i]=i+(odd?-1:1);
            }
        }

    //    print(next);

        string ans;
        for(int i=0, idx=0, step=1; i<n; i++){
            char c=s[idx];
            int j=next[idx];
            if (c=='(' || c==')') step*=-1, idx=j+step;
            else ans.push_back(c), idx=j;
        }
        
        return ans;
    }
};