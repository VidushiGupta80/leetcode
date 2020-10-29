class Solution {
int dp(int index, vector<int>& cache, vector<vector<int> >& joined)
{
    if(index >= joined.size())
        return 0;
    if(cache[index] != -1)
        return cache[index];
    int ans = INT_MIN;
    ans = max(ans, dp(index + 1, cache, joined));
    int i = index;
    for(; i < joined.size(); i++)
    {
        if(joined[i][0] >= joined[index][1])
            break;
    }
    ans = max(ans, joined[index][2] + dp(i, cache, joined));
    return cache[index] = ans;
}
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<int> cache (profit.size(), -1);
        vector<vector<int> > joined(profit.size(), vector<int> (3));
        for(int i = 0; i < profit.size(); i++)
        {
            joined[i][0] = startTime[i];
            joined[i][1] = endTime[i];
            joined[i][2] = profit[i];
        }
        sort(joined.begin(), joined.end());
        return dp(0, cache, joined);
    }
};
