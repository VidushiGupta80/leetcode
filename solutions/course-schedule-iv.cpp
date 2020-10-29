class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prereq, vector<vector<int>>& queries) {
        vector<vector<int> > adj(n);
        vector<vector<bool> > dp(n, vector<bool> (n, false));
        for(int i = 0; i < prereq.size(); i++)
        {
            adj[prereq[i][0]].push_back(prereq[i][1]);
            dp[prereq[i][0]][prereq[i][1]] = true;
        }
        vector<bool> ans(queries.size());
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                for(int k = 0; k < n; k++)
                    dp[j][k] = dp[j][k] || (dp[j][i] && dp[i][k]);
            }
        }
        for(int i = 0; i < queries.size(); i++)
        {           
           ans[i] = dp[queries[i][0]][queries[i][1]];
        }
        return ans;
    }
};
