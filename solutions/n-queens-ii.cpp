class Solution {
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
                  int& res)
{
    if(i == n)
    {
        res++;
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
    int totalNQueens (int n) {        
        map<pair<string, int>, int> board;
        int res = 0;
        if(n == 1)
        {
            return 1;
        }
        if(n == 2 || n == 3)
            return res;
        locateQueens(0, n, board, res);
        return res;
    }
};