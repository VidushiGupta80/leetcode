//Find Eventual Safe States -> 07/19/2020 22:33

class Solution {
private:
    bool dfs(int i, vector<vector<int>>& graph, vector<bool>& notCycle,
            vector<bool>& visited)
    {
        // cout << "entering " << i << endl;
        visited[i] = true;
        // cout << i << " " << graph[i].size() << endl;
        if(graph[i].size() == 0)
        {
            notCycle[i] = true;
             // cout << "recBase: " << i << " " << notCycle[i] << endl;
            return true;
        }
        
        bool state = true;
        for(int j = 0; j < graph[i].size(); j++)
        {
            // cout << "size " << i << " " << graph[i].size()<< endl;
            // cout<< "check " << i << "-->" << graph[i][j] << " " << visited[graph[i][j]] << " " <<
                // notCycle[graph[i][j]] << endl;
            if(!visited[graph[i][j]])
                state = state && dfs(graph[i][j], graph, notCycle, visited);
            else if(visited[graph[i][j]] && notCycle[graph[i][j]])
                state = state && true;
            else if(visited[graph[i][j]] && !notCycle[graph[i][j]])
                state = state && false;
            // else
            //     cout << " one more condition " << graph[i][j] << endl;
        }
        
        notCycle[i] = state;
         // cout << "rec: " << i << " " << notCycle[i] << endl;
        return state;
    }
    
    
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<bool> notCycle (graph.size(), false);
        vector<bool> visited(graph.size(), false);
        
        for(int i = 0; i < graph.size(); i++)
        {
            if(!visited[i])
            {
                 
                notCycle[i] = dfs(i, graph, notCycle, visited);
                // cout << "first loop: " << i << " " << notCycle[i] << endl;
            }
        }
        vector<int> ans;
        for(int i = 0; i < graph.size(); i++)
        {
            // cout << "last loop: " << i << " " << notCycle[i] << endl;
            if(notCycle[i])
                ans.push_back(i);
        }
        return ans;
    }
};