//Target Sum -> 07/04/2020 13:20
class Solution {
private:
    int dp(int i, long sum, vector<unordered_map<long,int> >& cache, vector<int>& nums)
    {
        if(i == nums.size() && sum == 0)
            return 1;
        else if(i == nums.size() && sum != 0)
            return 0;
        
        unordered_map<long,int> :: iterator it = cache[i].find(sum);
        if(it != cache[i].end())
            return it->second;
        
        int ans = dp(i + 1, sum - nums[i], cache, nums) + dp(i + 1, sum + nums[i], cache, nums);
        cache[i].insert(make_pair(sum, ans));
        return ans;
    }
    
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        long sum = 0;
        vector<unordered_map<long,int> >cache(nums.size());
        int ans = dp(0, S-sum, cache, nums);
        return ans;
    }
};
