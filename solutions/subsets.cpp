//Subsets -> 08/12/2020 22:11
class Solution {
void dp(int index, vector<int>& nums, vector<vector<int> >& ans, vector<int> temp)
{
    if(index >= nums.size())
    {
        ans.push_back(temp);
        return;
    }
    
    dp(index + 1, nums, ans, temp);
    temp.push_back(nums[index]);
    dp(index + 1, nums, ans, temp);
    
    return;
    
    
}
    
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int> > ans;
        vector<int> temp;
        dp(0, nums, ans, temp);
        return ans;
    }
};
