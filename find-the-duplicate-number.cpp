//Find the Duplicate Number -> 08/25/2020 10:41
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        map<int, int> freq;
        for(int i = 0; i < nums.size(); i++)
        {
            if(freq.find(nums[i]) != freq.end())
                return nums[i];
            else
                freq[nums[i]] = 1;
        }
        return -1;
    }
};
