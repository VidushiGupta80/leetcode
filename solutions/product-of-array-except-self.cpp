//Product of Array Except Self -> 08/13/2020 13:51
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int prod = 1;
        int j;
        if(count(nums.begin(),nums.end(), 0) > 1)
            return vector<int> (nums.size(), 0);
        
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] != 0)
                prod *= nums[i];
            else
                j = i;
        }
        if(count(nums.begin(),nums.end(), 0) == 1)
        {
            vector<int> ans(nums.size(), 0);
            ans[j] = prod;
            return ans;
        }
        vector<int> ans(nums.size(), prod);
        
        for(int i = 0; i < nums.size(); i++)
        {
            ans[i] = ans[i] / nums[i];
        }
        return ans;
    }
};
