//Sort Colors -> 08/30/2020 13:54
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        for(int i = 0; i <= r; )
        {
            if(nums[i] == 0)
            {
                swap(nums[l], nums[i]);
                i++;
                l++;
            }
            else if(nums[i] == 2)
            {
                swap(nums[i], nums[r]);
                 r--;                
            }
            else
                i++;
            
        }
        return;
    }
};
