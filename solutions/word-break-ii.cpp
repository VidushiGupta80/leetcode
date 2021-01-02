class Solution {
pair<vector<string>, bool> dp(int index, unordered_map<int, pair<vector<string>, bool> >& cache, string& s, vector<string>& wordDict)
{
    vector<string> partAns(1, "");
    
    if(index >= s.size())
        return {partAns, true};
    if(cache.find(index) != cache.end())
        return cache[index];
    
    pair<vector<string>, bool> ans;
    for(int i = 0; i < wordDict.size(); i++)
    {
        if(wordDict[i][0] == s[index])
        {
            if(wordDict[i] == s.substr(index, wordDict[i].size())){
                pair<vector<string>, bool> temp;
                temp = dp(index + wordDict[i].size(), cache, s, wordDict);
                if(temp.second){
                    ans.second |= temp.second;
                    for(int j = 0; j < temp.first.size(); j++)
                    {
                        if(temp.first[j] != "")
                            ans.first.push_back(wordDict[i] + " " + temp.first[j]);
                        else
                            ans.first.push_back(wordDict[i]);
                    }
                }
            }                
        }
    }
    return cache[index] = ans;
}
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        sort(wordDict.begin(), wordDict.end());
        unordered_map<int, pair<vector<string>, bool> > cache;
        // vector<int> gaps;
        return dp(0, cache, s, wordDict).first;
    }
};