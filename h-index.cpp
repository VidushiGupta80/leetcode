//H-Index -> 08/11/2020 23:26
class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int n = citations.size();
        int ans = 0;
        if(n == 0)
            return 0;
        int i;
        for(i = n - 1; i >= 0; i--)
        {
            if(citations[i] >= n - i)
                ans = max(ans, n - i);
        }
        // if(i < 0)
        //     return 0;
        return ans;
    }
};
