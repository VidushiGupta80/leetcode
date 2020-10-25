//Word Search -> 08/14/2020 18:05
class Solution {
bool dfs(int i, int j, int index, vector<vector<char>>& board, string& word,
         vector<vector<bool> >& visited)
{
    visited[i][j] = true;
    
    if(index == word.size() - 1)
        return true;
   
    bool ans = false;
    if(i + 1 < board.size())
    {
        if(!visited[i + 1][j] && board[i + 1][j] == (char)word[index + 1])
            ans = ans || dfs(i + 1, j, index + 1, board, word, visited); 
    }
    if(i - 1 >= 0)
    {
        if(!visited[i - 1][j] && board[i - 1][j] == (char)word[index + 1])
            ans = ans || dfs(i - 1, j, index + 1, board, word, visited);
    }
    if(j + 1 < board[0].size())
    {
        if(!visited[i][j + 1] && board[i][j + 1] == (char)word[index + 1])
            ans = ans || dfs(i, j + 1, index + 1, board, word, visited);
    }
    if(j - 1 >= 0)
    {
        if(!visited[i][j - 1] && board[i][j - 1] == (char)word[index + 1])
            ans = ans || dfs(i, j - 1, index + 1, board, word, visited);
    }
    if(!ans)
            visited[i][j] = false;
    return ans;
}
public:
    bool exist(vector<vector<char>>& board, string word) {
        bool ans = false;
        
        for(int i = 0; i < board.size(); i++)
        {
            for(int j = 0; j < board[0].size(); j++)
            {
                if(board[i][j] == (char)word[0])
                {
                    vector<vector<bool> > visited
                        (board.size(), vector<bool> (board[0].size(), false));
                    ans = ans || dfs(i, j, 0, board, word, visited);
                }
            }
        }
        
        return ans;
    }
};
