//Course Schedule II -> 07/13/2020 19:23
class Solution {
// private:
//     void DFS(int i, vector<int>& ans, map<int, vector<int> >& adj, vector<bool>& done)
//     {
//         map<int, vector<int> > :: iterator it = adj.find(i);
        
        
//         for(int i = 0; i < it->second.size(); i++)
//         {
//             if(!done[it->second[i]])
//                 DFS(it->second[i], ans, adj, done);
//         }
//         done[i] = true;
//         ans.push_back(i);
//         return;
//     }
    
//     bool detectCycle(int i, map<int, vector<int> >& adj, vector<bool>& visited, vector<int>& path)
//     {
//         map<int, vector<int> > :: iterator it = adj.find(i);
//         if(it->second.size() == 0)
//             return false;
        
//         bool ans = false;
//         for(int i = 0; i < it->second.size(); i++)
//         {
//             if(!visited[it->second[i]])
//             {
//                 visited[it->second[i]] = true;
//                 path.push_back(it->second[i]);
//                 ans = ans || detectCycle(it->second[i], adj, visited, path); 
//             }
//             else
//             {
//                 vector<int> :: iterator pathItr = find(path.begin(), path.end(), it->second[i]);
//                 if(pathItr != path.end())
//                     return true;
//                 else
//                     return false;
//             }
//         }
        
//         return false;
//     }
// public:
//     vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
//         map<int, vector<int> > adj;
//         vector<bool> done(numCourses, false);
//         vector<bool> visited(numCourses, false);
//         vector<int> ans;
//         for(int i = 0; i < prerequisites.size(); i++)
//         {
//             adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
//         }
//         map<int, vector<int> > :: iterator it = adj.begin();
//         bool cycle = false;
//         vector<int> path;
//         for(; it!= adj.end(); it++)
//         {
//             if(!visited[it->first])
//             {
//                 path.clear();
//                 path.push_back(it->first);
//                 visited[it->first] = true;
//                 cycle = cycle || detectCycle(it->first, adj, visited, path);
//             }
//         }
//         if(cycle)
//             return ans;
        
        
//         for(int i = 0; i < numCourses; i++)
//         {
//             if(adj.find(i) == adj.end())
//             {
//                 done[i] = true;
//                 ans.push_back(i);
//             }
//         }
        
//         for(it = adj.begin(); it != adj.end(); it++)
//         {
//           if(!done[it->first])
//               DFS(it->first, ans, adj, done);
//         }
//         return ans;
//     }
    
    private:
        unordered_set<int> seen;
        unordered_set<int> alreadySeen;
        vector<int> answer;
public:
     bool topsort(vector<vector<int>>& prerequisites, vector<vector<int>> &adjList,int course)
    {
        seen.emplace(course);
        alreadySeen.emplace(course);
        bool noCycle{true};
        for(auto &x:adjList[course])
        {
            if(!seen.count(x))
            {
                noCycle=noCycle &topsort(prerequisites,adjList,x);
            }
            else if(alreadySeen.count(x))
            {
                return false;
            }
        }
         alreadySeen.erase(course);
         answer.push_back(course);
         return noCycle;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) { 
        vector<vector<int>> adjList(numCourses,vector<int>());
        for(int i=0;i<prerequisites.size();i++)
        {
            adjList[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        for(int i=0;i<numCourses;i++)
        {
            if(!seen.count(i))
            {
                if( !topsort(prerequisites,adjList,i) )
                {
                    return{};
                } 
            }   
        }
        reverse(answer.begin(),answer.end());
        return answer ;
    }
    
   
};
