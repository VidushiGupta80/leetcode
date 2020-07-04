//House Robber -> 07/04/2020 13:40
class Solution {
private:
    int dp(int i, map<int, int>& cache, vector<int>& nums)
    {
        if(i >= nums.size())
            return 0;
        
        map<int, int> :: iterator it = cache.find(i);
        if(it != cache.end())
            return cache[i];
        
        int ans = max(nums[i] + dp(i + 2, cache, nums), dp(i + 1, cache, nums));
        
        cache.insert(make_pair(i, ans));
        return ans;
        
    }
    
    
public:
    int rob(vector<int>& nums) {
        map<int, int> cache;
        int ans = dp(0, cache, nums);
        return ans;
    }
};
