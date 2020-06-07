//Pascal's Triangle -> 06/07/2020 18:33
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
        vector<int> subArr;
        vector<vector<int> > ans;
        if(numRows == 0)
            return ans;
        subArr.push_back(1);
        ans.push_back(subArr);
        subArr.clear();
        
        numRows--;
       
        for(int i = 0; i < numRows; i++)
        {
            for(int j = 0; j <= ans[i].size(); j++)
            {
                if(j == 0)
                    subArr.push_back(1);
                else if(j == ans[i].size())
                    subArr.push_back(1);
                else
                {
                    subArr.push_back(ans[i][j - 1] + ans[i][j]);
                }
            }
            ans.push_back(subArr);
            subArr.clear();
        }
        return ans;
        
    }
};
