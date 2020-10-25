//Palindromic Substrings -> 08/14/2020 16:00
class Solution {
public:
    int countSubstrings(string s) {
        vector<vector<bool> > cache(s.size(), vector<bool> (s.size(), false));
        for(int i = s.size() - 1; i >= 0; i--)
        {
            for(int j = i; j < s.size(); j++)
            {
                if(i == j)
                    cache[i][j] = true;
                else if(abs(i - j) == 1 && s[i] == s[j])
                    cache[i][j] = true;
                else 
                {
                    if(s[i] == s[j])
                        cache[i][j] = cache[i + 1][j - 1];
                }
                    
            }
        }
        // for(int i = 0; i < s.size(); i++)
        // {
        //     for(int j = 0; j < s.size(); j++)
        //         cout << cache[i][j] << " ";
        //     cout << endl;
        // }
        int ans = 0;
        for(int i = 0; i < s.size(); i++)
        {
            for(int j = 0; j < s.size(); j++)
            {
                if(cache[i][j])
                    ans++;
            }
        }
        return ans;
    }
};
