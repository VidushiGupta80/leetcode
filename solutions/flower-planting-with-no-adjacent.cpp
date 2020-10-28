//Flower Planting With No Adjacent -> 08/12/2020 15:37

class Solution {
void dfs(int i, map<int, vector<int> >& adj, vector<bool>& visited, vector<int>& colour)
{
    visited[i] = true;
    vector<bool> chosen(4, false);
    map<int, vector<int> > :: iterator it = adj.find(i);
    if(it != adj.end())
    {
        for(int j = 0; j < it->second.size(); j++)
        {
            if(visited[adj[i][j]])
            {
                int flower = colour[adj[i][j] - 1];
                chosen[flower - 1] = true;
            }
        }
    }    
    for(int j = 0; j < 4; j++)
    {
        if(!chosen[j])
        {
            colour[i - 1] = j + 1;
            break;
        }
    }
    return;
}
    
public:
    vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
        vector<bool> visited(N + 1, false);
        map<int, vector<int> > adj;
        for(int i = 0; i < paths.size(); i++)
        {
            adj[paths[i][0]].push_back(paths[i][1]);
            adj[paths[i][1]].push_back(paths[i][0]);
        }
        vector<int> colour(N);
        // vector<int> type = [1, 2, 3, 4];
        // vector<bool> chosen(4, false);
        for(int i = 1; i <= N; i++)
        {
          if(!visited[i])
              dfs(i, adj, visited, colour);
        }
        return colour;
    }
};