//K Closest Points to Origin -> 08/19/2020 13:42

typedef pair<int, int> pi;
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        priority_queue<pi, vector<pi>, greater<pi> > pq;
        for(int i = 0; i < points.size(); i++)
        {
            int dist = points[i][0] * points[i][0] + points[i][1] * points[i][1];
            pq.push(make_pair(dist, i));
        }
        vector<vector<int> > ans;
        
        while(K > 0)
        {
            int i = pq.top().second;
            ans.push_back(points[i]);
            K--;
            pq.pop();
        }
        return ans;
    }
};