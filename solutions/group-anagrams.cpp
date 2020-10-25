//Group Anagrams -> 08/13/2020 13:58
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string> > anaFreq;
        // vector<string> sortedstrs(strs.size());
        for(int i = 0; i < strs.size(); i++)
        {
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            anaFreq[temp].push_back(strs[i]);
        }
        vector<vector<string> > ans;
        map<string, vector<string> > :: iterator it = anaFreq.begin();
        for(; it != anaFreq.end(); it++)
        {
            ans.push_back(it->second);
        }
        return ans;
    }
};
