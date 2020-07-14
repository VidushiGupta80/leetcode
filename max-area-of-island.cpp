//Max Area of Island -> 07/14/2020 14:20
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int answer = 0;
        vector<vector<bool> > visited(grid.size(), vector<bool> (grid[0].size(), false));
        queue<pair<int, int> > bfs;
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[0].size(); j++)
            {
                int ans = 0;
                if(!visited[i][j] && grid[i][j] == 1)
                {
                    
                    bfs.push(make_pair(i, j));
                    
                    while(!bfs.empty())
                    {
                        int i = bfs.front().first, j = bfs.front().second; 
                        
                        if(i >= grid.size() || i < 0) 
                        {
                            bfs.pop();  
                            continue;
                        }
                        if(j >= grid[0].size() || j < 0)
                        {
                             bfs.pop();  
                            continue;
                        }
                        if(grid[i][j] == 0)
                        {
                            bfs.pop();
                            continue;
                        }
                        if(visited[i][j])
                        {
                             bfs.pop();  
                            continue;
                        }
                        
                        else if(!visited[i][j])
                        {
                            ans++;
                            visited[i][j] = true;
                            bfs.push(make_pair(i + 1, j));
                            bfs.push(make_pair(i - 1, j));
                            bfs.push(make_pair(i, j + 1));
                            bfs.push(make_pair(i, j - 1));
                            bfs.pop();
                        }
                    }
                    answer = max(ans, answer);
                }
            }
        }
        return answer;
    }
};
