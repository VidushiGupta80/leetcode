//Two City Scheduling -> 05/01/2020 13:15
class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
      
        int N = costs.size();
        
        vector<pair<int, int> > diff;
        
        int cost = 0;
        
        for(int i = 0; i < N; i++)
        {
            diff.push_back(make_pair(costs[i][1] - costs[i][0], i));
            // diff[i][0] = costs[i][0] - costs[i][1];
            // diff[i][1] = i;
        }
        sort(diff.begin(), diff.end());
        for(int i = 0; i < N; i++)
        {
            if(i < N/2)
                cost += costs[diff[i].second][1];
            else
                cost += costs[diff[i].second][0];
        }
        
        return cost;
    }
};
