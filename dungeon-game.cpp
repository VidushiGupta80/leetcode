//Dungeon Game -> 09/02/2020 20:03
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();
        vector<vector<int> >cache(m, vector<int> (n, INT_MAX));
        for(int i = m - 1; i >= 0; i--)
        {
            for(int j = n - 1; j >= 0; j--)
            {
                if(i == m - 1 && j == n - 1)
                {
                    if(dungeon[i][j] < 0)
                        cache[i][j] = 1 + (-dungeon[i][j]);
                    else
                        cache[i][j] = 1;
                    // cout << cache[i][j] << endl;
                    continue;
                }
                int right = INT_MAX, down = INT_MAX;
                if(j + 1 < n)
                    right = cache[i][j + 1];
                if(i + 1 < m)
                    down = cache[i + 1][j];
                cache[i][j] = min(right, down);
                if(dungeon[i][j] < 0)
                    cache[i][j] += (-dungeon[i][j]);
                else
                    cache[i][j] = max(1, cache[i][j] - dungeon[i][j]);
                
            }
        }
        return cache[0][0];
    }
};
