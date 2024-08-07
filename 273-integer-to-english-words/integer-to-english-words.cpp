class Solution {
public:
    string digits[20] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    string tens[10] = {"Zero", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};    

    void helper(int valHigher, int valMedium, int valSlow, int &i, string &response, int* total, string actualVal, string prevVal){
            if(i==valHigher && total[valHigher]!=0){
                response+=digits[total[i]]+" "+prevVal+" ";
                if(total[valMedium]==0 && total[valSlow]==0) response+=actualVal+" ";                
            }

            else if(i==valMedium){
                if(total[valMedium]!=0 && total[valSlow]!=0){
                    int decena= total[valMedium]*10;
                    int unidad= total[valSlow];

                    if(unidad+decena!=0){
                        if(decena!=0){
                            if(unidad+decena<20)    response+= digits[unidad+decena]; 
                            else                    response+= tens[total[i]] + " "+ digits[total[i-1]]; 
                        } 
                        else response+= digits[unidad]+ " "; 
                        response+=" "+actualVal+" ";
                    }
                    i--;
                }

                else if(total[valMedium]!=0 && total[valSlow]==0)response+=tens[total[valMedium]]+" "+actualVal+" ";  
            }

            else if(i==valSlow && total[valSlow]!=0)response+=digits[total[valSlow]]+" "+actualVal+" ";
    }
    string numberToWords(int num) {

        if(num<20) return digits[num];
        
        int total[10];
        int cont=0;
        while(num>0){
            total[cont]=num%10;
            num=num/10;
            cont++;
        }

        string response ="";
        for(int i=cont-1;i>=0;i--){
            //Billion
            if(i==9)    response+= digits[total[i]]+ " Billion "; 

            //Million
            else if(i<=8 && i>5)    helper(8,7,6,i,response,total,"Million","Hundred");
            else if(i<=5 && i>2)    helper(5,4,3,i,response,total,"Thousand","Hundred");
            else if(i<=2 && i>=0)   helper(2,1,0,i,response,total,"","Hundred");
        }

        if (!response.empty() && response.back() == ' ') response.pop_back();
        if (!response.empty() && response.back() == ' ') response.pop_back();
        return response;
    }
};