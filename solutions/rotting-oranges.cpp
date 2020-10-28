//Rotting Oranges -> 08/10/2020 12:53
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int time = 0;
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<pair<int, int>, int> > bfs;
        vector<vector<bool> > visited(n, vector<bool> (m, false));
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == 2)
                {
                    visited[i][j] = true;
                    bfs.push(make_pair(make_pair(i, j), time));
                }
            }
        }
        while(!bfs.empty())
        {
            int i = bfs.front().first.first;
            int j = bfs.front().first.second;
            time = bfs.front().second;
            
            if(i - 1 >= 0)
            {
                if(!visited[i - 1][j] && grid[i - 1][j] == 1)
                {
                    bfs.push(make_pair(make_pair(i - 1, j), time + 1));
                    visited[i - 1][j] = true;
                }
            }
            if(i + 1 < n)
            {
                if(!visited[i + 1][j] && grid[i + 1][j] == 1)
                {
                    bfs.push(make_pair(make_pair(i + 1, j), time + 1));
                    visited[i + 1][j] = true;
                }
            }
            if(j - 1 >= 0)
            {
                if(!visited[i][j - 1] && grid[i][j - 1] == 1)
                {
                    bfs.push(make_pair(make_pair(i, j - 1), time + 1));
                    visited[i][j - 1] = true;
                }
            }
            if(j + 1 < m)
            {
                if(!visited[i][j + 1] && grid[i][j + 1] == 1)
                {
                    bfs.push(make_pair(make_pair(i, j + 1), time + 1));
                    visited[i][j + 1] = true;
                }
            }
            bfs.pop();
        }
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(!visited[i][j] && grid[i][j] == 1)
                {
                   return -1;
                }
            }
        }
        return time;
    }
};
