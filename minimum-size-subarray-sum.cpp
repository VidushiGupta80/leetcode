//Minimum Size Subarray Sum -> 05/27/2020 16:25
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int len = nums.size();
        if(len == 0)
            return 0;
        else if(len == 1)
        {
            if(nums[0] >= s)
                return 1;
            return 0;
        }
        int ans = len + 1;
        int sum = nums[0];
        int i = 0, j = 0;
        for(; i < len, i <= j ; )
        {
            if(sum >= s)
            {
                ans = min(ans, j - i + 1);
                 sum -= nums[i];
                i++;
                 
            }
            if(sum < s)
            {
                
              if(j < len - 1)
              {
                j++;
                sum += nums[j];
              }
            else 
               break;
            }
           
           
        }
        if(ans == len + 1)
            return 0;
        else 
            return ans;
    }
};
