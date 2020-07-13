//Number of Islands -> 07/13/2020 20:49
class Solution {
// void BFS(int i, int j, vector<vector<char>>& grid)
// {
//     queue<pair<int, int> > bfs;
//     bfs.push(make_pair(i, j));
//     while(!bfs.empty())
//     {
//         i = bfs.front().first;
//         j = bfs.front().second;
//         grid[i][j] = '0';
//         if(i + 1 < grid.size() && grid[i+1][j] == '1')
//             bfs.push(make_pair(i+1, j));
//         if(j + 1 < grid[0].size() && grid[i][j+1] == '1')
//             bfs.push(make_pair(i, j+1));
//         if(j - 1 >= 0 && grid[i][ j - 1] == '1')
//             bfs.push(make_pair(i, j - 1));
//         if(i - 1 >= 0 &&  grid[i - 1][j] == '1')
//             bfs.push(make_pair(i - 1, j));
//         bfs.pop();
//     }
// }
    
    
// public:
//     int numIslands(vector<vector<char>>& grid) {
//         if(grid.size() == 0)
//             return 0;
//         int m = grid.size(), n = grid[0].size();
        
//         // cout << m << " " << n << endl;
//         // if(m == 0)
//         //     return 0;
//         // vector<vector<int> > visited( m, vector<int> (n, 0));
//         // for(int i = 0;i < m; i++)
//         // {
//         //     for(int j = 0; j < n; j++)
//         //         cout << visited[i][j] << " ";
//         //     cout << endl;
//         // }
//         int count = 0;
//         for(int i = 0; i < m; i++)
//         {
//             for(int j = 0; j < n; j++)
//             {
//                 if(grid[i][j] == '1')
//                 {
//                     BFS(i, j, grid);
//                     count++;
//                 }
//             }
//         }
//         return count;
//     }
      vector<vector<char>> marker;
    int row; int col;
    void mark(int i, int j){
        // This methods marks all the nodes in a single Island
        marker[i][j] = '0';
        if(i>0 && marker[i-1][j]=='1') mark(i-1, j);
        if(i<row && marker[i+1][j]=='1') mark(i+1,j);
        if(j>0 && marker[i][j-1]=='1') mark(i, j-1);
        if(j<col && marker[i][j+1]=='1') mark(i,j+1);
        
    }
    public:
    int numIslands(vector<vector<char>>& grid) {
        row = grid.size()-1;
        // Checking dimensions of grid
        if(row<0) return 0;
        col = grid[0].size()-1;
        if(col<0) return 0;
        // Initializing grid to global variable
        marker = grid;
        int count = 0;
        for(int i=0;i<=row;i++){
            for(int j=0;j<=col;j++){
                if(marker[i][j]=='1'){
                    // Marking the full island if found
                    mark(i,j);
                    count++;
                }
            }
        }
        return count;
        
    }
};
