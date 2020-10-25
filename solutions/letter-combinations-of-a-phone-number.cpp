//Letter Combinations of a Phone Number -> 08/08/2020 20:51
class Solution {
void dp(int i, string temp, string& digits, vector<string>& ans, map<int, string>& match)
{
    if(i < 0)
    {
        ans.push_back(temp);
        return;
    }
    map<int, string> :: iterator it;
    it = match.find((int)digits[i] - 48);
    for(int j = 0; j < it->second.size(); j++)
    {
        dp(i - 1, it->second[j] + temp, digits, ans, match);
    }
    return;
}
    
public:
    vector<string> letterCombinations(string digits) {
        int n = digits.size();
        map<int, string> match;
        match[2] = "abc";
        match[3] = "def";
        match[4] = "ghi";
        match[5] = "jkl";
        match[6] = "mno";
        match[7] = "pqrs";
        match[8] = "tuv";
        match[9] = "wxyz";
        vector<string> ans;
        if(n == 0)
            return ans;
        dp(n - 1, "", digits, ans, match);
        return ans;
        
    }
};
