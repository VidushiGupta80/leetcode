//Find First and -> 05/17/2020 16:37
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result;
        if(nums.size() == 0)
            {
                result.push_back(-1);
                result.push_back(-1);
                return result;
            }
        int left = 0, right = nums.size() - 1, mid;
        if(nums.size() == 1)
        {
            if(nums[0] == target)
            {
                result.push_back(0);
                result.push_back(0);
                return result;
            }
            else
            {
                result.push_back(-1);
                result.push_back(-1);
                return result;
            }
        }
        
        while(left < right)
        {
            mid = left + (right - left) / 2;
            if(nums[mid] == target)
                break;
            else if(nums[mid] > target)
                right = mid - 1;
            else if(nums[mid] < target)
                left = mid + 1;
        }
        mid = left + (right - left) / 2;
        if(nums[mid] == target)
        {
            if(nums[left] == target)
                result.push_back(left);
            else if(nums[left] != target)
            {
                while(nums[left] != target)
                    left++;
                result.push_back(left);
            }
            
            // if(nums[right] == target)
            //     result.push_back(right);
            // else if(nums[right] != target)
            // {
            //     while(nums[right] != target)
            //         right--;
            // }
            if(nums[nums.size() - 1] == target)
            {
                result.push_back(nums.size() - 1);
                return result;
            }
            while(nums[mid] == target && mid != nums.size() - 1)
                mid++;
            result.push_back(mid - 1);
        }
        else if(nums[mid] != target)
        {
            result.push_back(-1);
            result.push_back(-1);
        }
        return result;
    }
};
