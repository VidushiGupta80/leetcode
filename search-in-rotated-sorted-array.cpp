//Search in Rotated Sorted Array -> 05/16/2020 15:34
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1, mid;
        if(right == 0 && nums[right] == target)
            return right;
        else if(right == 0 && nums[right] != target)
            return -1;
        else if(nums.size() == 2)
        {
            if(nums[left] == target)
                return left;
            else if(nums[right] == target)
                return right;
            else 
                return -1;
        }
        while(left <= right)
        {
            mid = left + (right - left) / 2;
           
             if(nums[mid] == target)
                return mid;
            else if(nums[mid] < nums[right] && nums[mid] < nums[left])
            {
                if(target > nums[mid] && target <= nums[right])
                    left = mid + 1;
                else
                    right = mid - 1;
            }
            else if(nums[mid] > nums[right] && nums[mid] > nums[left])
            {
                if(target >= nums[left] && target < nums[mid])
                    right = mid - 1;
                else
                    left = mid + 1;
            }
            else if(nums[mid] < nums[right] && nums[mid] > nums[left])
            {
                if(target >= nums[left] && target < nums[mid])
                    right = mid - 1;
                else
                    left = mid + 1;
            }
            else if(nums[mid] == nums[left] || nums[right] == nums[mid])
            {
               if(nums[left] == target)
                    return left;
                else if(nums[right] == target)
                    return right; 
                else 
                    break;
                
            }
            
            
        }
        return -1;
    }
};
