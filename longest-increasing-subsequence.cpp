//Longest Increasing Subsequence -> 08/14/2020 15:47
class Solution {
// int dp(int i, bool isPart, map<pair<int, bool>, int>& cache, vector<int>& nums)
// {
//     if(i >= nums.size())
//         return 0;
//     if(cache.find(make_pair(i, isPart)) != cache.end())
//         return cache[make_pair(i, isPart)];
    
//     int ans = 0;
//     if(isPart)
//     {
//         for(int j = i+1; j < nums.size(); j++)
//         {
//             if(nums[j] > nums[i])
//                 ans = max(ans, 1 + dp(j, true, cache, nums));
//         }
        
//     }
//     else
//     {
//         ans = max(ans, dp(i + 1, false, cache, nums));
//         for(int j = i+1; j < nums.size(); j++)
//         {
//             if(nums[j] > nums[i])
//                 ans = max(ans, 1 + dp(j, true, cache, nums));
//         }
//     }
//     return cache[make_pair(i, isPart)] = ans;
// }
    
// public:
//     int lengthOfLIS(vector<int>& nums) {
//         if(nums.size() == 0)
//             return 0;
//         map<pair<int, bool>, int> cache;
//         int ans = dp(0,false, cache, nums);
//         return ans +m 1;
//     }
    
    
    public:
        int lengthOfLIS(vector<int>& nums) {
            if(nums.size() == 0)
                return 0;
            vector<int> dp(nums.size(), 1);
            for(int i = 1; i < nums.size(); i++)
            {
                for(int j = 0; j < i; j++)
                {
                    if(nums[j] < nums[i] && dp[i] <= dp[j])
                        dp[i] = 1 + dp[j];
                }
            }
            return *max_element(dp.begin(), dp.end());
        }
};
