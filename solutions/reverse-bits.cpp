//Reverse Bits -> 04/30/2020 11:44
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t a = 1;
        uint32_t ans = 0;
        uint32_t o = 1;
        uint32_t result = 0;
        int j;
        for(int i = 0; i < 32; i++)
        {
            a = a << i;
            ans = n & a;            
            if(ans == a)
            {
                j = 31 - i;
                o = o << j;
                result = result | o;                
            }
            a = 1;
            o = 1;
        }
        return result;        
    }
};
