//Friend Circles -> 07/12/2020 20:06
class Solution {
 private:
    void BFS(int i, vector<vector<int>>& M)
    {
        queue<int> bfs;
        bfs.push(i);
        while(!bfs.empty())
        {
            i = bfs.front();
            if(M[i][i] == 1)
            {
                M[i][i] = 0;
                for(int j = 0; j < M[0].size(); j++)
                {
                    if(M[i][j] == 1)
                    {
                        bfs.push(j);
                        M[i][j] = 0;
                    }
                }
                
            }
            bfs.pop();
        }
    }
    
public:
    int findCircleNum(vector<vector<int>>& M) {
        if(M.size() == 0)
            return 0;
        int m = M.size(), n = M[0].size();
        int count = 0;
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(M[i][j] == 1)
                {
                    BFS(i, M);
                    count++;
                }
            }
        }
        return count;
    }
};
