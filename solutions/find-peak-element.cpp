//Find Peak Element -> 05/21/2020 13:25
// int check(vector<int>& nums, int left, int right)
// {
//     int mid = left + (right - left) / 2;
//     // if(nums[left + 1] < nums[left] && nums[left] > nums[left - 1])
//     //     return left;
//     // else if(nums[right - 1] < nums[right] && nums[right] > nums[right + 1])
//     //     return right;    
//     if(nums[mid - 1] < nums[mid] && nums[mid + 1] < nums[mid])
//         return mid;
//     else if((right - left) < 3)
//         return -2;
    
//     else
//     {
//         int checkLeft = check(nums, left, mid);
//         if(checkLeft == -2)
//         {
//             int checkRight = check(nums, mid, right);
//             return checkRight;
//         }
//         return checkLeft;
//     }
            
// }
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
//         if(nums.size() == 1)
//             return 0;
//         int left = 0, right = nums.size() - 1;
               
//         return(check(nums, left, right));
            
//     }
        
        
        
        
        if(nums.size() == 1) return 0;
        
        if(nums[0] > nums[1]) return 0;
        else if(nums[nums.size() - 1] > nums[nums.size() - 2]) return nums.size() - 1;
        else return helper(nums, 0, nums.size() - 1);
    }
    
private:
    int helper(vector<int> &nums, int low, int high)
    {
        if(high - low + 1 <= 2) return -1;
        
        int mid = low + (high - low) / 2;
        if(nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1])
            return mid;
        else
        {
            int left = helper(nums, low, mid);
            if(left != -1) return left;
            else return helper(nums, mid, high);
        }
    }
};
