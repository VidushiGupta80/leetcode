//Move Zeroes -> 09/26/2020 13:52
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        fill(remove(nums.begin(), nums.end(),0), nums.end(), 0);
    }
};
