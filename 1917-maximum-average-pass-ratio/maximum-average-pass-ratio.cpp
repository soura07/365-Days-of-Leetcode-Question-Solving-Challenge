class Solution {
public:
    double calculateAve(int pass,int total){
        double curave= double(pass)/total;
        double nextave=double(pass+1)/(total+1); 
        return abs(nextave-curave);
    }
    void heapPush(priority_queue<pair<double,int>> &maxheap,double val,int classn){
        maxheap.push(make_pair(val,classn)); 
    }
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pair<double,int>> maxheap;
        for(int i=0;i<classes.size();i++){
            double cal=calculateAve(classes[i][0],classes[i][1]); 
            heapPush(maxheap,cal,i);
        }
        while(extraStudents--){
            pair<double,int> temp=maxheap.top();
            maxheap.pop();
            int index=temp.second;
            classes[index][0]++;
            classes[index][1]++; 
            double cal=calculateAve(classes[index][0],classes[index][1]);
            heapPush(maxheap,cal,index); 
        }
        double ans=0.0; 
        for(int i=0;i<classes.size();i++){
            double temp=double(classes[i][0])/classes[i][1]; 
            ans+=temp;
        }
        return ans/classes.size(); 

    }
};