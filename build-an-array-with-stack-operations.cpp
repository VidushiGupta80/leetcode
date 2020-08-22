//Build an Array With Stack Operations -> 08/22/2020 10:55
class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int num = target[target.size() - 1];
        vector<string> ans;
        for(int i = 1, j = 0; i <= num; i++)
        {
            ans.push_back("Push");
            if(target[j] != i)
            {
                ans.push_back("Pop");
            }
            else
                j++;
        }
        return ans;
    }
};
