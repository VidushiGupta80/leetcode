//Flood Fill -> 07/17/2020 19:34
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        vector<vector<bool> >visited(image.size(), vector<bool> (image[0].size(), false));
        queue<pair<int, int> > bfs;
        bfs.push(make_pair(sr, sc));
        while(!bfs.empty())
        {
            int i = bfs.front().first;
            int j = bfs.front().second;
            visited[i][j] = true;
            if(i < 0 || i >= image.size() || j < 0 || j >= image[0].size())
                bfs.pop();
            
            if((i - 1) >= 0 && (i - 1) < image.size() &&
                image[i - 1][j] == image[i][j] && !visited[i - 1][j])
                bfs.push(make_pair(i - 1, j));
            if((i + 1) >= 0 && (i + 1) < image.size() &&
               image[i + 1][j] == image[i][j]  && !visited[i + 1][j])
                bfs.push(make_pair(i + 1, j));
            if((j - 1) >= 0 && (j - 1) < image[0].size() &&
               image[i][j - 1] == image[i][j]  && !visited[i][j - 1])
                bfs.push(make_pair(i, j - 1));
            if((j + 1) >= 0 && (j + 1) < image[0].size() &&
               image[i][j + 1] == image[i][j]  && !visited[i][j + 1])
                bfs.push(make_pair(i, j + 1));
            
            image[i][j] = newColor;
            bfs.pop();
        }
        return image;
    }
};
