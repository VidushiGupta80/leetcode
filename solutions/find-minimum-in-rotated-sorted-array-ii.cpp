//Find Minimum in Rotated Sorted Array II</a -> 07/23/2020 14:11
class Solution {
public:
    int findMin(vector<int>& nums) {
        // size_t length = nums.size();
        // size_t left = 0, right = length - 1, mid = (right - left) / 2 ;
        // while(true)
        // {
        //     if((nums[mid - 1] > nums[mid] && nums[mid + 1] > nums[mid]) || mid == 0 || mid == length - 1)
        //         return nums[mid];
        //     else if(nums[left] < nums[mid] && nums[mid] > nums[right])
        //     {
        //         left = mid;
        //         mid = mid + (right - mid) / 2;
        //     }
        //     else if((nums[left] > nums[mid] && nums[mid] < nums[right]) || 
        //             (nums[left] < nums[mid] && nums[mid] < nums[right]))
        //     {
        //         right = mid;
        //         mid = (right - left)/ 2;
        //     }
        // }
        
        
//         int left = 0, right = nums.size() - 1, mid;
//         if(right == 0)
//             return nums[right];
        
//         else if(nums.size() == 2)
//         {
//             if(nums[left] <= nums[right])
//                 return nums[left];
//             else 
//                 return nums[right];
//         }
//         while(left <= right)
//         {
//             mid = left + (right - left) / 2;
           
//              if(nums[mid] < nums[mid - 1] && nums[mid] < nums[mid + 1])
//                 return nums[mid];
//             else if(nums[mid] < nums[right] && nums[mid] < nums[left])
//             {
//                 right = mid;
//             }
//             else if(nums[mid] > nums[right] && nums[mid] > nums[left])
//             {
//                 left = mid;
//             }
//             else if(nums[mid] < nums[right] && nums[mid] > nums[left])
//             {
//                 return nums[left];
//             }
//             else if(nums[mid] == nums[left] && nums[right] == nums[mid])
//             {
//                return nums[mid];
//             }
//              else if(right - left == 1)
//             {
//                 if(nums[left] < nums[right])
//                     return nums[left];
//                 else 
//                     return nums[right];
//             }
              
            
            
//         }
//         return -1;
        
        
        int n = nums.size();
        
        if(n == 0) return 0;
        if(n == 1) return nums[0];
        
        int mn = INT_MAX;
        
        for(int i = 1; i < n; i++) {
            if(nums[i - 1] > nums[i]) return nums[i];
        }
        
        return nums[0];
    }
};
