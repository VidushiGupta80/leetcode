//Shortest Unsorted Continuous Subarray -> 08/29/2020 20:57
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> sorted(nums);
        sort(sorted.begin(), sorted.end());
        int i, j;
        for(i = 0; i < nums.size(); i++)
        {
            if(nums[i] != sorted[i])
                break;
        }
        for(j = nums.size() - 1; j >= 0; j--)
        {
            if(nums[j] != sorted[j])
                break;
        }
        if(j > i)
            return j - i + 1;
        else return 0;
    }
};
