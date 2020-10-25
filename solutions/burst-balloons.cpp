//Burst Balloons -> 09/03/2020 11:19
class Solution {
int dp(int i, int j, vector<int>& nums, vector<vector<int> >&cache)
{
    if(i > j)
        return 0;
    if(cache[i][j] != -1)
        return cache[i][j];
    int ans = 0;
    for(int k = i+1; k < j; k++)
        ans = max(ans, dp(i, k, nums, cache) + dp(k, j, nums, cache) + nums[i] * nums[k] * nums[j]);
    return cache[i][j] = ans;
}
public:
    int maxCoins(vector<int>& nums) {
        vector<vector<int> >cache(501, vector<int> (501, -1));
        nums.insert(nums.end(),1);
        nums.push_back(1);
        return dp(0, nums.size() - 1, nums, cache);
    }
};
