class Solution {
public:
    bool areSentencesSimilar(string s1, string s2) {
        
        if(s1.size() > s2.size())return areSentencesSimilar(s2, s1);

        bool l_common = false, r_common = false;
        int n1 = s1.size(), n2 = s2.size(), i_1 = 0, i_2 = 0, j_1 = n1 - 1, j_2 = n2 - 1;

        while(i_1 < n1){
            int i = i_1;
            string str_1 = "", str_2 = "";
            
            while(i_1 < n1){
                if(s1[i_1] != ' ')str_1 += s1[i_1++];
                else {i_1++; break;}
            }

            while(i_2 < n2){
                if(s2[i_2] != ' ')str_2 += s2[i_2++];
                else {i_2++; break;}
            }

            if(str_1 != str_2){i_1 = i; break;}
        }

        if(i_1 == n1)return true;

        while(i_1 <= j_1){
            int j = j_1;
            string str_1 = "", str_2 = "";
            
            while(j_1 >= i_1){
                if(s1[j_1] != ' ')str_1 += s1[j_1--];
                else {j_1--; break;}
            }

            while(j_2 >= 0){
                if(s2[j_2] != ' ')str_2 += s2[j_2--];
                else {j_2--; break;}
            }

            if(str_1 != str_2){j_1 = j; break;} 
        }

        return j_1 + 1 == i_1;
    }
};