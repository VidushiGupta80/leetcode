//Permutations -> 08/10/2020 22:46
class Solution {
    
void dp(int index, vector<bool>& taken, vector<int>& temp, 
        vector<int>& nums, vector<vector<int> >& result)
{
    if(index == nums.size())
    {
        result.push_back(temp);
        return;
    }
    
    for(int i = 0; i < nums.size(); i++)
    {
        if(!taken[i])
        {
            temp.push_back(nums[i]);
            taken[i] = true;
            dp(index + 1, taken, temp, nums, result);
            taken[i] = false;
            temp.pop_back();
        }
    }
    return;
}
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> taken(nums.size(), false);
        vector<int> temp;
        vector<vector<int> > result;
        dp(0, taken, temp, nums, result);
        return result;
    }
};
