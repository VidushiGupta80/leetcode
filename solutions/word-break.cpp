class Solution {
bool dp(int index, map<int, bool>& cache, string& s, vector<string>& wordDict)
{
    if(index >= s.size())
        return true;
    if(cache.find(index) != cache.end())
        return cache[index];
    
    bool ans = false;
    for(int i = 0; i < wordDict.size(); i++)
    {
        if(wordDict[i][0] == s[index])
        {
            if(wordDict[i] == s.substr(index, wordDict[i].size())){
                ans = ans || dp(index + wordDict[i].size(), cache, s, wordDict);
            }                
        }
    }
    return cache[index] = ans;
}
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        sort(wordDict.begin(), wordDict.end());
        map<int, bool> cache;
        return dp(0, cache, s, wordDict);
    }
};