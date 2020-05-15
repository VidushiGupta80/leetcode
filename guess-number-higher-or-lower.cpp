//Guess Number Higher or Lower -> 05/15/2020 20:28
/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return       -1 if num is lower than the guess number
 *                1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int left = 0, right = n, mid;
        while(left <= right)
        {
            mid = left + (right - left)/2;
            int result = guess(mid);
            if(result == 0)
            {
                return mid;
            }
            else if(result == -1)
            {
                right = mid - 1;
            }
            else if(result == 1)
            {
                left = mid + 1;
            }
        }
        return 0;
    }
};
