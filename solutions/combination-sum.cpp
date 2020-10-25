//Combination Sum -> 10/07/2020 17:42
void dp(int index, int target, vector<int>& candidates, vector<int> ans, vector<vector<int> >& res)
{
    if(index >= candidates.size())
        return;
    if(target < candidates[index])
        return;
    if(target == candidates[index])
    {
        ans.push_back(target);
        res.push_back(ans);
        return;
    }
    int t = target;
    dp(index + 1, target, candidates, ans, res);
    for(int i = 1; target - i * candidates[index] >= 0; i++)
    {
        t = target - i * candidates[index];
        ans.push_back(candidates[index]);
        dp(index + 1, t, candidates, ans, res);
        if(t == 0)
            res.push_back(ans);
    }
    return;
    
}
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int> > res;
        sort(candidates.begin(), candidates.end());
        vector<int> ans;        
        dp(0, target, candidates, ans, res);
        return res;
       
    }
};
