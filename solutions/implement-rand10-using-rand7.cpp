//Implement Rand10() Using Rand7() -> 08/28/2020 16:17

// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        int res = 0;
        for (int i=0; i<7; i++)
            res += rand7();
        return res%10 + 1;
    }
};