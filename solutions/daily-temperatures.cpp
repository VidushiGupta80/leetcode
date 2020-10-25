//Daily Temperatures -> 08/12/2020 22:05
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> ans(T.size(), 0);
        stack<pair<int, int> > stk;
        for(int i = 0; i < T.size(); i++)
        {
            if(stk.empty())
                stk.push({T[i], i});
            else
            {
                while(!stk.empty() && T[i] > stk.top().first)
                {
                                        
                    ans[stk.top().second] = i - stk.top().second;
                    stk.pop();
                }
                stk.push({T[i], i});
            }
        }
        return ans;
    }
};
