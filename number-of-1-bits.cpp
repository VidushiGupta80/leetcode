//Number of 1 Bits -> 04/30/2020 10:36
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        uint32_t a = 1;
        uint32_t ans = a & n;
        if(ans == a)
            count++;
        for(int i = 0; i < 31; i++)
        {
            a = a<<1;
            ans = a & n;
            if(ans == a)
                count++;
        }
        return count;
    }
};
