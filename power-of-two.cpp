//Power of Two -> 05/01/2020 13:51
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0)
            return false;
        // if(n & (n - 1) == 0)
        //     return true;
        // return false;
        return log2(n) - (int)log2(n) == 0 ? true : false; 
        // int num = log2(n);
        // int nearestPower = pow(2, num);
        // if(n == nearestPower)
        //     return true;
        // else
        //     return false;
    }
};
