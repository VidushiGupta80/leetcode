//Non-overlapping Intervals -> 08/15/2020 17:38
// int ending;
 bool sortCol(vector<int> arr1, vector<int> arr2)
    {
        if(arr1[1] != arr2[1])
            return arr1[1] < arr2[1];
        return true;
    }
class Solution {
// int dp(int start, map<int, vector<int> >& startEnds, map<int, int>& cache)
// {
//     map<int, vector<int> > :: iterator it = startEnds.find(start);
//     if(it == startEnds.end())
//         return 0;
//     if(cache.find(start) != cache.end())
//         return cache[start];
    
//     int ans = 0;
//     for(int i = 0; i < it->second.size(); i++)
//     {
//         int temp = 1 + dp(it->second[i], startEnds, cache);
//         if(temp > ans)
//         {
//             ending = max(ending, it->second[i]);
//             // cout << ending << endl;
//             ans = temp;
//         }
//     }
//     return cache[start] = ans;
// }
    
public:
   
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int ending = INT_MIN;
//         map<int, vector<int> > startEnds;
//         map<int, int> cache;
//         for(int i = 0; i < intervals.size(); i++)
//         {
//             startEnds[intervals[i][0]].push_back(intervals[i][1]);
//         }
//         map<int, vector<int> > :: iterator it = startEnds.begin();
        
//         int ans = 0;
//         for(; it != startEnds.end(); it++)
//         {
//             if(cache.find(it->first) == cache.end())
//             {
//                 sort(it->second.begin(), it->second.end());
//                 if(it->second[it->second.size() - 1] > ending)
//                     ans += dp(it->first, startEnds, cache);
                
//             }
//         }
//         return intervals.size() - ans;
        sort(intervals.begin(), intervals.end(), sortCol);
        // for(int i = 0; i < intervals.size(); i++)
        //     cout << intervals[i][0] << " " << intervals[i][1] << endl;
        int count = 0;
        for(int i = 0; i < intervals.size(); i++)
        {
            if(intervals[i][0] >= ending)
            {
                ending = intervals[i][1];
            }
            else 
                count++;
            // cout << ending << " " << count << endl;
        }
        return count;
        
    }
};
