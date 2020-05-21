//Find Minimum in Rotated Sorted Array -> 05/21/2020 17:42
class Solution {
public:
    int findMin(vector<int>& nums) {
        
        int left = 0, right = nums.size() - 1, mid;
        if(right == 0)
            return nums[right];
        
        else if(nums.size() == 2)
        {
            if(nums[left] < nums[right])
                return nums[left];
            else 
                return nums[right];
        }
        while(left <= right)
        {
            mid = left + (right - left) / 2;
           
             if(nums[mid] < nums[mid - 1] && nums[mid] < nums[mid + 1])
                return nums[mid];
            else if(nums[mid] < nums[right] && nums[mid] < nums[left])
            {
                right = mid;
            }
            else if(nums[mid] > nums[right] && nums[mid] > nums[left])
            {
                left = mid;
            }
            else if(nums[mid] < nums[right] && nums[mid] > nums[left])
            {
                return nums[left];
            }
            else if(nums[mid] == nums[left] && nums[right] == nums[mid])
            {
               return nums[mid];
            }
             else if(right - left == 1)
            {
                if(nums[left] < nums[right])
                    return nums[left];
                else 
                    return nums[right];
            }
              
            
            
        }
        return -1;
        
        
        
        
        
        
        
//         size_t length = nums.size();
//         size_t left = 0, right = length - 1, mid = (right - left) / 2 ;
//         while(left <= right)
//         {
//             mid = left + (right - left) / 2;
//             if((nums[mid - 1] > nums[mid] && nums[mid + 1] > nums[mid]) || mid == 0 || mid == length - 1)
//                 return nums[mid];
//            else if(nums[left] < nums[mid] && nums[mid] > nums[right])
//             {
//                 left = mid + 1;
               
//             }
//             else if((nums[left] > nums[mid] && nums[mid] < nums[right]) || 
//                     (nums[left] < nums[mid] && nums[mid] < nums[right]))
//             {
//                 right = mid - 1;
               
//             }
//         }
//         return -1;
    }
};
