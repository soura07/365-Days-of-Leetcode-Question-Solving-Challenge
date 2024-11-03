class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size() != goal.size()){
            return false;
        }
        else{
            for(int i=0; i<s.length(); i++){
                string st1 = s.substr(s.length()-1, 1);
                string st2 = s.substr(0, s.length()-1);
                string st3 = st1 + st2;

                if(st3 == goal){
                    return true;
                }

                s = st3;
            }
        }
        return false;
    }
};