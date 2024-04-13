class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        bool arr[32]={0};
        int index=0;
        while(n) arr[index++]=n%2,n/=2;
        for(int i=0;i<32;i++)n+=arr[i]*pow(2,31-i);
        return n;
    }
};