//Partition Equal Subset Sum -> 08/30/2020 17:04
class Solution {
bool dp(int index, int diff, vector<int>& nums, unordered_map<int, bool>& cache)
{
    if(diff == 0)
        return true;
    // if(diff < 0)
    //     return false;
    if(index >= nums.size())
        return false;
    if(cache.find(diff) != cache.end())
        return cache[diff];
    
    bool ans = dp(index + 1, diff - nums[index] , nums, cache) || dp(index + 1, diff, nums, cache);
    return cache[diff] = ans;
}
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int num: nums){
            sum += num;
        }
        if(sum % 2 != 0)
            return false;
        // sum /= 2;
        unordered_map<int, bool> cache;
        return dp(0, sum / 2, nums, cache);
    }
};
