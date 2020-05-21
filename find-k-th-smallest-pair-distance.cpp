//Find K-th Smallest Pair Distance -> 05/21/2020 20:26
class Solution {
    int count(vector<int>& nums, int n, int d) {
        int ans = 0;
        int j = 1;
        for (int i = 0; i < n; i++) {
            while (j < n && nums[j]-nums[i] <= d) j++;
            ans += j-i-1;
        }
        return ans;
    }
public:
    int smallestDistancePair(vector<int>& nums, int k) {
         int n = nums.size();
        sort(nums.begin(), nums.end());
        
        int l = 0, r = nums[n-1]-nums[0];
        while (l < r) {
            int m = l + (r-l)/2;
            
            if (count(nums, n, m) >= k)
                r = m;
            else
                l = m+1;
        }
        
        return l;
    }
};
