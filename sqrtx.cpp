//Sqrt(x) -> 05/15/2020 20:24
class Solution {
public:
    int mySqrt(int x) {
        vector<int> num;
        if(x == 1 || x == 2 || x == 3)
            return 1;
        long left = 1, right = x - 1, mid;
        while(left <= right)
        {
            mid = left + (right - left)/2;
            if(mid * mid > x && (mid - 1) * (mid - 1) <= x)
            {
                return mid - 1;
            }
            else if(mid * mid <= x && (mid + 1) * (mid + 1) > x)
            {
                return mid;
            }
            else if(mid * mid > x)
            {
                right = mid - 1;
            }
            else if(mid * mid < x)
            {
                left = mid + 1;
            }
        }
        return 0;
    }
};
