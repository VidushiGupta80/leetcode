//Valid Perfect Square -> 05/21/2020 17:15
class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num == 1)
            return true;
        else if(num == 2 || num == 3)
            return false;
        long left = 1, right = num / 2, mid;
        while(left <= right)
        {
            mid = left + (right - left) / 2;
            if(mid * mid == num)
                return true;
            else if(mid * mid < num && (mid + 1) * (mid + 1) <= num)
                left = mid + 1;
            else if(mid * mid > num && (mid - 1) * (mid - 1) >= num)
                right = mid - 1;
            else if(mid * mid < num && (mid + 1) * (mid + 1) > num)
                return false;
            else if(mid * mid > num && (mid - 1) * (mid - 1) < num)
                return false;
        }
        return false;
    }
};
