//Minimum Cost Tree From Leaf Values -> 08/22/2020 21:40
class Solution {
int dp(int s, int e, int n, vector<int>& arr, map<pair<int, int>, int>& cache) 
{
    if(n == 1)
    {
        return cache[make_pair(s, e)] = arr[s];
    }
    if(n == 2)
    {
        return cache[make_pair(s, e)] = arr[s] * arr[e];
    }
    if(cache.find(make_pair(s, e)) != cache.end())
        return cache[make_pair(s, e)];
    
    int res = INT_MAX;
    for(int i = 1; i < n; i++)
    {
        int j = n - i;
        int sum1 = 0, sum2 = 0;
        if(i > 1)
            sum1 = dp(s, s + i - 1, i, arr, cache);
        if(j > 1)
            sum2 = dp(e - j + 1, e, j, arr, cache);
        int sum = sum1 + sum2;
        int maxL = *max_element(arr.begin() + s, arr.begin() + s + i);
        int maxR = *max_element(arr.begin() + e - j + 1, arr.begin() + e + 1);
        sum += (maxL * maxR);
        res = min(res, sum);
    }
    return cache[make_pair(s, e)] = res;
}
public:
    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();
        map<pair<int, int>, int> cache;
        int ans = dp(0, n - 1, n, arr, cache);
        return ans;
    }
};
