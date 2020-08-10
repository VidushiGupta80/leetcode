//Queue Reconstruction by Height -> 08/10/2020 22:14
bool sortCol(vector<int> arr1, vector<int> arr2)
{
    return arr1[0] != arr2[0] ? arr1[0] < arr2[0] : arr1[1] < arr2[1];
}
class Solution {
    

public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), sortCol);
        int n = people.size();
        // for(int i = 0; i < n; i++)
        //     cout << people[i][0] << " " << people[i][1] << endl;
        vector<bool> pos(n, false);
        vector<vector<int> > ans(n, vector<int> (2));
        for(int i = 0; i < n; i++)
        {
            int height = people[i][0];
            int ahead = people[i][1];
            // cout << "outer loop: " << height << " " << ahead << endl;
            // int sum = 0;
            for(int j = 0; j < n; j++)
            {
                // cout << "--inner loop: " << j << " " << pos[j] << " " << ahead << endl;
                if(!pos[j] && ahead == 0)
                {
                    pos[j] = true;
                    ans[j][0] = people[i][0];
                    ans[j][1] = people[i][1];
                    // cout << "done: " << j << endl; 
                    break;
                }
                else if(pos[j])
                {
                    if(ans[j][0] >= height)
                    {
                        ahead--;
                    }
                }
                else if(!pos[j] && ahead != 0)
                    ahead--;
            }
        }
        return ans;
    }
};
