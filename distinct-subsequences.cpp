//Distinct Subsequences -> 09/02/2020 17:59
class Solution {
public:
int numDistinct(string s, string t) {
        int ss = s.size();
        int ts = t.size();
        if(ss == 0)
            return 0;
        if(ts == 0)
            return 1;
        vector<vector<long long> > cache(ss, vector<long long> (ts, 0));
        for(int i = 0; i < ss; i++)
        {
            for(int j = 0; j < ts; j++)
            {
                 if(i == 0 && j == 0)
                 {
                     if(s[i] == t[j])
                         cache[i][j] = 1;
                 }
                else if(i == 0)
                    continue;
                else
                {
                    cache[i][j] = cache[i - 1][j];
                    if(s[i] == t[j])
                    {
                        if(j - 1 >= 0)
                            cache[i][j] += cache[i - 1][j - 1];
                        else 
                            cache[i][j] += 1;
                    }
                }
            }
        }
        return cache[ss - 1][ts - 1];
    }
};
