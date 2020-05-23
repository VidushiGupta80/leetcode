//Happy Number -> 05/23/2020 18:01
class Solution {
public:
    bool isHappy(int n) {
        long x = 0;
        while(true)
        {
            while(true)
            {
                int temp = n % 10;
                n = n / 10;
                x += (temp * temp);
                if(n == 0)
                    break;
            }
            if(x < 10)
            {
                if(x == 1 || x == 7)
                {
                 return true;
                    
                }
                    
                else 
                    return false;
            }
            else
            {
                n = x;
                x = 0;
            }
        }
    }
};
