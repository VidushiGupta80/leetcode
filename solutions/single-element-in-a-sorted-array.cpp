//Single Element in a Sorted Array -> 05/23/2020 12:00
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size() == 1)
            return nums[0];
        int left = 0, right = nums.size() - 1, mid;
         mid = left + (right - left) / 2;
        while(left < right && mid != 0)
        {
           
            if(nums[mid - 1] == nums[mid] || nums[mid + 1] == nums[mid])
            {
                if(nums[mid - 1] == nums[mid])
                {
                    int lenLeft = mid;
                    if(lenLeft % 2 == 0)
                        right = mid - 1;
                    else
                        left = mid + 1;
                }
                else if(nums[mid + 1] == nums[mid])
                {
                    int lenRight = nums.size() - 1 - mid;
                    if(lenRight % 2 != 0)
                        right = mid - 1;
                    else 
                        left = mid + 1;
                }
            }
            else
                break;
             mid = left + (right - left) / 2;
        }
         mid = left + (right - left) / 2;
        return nums[mid];
    }
};
