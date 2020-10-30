class Solution {
int mod = 1e9 + 7;
int calc(char c, int n, vector<char>& vowels, map<char, vector<char> >& pre, unordered_map<string, int>& dp)
{
    if(n == 0)
        return 1;
    string key = "";
    key += c;
    key += '-';
    key += to_string(n);
    if(dp.find(key) != dp.end())
        return dp[key];
    int ans = 0;
    for(int i = 0; i < pre[c].size(); i++)
        ans = (ans% mod + calc(pre[c][i], n - 1, vowels, pre, dp) % mod) % mod;
    return dp[key] =  ans;
}
public:
    int countVowelPermutation(int n) {
        map<char, vector<char> > pre;
        vector<char> vowels {'a', 'e', 'i', 'o', 'u'};
        pre['a'].push_back('u');
        pre['a'].push_back('i');
        pre['a'].push_back('e');
        pre['e'].push_back('a');
        pre['e'].push_back('i');
        pre['i'].push_back('e');
        pre['i'].push_back('o');
        pre['o'].push_back('i');
        pre['u'].push_back('i');
        pre['u'].push_back('o');
        unordered_map<string, int> dp;
        int ans = 0;
        for(int i = 0; i < 5; i++)
        {
            ans = (ans % mod + calc(vowels[i], n - 1, vowels, pre, dp) % mod) % mod;
        }
        return ans;
    }
};
