//Pascal's Triangle II -> 08/12/2020 21:29
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> prev;
        vector<int> latest;
        for(int i = 0; i <= rowIndex; i++)
        {
            for(int j = 0; j <= i; j++)
            {
                if(j == 0 || j == i)
                    latest.push_back(1);
                else
                    latest.push_back(prev[j - 1] + prev[j]);
            }
            prev = latest;
            latest.clear();
        }
        return prev;
    }
};
