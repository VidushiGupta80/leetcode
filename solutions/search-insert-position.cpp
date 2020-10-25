//Search Insert Position -> 05/01/2020 18:07
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int right = nums.size() - 1;
        int left = 0;
        if(target > nums[right])
            return right + 1;
        if(target < nums[left])
            return 0;
        int mid = (right - left) / 2;
        while(true)
        {
            if(target ==  nums[mid])
            {
                return mid;
                break;
            }
            else if(target > nums[mid])
            {
                if(target > nums[mid + 1])
                {
                    left = mid;
                    mid += (right - left) / 2;
                }
                else if(target <= nums[mid + 1])
                {
                    return mid + 1;
                }
                
            }
            else if(target < nums[mid])
            {
                if(target < nums[mid - 1])
                {
                    right = mid;
                    mid = (right - left) / 2;                    
                }
                else if(target == nums[mid - 1])
                    return mid - 1;
                else if(target > nums[mid - 1])
                    return mid;
            }
        }
    }
};
