//Maximal Square -> 09/02/2020 20:45
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int ans = 0;
        int m = matrix.size();
        if(m == 0)
            return 0;
        int n = matrix[0].size();
        vector<vector<int> >cache(m, vector<int> (n, 0));
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(i == 0 || j == 0)
                    cache[i][j] = matrix[i][j] - '0';
                else if(matrix[i][j] == '1')
                {
                    cache[i][j] = min(cache[i - 1][j - 1], min(cache[i - 1][j], cache[i][j - 1])) + 1;
                }
                ans = max(ans, cache[i][j]);
            }
        }
        return ans * ans;
    }
};
