//Minimum Falling Path Sum -> 07/04/2020 15:12
class Solution {
private:
    long dp(int i, int j, map<pair<int, int>, long>& cache, vector<vector<int>>& A)
    {
        // if(i < 0)
        //     return INT_MAX;
        if(i >= A.size())
            return 0;
        if(j < 0)
            return INT_MAX;
        if(j >= A.size())
            return INT_MAX;
        
        map<pair<int, int>, long> :: iterator it = cache.find(make_pair(i, j));
        if(it != cache.end())
            return cache[make_pair(i, j)];
        
        long ans = A[i][j] + min(dp(i + 1, j - 1, cache, A),
                                min(dp(i + 1, j, cache, A), dp(i+1, j + 1, cache, A)));
        cache.insert(make_pair(make_pair(i, j), ans));
        
        return ans;
    }
    
    
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        map<pair<int, int>, long> cache;
        long ans = INT_MAX;
        // cout<<A.size() << endl;
        for(int i = 0; i < A.size(); i++)
        {
            ans = min(ans, dp(0, i, cache, A));
        }
        return ans;
    }
};