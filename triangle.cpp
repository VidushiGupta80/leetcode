//Triangle -> 09/02/2020 19:02
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> cache(triangle.size(), INT_MAX);
        for(int i = 0; i < triangle.size(); i++)
        {
            vector<int> temp = cache;
            for(int j = 0; j < triangle[i].size(); j++)
            {
                if(i == 0)
                    temp[i] = triangle[i][j];
                else if(i > 0 && j == 0)
                    temp[j] = triangle[i][j] + cache[j];
                else if(i > 0 && j == triangle[i].size() - 1)
                    temp[j] = triangle[i][j] + cache[j - 1];
                else
                    temp[j] = min(cache[j - 1] + triangle[i][j], cache[j] + triangle[i][j]);
                   
            }
            cache = temp;
        }
        return *min_element(cache.begin(), cache.end());
    }
};
