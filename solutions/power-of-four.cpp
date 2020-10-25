//Power of Four -> 08/05/2020 13:40
class Solution {
public:
    bool isPowerOfFour(int num) {
        if(num == 0)
            return false;
        if(num == 1)
            return true;
        int j = 1;
        for(int i = 1; i < 16; i++)
        {
            j = j << 2;
            if((num | j) == j)
                return true;
            
        }
        return false;
    }
};
