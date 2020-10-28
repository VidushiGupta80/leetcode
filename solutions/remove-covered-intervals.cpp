//Remove Covered Intervals -> 10/07/2020 20:15

bool sortcol( const vector<int>& v1, const vector<int>& v2 ) { 
    
    return v1[0] == v2[0]? v1[1] < v2[1] : v1[0] < v2[0]; 
} 
class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), sortcol);
        int maxEnd = intervals[0][1];
        int minStart = intervals[0][0];
        int ans = 1;
        // for(int i = 0; i < intervals.size(); i++)
        //     cout << intervals[i][0] << " " << intervals[i][1] << endl;
        for(int i = 1; i < intervals.size(); i++)
        {
            if(intervals[i][1] > maxEnd && intervals[i][0] > minStart)
            {
                ans++;               
            }
            maxEnd = max(maxEnd, intervals[i][1]);
            minStart = min(minStart,intervals[i][0]);
        }
        return ans;
    }
};