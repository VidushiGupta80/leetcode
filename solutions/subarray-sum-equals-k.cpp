//Subarray Sum Equals K -> 08/14/2020 18:34
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        if(k == 0 && nums.size() == 1)
            return 0;
        int nice = 0;
        int sum = 0;
        int len = nums.size();
        // int i = 0, j = 1, start = 0, end, left, right;
        map<int, int> count;
        for(int i = 0; i < len; i++)
        {
            sum += nums[i];
            
            int x = sum - k;
            if(x == 0)
            {
                if(count.find(x) != count.end())
                    nice += (1 + count[x]);
                else
                    nice++;
            }
            else if(x != 0 && count.find(x) != count.end())
                nice += count[x];
            if(count.find(sum) != count.end())
            {
                count[sum]++;
            }
            else 
                count.insert(make_pair(sum, 1));
        }
        return nice;
    }
};
