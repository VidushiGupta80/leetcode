//Binary Number with Alternating Bits -> 04/30/2020 12:26
class Solution {
public:
    bool hasAlternatingBits(int n) {
        int bits = log(n) / log(2);
        int ans = 0;
        if(n % 2 == 0)
        {
            for(int i = 1; i <= bits; i+= 2)
            {
                ans += powl(2, i);
            }
        }
        else
        {
            for(int i = 0; i <= bits; i+= 2)
            {
                ans += powl(2, i);
            }
        }
        if(n == ans)
            return true;
        else 
            return false;
    }
};
