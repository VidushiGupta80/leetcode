//Find Right Interval -> 08/27/2020 16:35
class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        vector<int> ans(intervals.size(), INT_MIN);
        map<int, vector<pair<int, int> > > startEnds;
        for(int i = 0; i < intervals.size(); i++)
        {
            startEnds[intervals[i][0]].push_back(make_pair(i, intervals[i][1]));
        }
         map<int, vector<pair<int, int> > > :: iterator it;
        for(int i = 0; i < intervals.size(); i++)
        {
            it = startEnds.find(intervals[i][0]);
            int temp = intervals[i][1];
            while(it != startEnds.end())
            {
                if(it->first >= temp)
                {
                    sort(it->second.begin(), it->second.end());
                    ans[i] = it->second[0].first;
                    break;
                }
                else
                    it++;
            }
            if(ans[i] == INT_MIN)
                ans[i] = -1;
        }
        return ans;
    }
};
