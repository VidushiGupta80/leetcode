//Unique Paths -> 08/26/2020 18:29
class Solution {
public:
    int uniquePaths(int n, int m) {
        vector<vector<int> > cache(n, vector<int> (m, 0));
        cache[0][0] = 1;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
               if(i == 0 && j == 0)
                   continue;
                int ansTop = 0, ansLeft = 0;
                if(i - 1 >= 0 )
                    ansTop = cache[i-1][j];
                if(j - 1 >= 0)
                    ansLeft = cache[i][j - 1];
                cache[i][j] = ansTop + ansLeft;
                    
            }
        }
        return cache[n - 1][m - 1];
    }
};
