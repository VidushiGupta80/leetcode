//Unique Binary Search Trees -> 08/23/2020 14:16
class Solution {
int dp(int n, map<int, int>& cache)
    {
        if(cache.find(n) != cache.end())
            return cache[n];
        int res = 0;
        for(int i = 0; i < n; i++)
        {
            int j = n - i - 1;
            int l = dp(i, cache);
            int r = dp(j, cache);
            int ans = l * r;
            res += ans;
        }
        return cache[n] = res;
    }
    
public:
    int numTrees(int n) {
        map<int, int> cache;
        cache[0] = 1;
        cache[1] = 1;
        cache[2] = 2;
        return dp(n, cache);
    }
};
