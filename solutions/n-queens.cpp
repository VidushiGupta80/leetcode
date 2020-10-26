class Solution {
void addToRes(int& n, map<pair<string, int>, int>& board, vector<vector<string> >& res)
{
    vector<string> temp(n);
    for(int i = 0; i < n; i++)
    {   
        string str = "";
        int j = board[{"queen", i}];
        for(int k = 0; k < n; k++)
        {
            if(k == j)
                str += "Q";
            else
                str += ".";
        }
        temp[i] = str;
    }
    res.push_back(temp);
    return;
}
bool isFree(int i, int j, map<pair<string, int>, int>& board)
{
    if((board.find({"row", i}) == board.end() || board[{"row",i}] == -1)
       && (board.find({"column", j}) == board.end() || board[{"column", j}] == -1)
       && (board.find({"NEtoSW", i - j}) == board.end() || board[{"NEtoSW", i - j}] == -1)
       && (board.find({"NWtoSE", i + j}) == board.end() || board[{"NWtoSE", i + j}] == -1))
        return true;
    else
        return false;
}
void addToBoard(int i, int j, map<pair<string, int>, int>& board)
{
    board[{"row",i}] = 1;
    board[{"column", j}] = 1;
    board[{"NEtoSW", i - j}] = 1;
    board[{"NWtoSE", i + j}] = 1;
    board[{"queen", i}] = j;
    return;
}
void removeFromBoard(int i, int j, map<pair<string, int>, int>& board)
{
    board[{"row",i}] = -1;
    board[{"column", j}] = -1;
    board[{"NEtoSW", i - j}] = -1;
    board[{"NWtoSE", i + j}] = -1;
    board[{"queen", i}] = -1;
    return;
}
void locateQueens(int i, int& n, map<pair<string, int>, int>& board, 
                  vector<vector<string> >& res)
{
    if(i == n)
    {
        addToRes(n, board, res);
        return;
    }
    for(int j = 0; j < n; j++)
    {
        if(isFree(i, j, board))
        {
            addToBoard(i, j, board);
            locateQueens(i + 1, n, board, res);
            removeFromBoard(i, j, board);
        }
    }
    return;
}
public:
    vector<vector<string>> solveNQueens(int n) {        
        map<pair<string, int>, int> board;
        vector<vector<string> > res;
        if(n == 1)
        {
            string str = "Q";
            vector<string> vec;
            vec.push_back(str);
            res.push_back(vec);
            return res;
        }
        if(n == 2 || n == 3)
            return res;
        locateQueens(0, n, board, res);
        return res;
    }
};