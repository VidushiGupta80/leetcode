class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> left(height.size());
        vector<int> right(height.size());
        int maxTillNow = 0;
        for(int i = 0; i < height.size(); i++){
            left[i] = maxTillNow;
            maxTillNow = max(maxTillNow, height[i]);
        }
        maxTillNow = 0;
        for(int i  =height.size() - 1; i >= 0; i--){
            right[i] = maxTillNow;
            maxTillNow = max(maxTillNow, height[i]);
        }
        int ans = 0;
        for(int i = 0; i < height.size(); i++){
            int ht = min(left[i], right[i]);
            ht = ht - height[i];
            if(ht > 0)
                ans += ht;
        }
        return ans;
    }
};