//Arranging Coins -> 04/16/2020 18:03
class Solution {
public:
    int arrangeCoins(int n) {
        long int x = 1;
        while(true)
        {
            if(x * (x + 1) / 2  < n)
                x++;
            else if(x * (x + 1) / 2  == n)
                return x;
            else
                return x - 1;
        }
    }
};
