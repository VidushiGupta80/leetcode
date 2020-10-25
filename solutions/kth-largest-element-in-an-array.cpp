//Kth Largest Element in an Array -> 08/18/2020 17:16
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        make_heap(nums.begin(), nums.end());
        int x;
        while(k > 0)
        {
            x = nums.front();
            pop_heap(nums.begin(), nums.end());
            nums.pop_back();
            k--;
        }
        return x;
    }
};
