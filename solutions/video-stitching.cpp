//Video Stitching -> 08/12/2020 19:32

class Solution {
int dp(int index, vector<pair<int, int> >& ans, int end, map<pair<int, int>, int>& cache, int T)
{
    
    if(end >= T)
        return cache[make_pair(index,end)]  = 0;
    if(index >= ans.size() && end < T)
        return INT_MAX;
    if(index >= ans.size() && end >= T)
        return 0;
    
    
    if(cache.find(make_pair(index, end)) != cache.end())
        return cache[make_pair(index,end)] ;
    int res = INT_MAX - 10;
    res = min(res, dp(index + 1, ans, end, cache, T));
    if(ans[index].first <= end)
        res = min(res, 1 + dp(index + 1, ans, ans[index].second, cache, T));
    
    return cache[make_pair(index,end)]  = res;
        
        
}
    
public:
    int videoStitching(vector<vector<int>>& clips, int T) {
       
        map<int, int > startEnds;
        for(int i = 0; i < clips.size(); i++)
        {
            if(startEnds.find(clips[i][0]) != startEnds.end())
            {
                startEnds[clips[i][0]] = max(startEnds[clips[i][0]], clips[i][1]);
            }
            else
                startEnds[clips[i][0]] = clips[i][1];
        }
        vector<pair<int, int> > ans;
        if(startEnds.find(0) == startEnds.end())
            return -1;
        map<int, int> :: iterator it = startEnds.begin();
        int start = 0, end = -1;
        for(; it != startEnds.end(); it++)
        {
            if(it->second > end)
            {
                end = it->second;
                ans.push_back(make_pair(it->first, it->second));
            }
        }
        
        
        for(int i = 0; i < ans.size() - 1; i++)
        {
            if(ans[i].second >= T)
                break;
            if(ans[i].second < ans[i + 1].first)
                return -1;
        }
        if(ans[ans.size() - 1].second < T)
            return -1;
        map<pair<int, int>, int> cache;
        int res = dp(0, ans, 0, cache, T);
        
        return res;
        
       
    }
};
