class Solution {
const int mod = 1e9 + 7 ;
int recc(int num, int n, vector<vector<int> >&cache, vector<vector<int> >& pattern)
{
    if(n == 0)
        return 1;
    if(cache[num][n] != -1)
        return cache[num][n];
    int ans = 0;
    for(int i = 0; i < pattern[num].size(); i++)
    {
        ans = (ans + recc(pattern[num][i], n - 1, cache, pattern)) % mod;
    }
    return cache[num][n] = ans;
}
public:
    int knightDialer(int n) {
        if(n == 0)
            return 0;
        if(n == 1)
            return 10;
        vector<vector<int> > pattern(10);
        pattern[0].push_back(4);
        pattern[0].push_back(6);
        pattern[1].push_back(6);
        pattern[1].push_back(8);
        pattern[2].push_back(7);
        pattern[2].push_back(9);
        pattern[3].push_back(4);
        pattern[3].push_back(8);
        pattern[4].push_back(0);
        pattern[4].push_back(3);
        pattern[4].push_back(9);
        pattern[6].push_back(0);
        pattern[6].push_back(1);
        pattern[6].push_back(7);
        pattern[7].push_back(2);
        pattern[7].push_back(6);
        pattern[8].push_back(3);
        pattern[8].push_back(1);
        pattern[9].push_back(2);
        pattern[9].push_back(4);
        vector<vector<int> > cache(10, vector<int>(n, -1));
        int ans = 0;
        for(int i = 0; i < 10; i++)
            ans = (ans + recc(i, n - 1, cache, pattern)) % mod;
        return ans;
        
    }
};