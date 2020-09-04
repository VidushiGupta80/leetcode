//Set Matrix Zeroes -> 09/04/2020 11:51
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        set<int> rows;
        set<int> columns;
        int m = matrix.size();
        int n = matrix[0].size();
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(matrix[i][j] == 0)
                {
                    rows.insert(i);
                    columns.insert(j);
                }
            }
        }
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(rows.count(i) > 0)
                {
                    vector<int> temp(n, 0);
                    matrix[i] = temp;
                    break;
                }
                else if(columns.count(j) > 0)
                    matrix[i][j] = 0;
            }
        }
        return;
    }
};
