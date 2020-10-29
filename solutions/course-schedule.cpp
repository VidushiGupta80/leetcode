class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prereq) {
        vector<int> indeg(n, 0);
        vector<vector<int> > adj(n);
        for(int i = 0; i < prereq.size(); i++)
        {
            indeg[prereq[i][0]]++;
            adj[prereq[i][1]].push_back(prereq[i][0]);
        }
        queue<int> zeros;
        for(int i = 0; i < n; i++)
        {
            if(indeg[i] == 0)
                zeros.push(i);
        }
        while(!zeros.empty())
        {
            int i = zeros.front();
            zeros.pop();
            for(int j = 0; j < adj[i].size(); j++)
            {
                indeg[adj[i][j]]--;
                if(indeg[adj[i][j]] == 0)
                    zeros.push(adj[i][j]);
            }
            
        }
        for(int i = 0; i < n; i++)
        {
            if(indeg[i] > 0)
                return false;
        }
        return true;
    }
};
