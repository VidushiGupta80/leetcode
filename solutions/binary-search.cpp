//Binary Search -> 05/16/2020 15:43

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1, mid;
        if(nums.size() == 1)
        {
            if(nums[0] == target)
                return 0;
            else
                return -1;
        }
        else if(nums.size() == 2)
        {
            if(nums[left] ==  target)
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
            else if(nums[mid] > target)
                right = mid - 1;
            else if(nums[mid] < target)
                left = mid + 1;
            else if(mid == left || mid == right)
            {
                 if(nums[left] ==  target)
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
