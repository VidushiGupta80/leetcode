//First Bad Version -> 05/16/2020 17:14
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1, right = n, mid;
        if(n == 1)
            return 1;
        while(left <= right)
        {
            mid = left + (right - left) / 2;
            bool check = isBadVersion(mid);
            if( check == true && isBadVersion(mid - 1) == false)
            {
                return mid;
            }
            else if(check)
            {
                right = mid;
            }
            else if(!check)
                left = mid + 1;
           
        }
        return -1;
    }
};
