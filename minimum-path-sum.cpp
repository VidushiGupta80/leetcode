//Minimum Path Sum -> 06/24/2020 23:19
class Solution {
private:
    long dp(int rows, int columns, vector<vector<int>>& grid, map<pair<int, int>, int>& cache)
    {
        if(rows == 0 && columns == 0)
            return grid[0][0];
        map<pair<int, int>, int> :: iterator it = cache.find(make_pair(rows,columns));
        if(it != cache.end())
            return cache[make_pair(rows, columns)];
        int left = INT_MAX - 10;
        if(columns >= 1)
            left = dp(rows, columns - 1, grid, cache);
        int top = INT_MAX - 10;
        if(rows >= 1)
            top = dp(rows - 1, columns, grid, cache);
        long ans = grid[rows][columns] + min(top, left);
        cache.insert(make_pair(make_pair(rows, columns), ans));
        return ans;
        
    }
        
public:
    int minPathSum(vector<vector<int>>& grid) {
        int rows = grid.size();
        int columns = grid[0].size();
        // cout << rows << columns;
        map<pair<int, int>, int> cache;
        int answer = dp(rows - 1, columns - 1, grid, cache);
        return answer;
    }
};
