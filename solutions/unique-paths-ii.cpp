//Unique Paths II -> 09/02/2020 13:57
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        vector<vector<int> > cache(n, vector<int> (m, 0));
        if(obstacleGrid[0][0] == 1)
            return 0;
        cache[0][0] = 1;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(i == 0 && j == 0)
                    continue;
                else if(obstacleGrid[i][j] == 0)
                {
                    int top = 0;
                    int left = 0;
                    if(i - 1 >= 0)
                    {
                        top = cache[i - 1][j];
                    }
                    if(j - 1 >= 0)
                        left = cache[i][j - 1];
                    cache[i][j] = top + left;
                }
            }
        }
        return cache[n - 1][m - 1];
    }
};
