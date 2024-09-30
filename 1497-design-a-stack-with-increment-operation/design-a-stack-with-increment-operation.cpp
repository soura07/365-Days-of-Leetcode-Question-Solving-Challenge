class CustomStack {
    vector<int> v;
    vector<pair<int,int>> com;
    int maxS = INT_MIN;
public:
    CustomStack(int maxSize) {
        maxS=maxSize;
    }
    
    void push(int x) {
        if(v.size() >= maxS) return;
        v.push_back(x);
    }
    
    int pop() {
        if(v.size() == 0) return -1;
        int res = v.back();

        for(pair<int,int> p:com){
            if(v.size() == p.first){
                res+=p.second;
            }
        }
        for(int i=0;i<com.size();i++){
            com[i].first = min((int)com[i].first,(int)(v.size()-1));
        }

        v.pop_back();
        return res;
    }
    
    void increment(int k, int val) {
        com.push_back({min((int)k,(int)v.size()),val});
    }
};