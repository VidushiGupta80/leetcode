//Unique Paths III -> 09/05/2020 14:48
class Solution {
void dp(int x, int y, int p, vector<vector<int> >& grid, vector<vector<int> >& visited, int& ans)
{
    if(grid[x][y] == 2 && p == 1)
    {
        ans++;
        return;
    }
    visited[x][y] = 1;
    if(x - 1 >= 0 && visited[x-1][y] == -1 && grid[x - 1][y] != -1)
        dp(x - 1, y, p - 1, grid, visited, ans);
    if(y - 1 >= 0 && visited[x][y - 1] == -1 && grid[x][y - 1] != -1)
        dp(x, y - 1, p - 1, grid, visited, ans);
    if(x + 1 < grid.size() && visited[x+1][y] == -1 && grid[x + 1][y] != -1)
        dp(x + 1, y, p - 1, grid, visited, ans);
    if(y + 1 < grid[0].size() && visited[x][y + 1] == -1 && grid[x][y + 1] != -1)
        dp(x, y + 1, p - 1, grid, visited, ans);
    visited[x][y] = -1;
    return;
    
}
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        if(m == 0)
            return 0;
        vector<vector<int> > visited(m, vector<int> (n, -1));
        int x, y, p = 0;
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] >= 0)
                    p++;
                if(grid[i][j] == 1)
                {
                    x = i;
                    y = j;
                }
            }
        }
        int ans = 0;
        dp(x, y, p, grid, visited, ans);
        return ans;
    }
};
