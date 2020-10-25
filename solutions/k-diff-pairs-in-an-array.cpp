//K-diff Pairs in an Array -> 10/07/2020 19:01
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int ans = 0;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); )
        {
            int j = i + 1;
            while(j < nums.size() - 1 && nums[j] - nums[i] < k)
                j++;
            if(j < nums.size() && nums[j] - nums[i] == k)
                ans++;
            else if(j >= nums.size())
                break;
            while(i < nums.size() - 1 && nums[i] == nums[i + 1])
                i++;
            if(i < nums.size() - 1)
                i++;                        
        }
        return ans;
    }
};
