//Valid Sudoku -> 09/04/2020 12:12
class Solution {
int get(int i, int j)
{
    int ans = 0;
    if(i >=0 && i <= 2)
    {
        if(j >= 0 && j <= 2)
            ans = 1;
        else if(j >=3 && j <= 5)
            ans = 2;
        else
            ans = 3;
    }
    else if(i >= 3 && i <= 5)
    {
        if(j >= 0 && j <= 2)
            ans = 4;
        else if(j >=3 && j <= 5)
            ans = 5;
        else
            ans = 6;
    }
    else if(i >= 6 && i <= 8)
    {
        if(j >= 0 && j <= 2)
            ans = 7;
        else if(j >=3 && j <= 5)
            ans = 8;
        else
            ans = 9;
    }
    return ans;
}
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        map<int, set<char> > rows;
        map<int, set<char> > columns;
        map<int, set<char> > box;
        for(int i = 0; i < 9; i++)
        {
            for(int j = 0; j < 9; j++)
            {
                if(board[i][j] == '.')
                    continue;
                if(rows[i].count(board[i][j]) > 0)
                    return false;
                else
                    rows[i].insert(board[i][j]);
                if(columns[j].count(board[i][j]) > 0)
                    return false;
                else
                    columns[j].insert(board[i][j]);
                int temp = get(i, j);
                if(box[temp].count(board[i][j]) > 0)
                    return false;
                else
                    box[temp].insert(board[i][j]);
            }
        }
        return true;
    }
};
