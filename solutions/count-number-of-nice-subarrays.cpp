//Count Number of Nice Subarrays -> 05/28/2020 11:33
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int nice = 0;
        int sum = 0;
        int len = nums.size();
        // int i = 0, j = 1, start = 0, end, left, right;
        map<int, int> count;
        for(int i = 0; i < len; i++)
        {
            sum += (nums[i] % 2);
            if(count.find(sum) != count.end())
            {
                count[sum]++;
            }
            else 
                count.insert(make_pair(sum, 1));
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
        }
        return nice;
        
        
        
        
        
//         while(j < len)
//         {
//             if(nums[start] % 2 != 0)
//             {
//                 i = start;
//             }
//             else
//                 i = start + 1;
            
                
//             while(nums[i] % 2 == 0)
//             {
//                 i++;
//             }
//             if(j < i)
//                 j = i;
            
//             while(countOdd < k )
//             {
//                 if(j < len - 1)
//                 {
//                     j++;
//                     while(j < len && nums[j] % 2 == 0)
//                         j++;
//                     if(nums[j] % 2 != 0)
//                         countOdd++;
//                     else if(j >= len)
//                         j = len;;
//                 }
//             }
//             end = j + 1;
//             while(end < len && nums[end] % 2 == 0)
//                 end++;
//             if(nums[end] % 2 != 0 || end >= len)
//                 end--;
//             if(countOdd == k)
//             {
//                 left = i - start;
//                 right = end - j;
//                 nice = nice + ((left + 1) * (right + 1));
//                 countOdd--;
//                 start = i + 1;
//             }
//             else
//                 break;
            
//         }
//         return nice;
    }
};
