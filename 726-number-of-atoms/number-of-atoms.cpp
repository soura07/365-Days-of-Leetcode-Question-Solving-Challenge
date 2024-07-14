class Solution {
    int getSub(int& i, int& n, string& s){
        string tmp="";
        while(i<n && '0'<=s[i] && s[i]<='9'){
            tmp.push_back(s[i]);
            i++;
        }
        if(tmp.size()>0) return stoi(tmp);
        else return 1;
    }
public:
    string countOfAtoms(string s) {
        int n=s.size();
        stack<int> st;
        unordered_map<int,int> util;
        for(int i=0;i<n;i++){
            if(s[i]=='(') st.push(i);
            else if(s[i]==')'){
                util[st.top()]=i;
                util[i]=st.top();
                st.pop();
            }
        }
        map<string,int> mp;
        int i=0;
        int sub=1;
        stack<pair<int,int>> bPow;
        while(i<n){
            if('A'<=s[i] && s[i]<='Z'){
                string elm="";
                elm.push_back(s[i]); i++;
                if(i<n && 'a'<=s[i] && s[i]<='z'){
                    elm.push_back(s[i]);
                    i++;
                }
                int ownSub=getSub(i,n,s)*sub;
                if(mp.count(elm)) mp[elm]+=ownSub;
                else mp[elm]=ownSub;
            }
            else if(s[i]=='('){
                int open=i;
                i=util[i]; i++;
                int ownSub=getSub(i,n,s);
                if(ownSub>1) {
                    sub*=ownSub;
                    bPow.push({ownSub,i});
                }
                i=open; i++;
            }
            else if(s[i]==')' && !bPow.empty()){
                sub/=bPow.top().first;
                i=bPow.top().second;
                bPow.pop();
            }
            else i++;
        }
        string ans="";
        for(auto i:mp){
            ans+=(i.first);
            if(i.second>1) ans+=to_string(i.second);
        }
        return ans;
    }
};