//Redundant Connection -> 06/16/2020 17:34
class Solution {
private:
    int Find(int a, vector<int>& parent)
    {
        if(parent[a] == a)
            return a;
        int par_a = Find(parent[a], parent);
        return par_a;
    }
    
    void Union(int i, int j, vector<int>& parent, vector<vector<int> >& ans)
    {
        int par_i = Find(i, parent);
        int par_j = Find(j, parent);
        if(par_i == par_j)
        {
            vector<int> temp;
            temp.push_back(i);
            temp.push_back(j);
            ans.push_back(temp);
        }
        else
            parent[par_j] = par_i;
        return;
    }
            
    
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        // vector<bool> visited(1000, false);
        vector<vector<int> > ans;
        int n = edges.size();
        vector<int> parent(n + 1);
        for(int i = 1; i < n + 1; i++)
            parent[i] = i;
        int k = 0;
        vector<int> temp;
        for(int i = 0; i < n; i++)
        {
           Union(edges[i][0], edges[i][1], parent, ans);
        }
        vector<int> result;
        k = ans.size();
        result.push_back(ans[k - 1][0]);
        result.push_back(ans[k - 1][1]);
        return result;
    }
};
