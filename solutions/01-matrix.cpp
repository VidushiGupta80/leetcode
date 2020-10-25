//01 Matrix -> 07/14/2020 12:31
class Solution {
    
// private:
//     int update(int i, int j, vector<vector<int>>& matrix, map<pair<int, int>, int>& cache)
//     {
//        if(i >= matrix.size() || i < 0 || j >= matrix[0].size() || j < 0)
//            return INT_MAX;
//         if(matrix[i][j] == 0)
//             return 0;
        
//         map<pair<int, int>, int> :: iterator it = cache.find(make_pair(i, j));
//         if(it != cache.end())
//             return cache[make_pair(i, j)];
        
//         matrix[i][j] = 1 + min(update(i + 1, j, matrix, cache), min(update(i, j+1, matrix, cache), min(update(i - 1, j, matrix, cache), 
    update(i, j - 1, matrix, update))));
        
//         cache[make_pair(i, j)] = matrix[i][j];
//         return matrix[i][j];
//     }
    
    
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
       // map<pair<int, int>, int> cache;
        queue<pair<int, pair<int, int> > > bfs;
        for(int i = 0; i < matrix.size(); i++)
        {
            for(int j = 0; j < matrix[0].size(); j++)
            {
                if(matrix[i][j] == 0)
                  bfs.push(make_pair(i, make_pair(j, 0)));
            }
        }
        
        vector<vector<bool> > visited(matrix.size(), vector<bool> (matrix[0].size(), false));
        while(!bfs.empty())
        {
            int i = bfs.front().first, j = bfs.front().second.first, 
                    level = bfs.front().second.second;
            if(i >= matrix.size() || i < 0) 
            {
                bfs.pop();  
                continue;
            }
            if(j >= matrix[0].size() || j < 0)
            {
                 bfs.pop();  
                continue;
            }
            if(visited[i][j])
            {
                 bfs.pop();  
                continue;
            }
            else if(!visited[i][j])
            {
                visited[i][j] = true;
                bfs.push(make_pair(i + 1, make_pair(j, level+1)));
                bfs.push(make_pair(i - 1, make_pair(j, level+1)));
                bfs.push(make_pair(i, make_pair(j + 1, level+1)));
                bfs.push(make_pair(i, make_pair(j - 1, level+1)));
                matrix[i][j] = level;
            }
        }
        return matrix;
    }
};
