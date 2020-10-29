class Solution {
int dp(int index, int d, vector<int>& jobDifficulty, map<pair<int, int>, int>& cache)
{
    
    if(d == 0 &&  index >= jobDifficulty.size())
        return 0;
    if(d == 0 && index < jobDifficulty.size())
        return 1000;    
	if (index == jobDifficulty.size()) 
        return INT_MAX;    
    if(cache.find({index, d}) != cache.end())
        return cache[{index, d}];
    long res = INT_MAX;
    long temp = jobDifficulty[index];
    for(int i = index; i <= jobDifficulty.size() - d, i < jobDifficulty.size(); i++)
    {
        temp = max(temp, (long)jobDifficulty[i]);
        int ans = dp(i + 1, d - 1, jobDifficulty, cache);
        res = min(res, temp + ans);
    }
    return cache[{index, d}] = res;
}
    
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        if(jobDifficulty.size() < d)
            return -1;
        if(jobDifficulty.size() == d)
            return accumulate(jobDifficulty.begin(), jobDifficulty.end(), 0);
        map<pair<int, int>, int> cache;
        return dp(0, d, jobDifficulty, cache);
    }
};
