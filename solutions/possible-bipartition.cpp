//Possible Bipartition -> 09/10/2020 17:10

class Solution {
bool bfs(int curr, vector<vector<int> >& adj, vector<int>& colour)
{
    colour[curr] = 1;
    queue<int> q;
    q.push(curr);
    while(!q.empty())
    {
        int temp = q.front();
        int currColour = colour[temp];
        for(int i = 0; i < adj[temp].size(); i++)
        {
            if(colour[adj[temp][i]] == 0)
            {
                colour[adj[temp][i]] = -currColour;
                q.push(adj[temp][i]);
            }
            else if(colour[adj[temp][i]] == currColour)
                return false;
            
        }
        q.pop();
    }
    return true;
   
}
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        vector<int> colour(N + 1, 0);
        int n = dislikes.size();
        vector<vector<int> > adj(N + 1);
        for(int i = 0; i < n; i++)
        {
            adj[dislikes[i][0]].push_back(dislikes[i][1]);
            adj[dislikes[i][1]].push_back(dislikes[i][0]);
        }
        for(int i = 1; i <= N; i++)
        {
            if(colour[i] == 0)
            {
                if(!bfs(i, adj, colour))
                    return false;
            }
        }
        return true;
    }
};