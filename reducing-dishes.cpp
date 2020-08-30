//Reducing Dishes -> 08/30/2020 20:18
class Solution {
int dp(int index, int count, vector<int>& s, vector<vector<int> >& cache)
{
    if(index >= s.size())
        return 0;
    if(cache[index][count] != -1)
        return cache[index][count];
    int res = 0;
    res = max(s[index] * count + dp(index + 1, count + 1, s, cache), dp(index + 1, 1, s, cache));
       
    return cache[index][count] = res;
}
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        // int ans = 0;
        sort(satisfaction.begin(), satisfaction.end());
        vector<vector<int> >cache(satisfaction.size() + 1, vector<int> (satisfaction.size() + 1, -1));
        return dp(0, 1, satisfaction, cache);
    }
};
