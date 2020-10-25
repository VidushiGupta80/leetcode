//Evaluate Division -> 07/13/2020 20:36
class Solution {
// private:
    
//     int findEdge(string N, string D, map<string, vector<pair<string, double> > >& adj)
//     {
//         map<string, vector<pair<string, double> > > :: iterator it = adj.find(N);
//         for(int i = 0; i < it->second.size(); i++)
//         {
//             if((char)it->second.first == D)
//                 return it->second[i][1];
//         }
//         return -1;
//     }
    
//     int findCommon(string N, string D, map<string, vector<pair<string, double> > >& adj)
//     {
//         map<string, vector<pair<string, double> > > :: iterator it = adj.begin();
//         int ans = -1;
//         for(; it != adj.end(); it++)
//         {
//             if((char)it->first == N || (char)it->first == D)
//                 continue;
//             else
//             {
//                 int num, den;
//                 for(int i = 0; i < it->second.size(); i++)
//                 {
//                     if((char)it->second[i][0] == N)
//                     {
//                         den = it->second[i][1];
//                         for(; i < it->second.size(); i++)
//                         {
//                             if((char)it->second[i][0] == D)
//                             {
//                                 num = it->second[i][1];
//                                 ans = num / den;
//                             }
//                         }
//                     }
//                     else if((char)it->second[i][0] == D)
//                     {
//                         num = it->second[i][1];
//                         for(; i < it->second.size(); i++)
//                         {
//                             if((char)it->second[i][0] == N)
//                             {
//                                 den = it->second[i][1];
//                                 ans = num / den;
//                             }
//                         }
//                     }
//                 }
//             }
//         }
//         return ans;
//     }
    
    
// public:
//     vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
//         vector<double> ans;
//         map<string, vector<pair<string, double> > > adj;
//         for(int i = 0; i < values.size(); i++)
//         {
//             adj[equations[i][0]].push_back(make_pair(equations[i][1], values[i]));
//             adj[equations[i][1]].push_back(make_pair(equations[i][0], 1.0 / values[i]));
//         }
//         for(int i = 0; i < queries.size(); i++)
//         {
//             if(adj.find(queries[i][0]) != adj.end() && adj.find([i][0]) != adj.end())
//             {
//                 if(queries[i][0] == queries[i][1])
//                     ans.push_back(1);
//                 else
//                 {
//                     int div = findEdge(queries[i][0], queries[i][1], adj);
//                     if(div > 0)
//                         ans.push_back(div);
//                     else
//                     {
//                         div = findEdge(queries[i][1], queries[i][0], adj);
//                         if(div > 0)
//                             ans.push_back(div);
//                         else
//                         {
//                             div = findCommon(queries[i][0], queries[i][1], adj);
//                             if(div > 0)
//                                 ans.push_back(div);
//                             else
//                                ans.push_back(-1.0); 
//                         }
//                     }
//                 }
//             }
//             else
//                 ans.push_back(-1.0);
//         }
//         return ans;
//     }
    
    
     vector<double> res;   //to store final output
     map<string,vector<pair<string,double>>> adj; //Create a map to store adjacency list
    
    void find(string x,string y,map<string,int> &vis,double rs)
    {  
        vis[x]=1;
        if(x==y){
          res.push_back(rs);return;
        }
        for(int i=0;i<adj[x].size();i++)
        {  
            string p=adj[x][i].first;
           
            if( vis.count(p)==0)
            {    
                find(p,y,vis,rs*adj[x][i].second);
            }
        }
         
        return;
    }
    public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        
        // ios_base::sync_with_stdio(false);
        // cin.tie(NULL);
        
        if(equations.size()==0) return res;
        if(equations[0].size()==0) return res;
        
         
        
        for(int i=0;i<equations.size();i++)
        {   
            string x=equations[i][0],y=equations[i][1]; 
            double val=values[i]; 
            adj[x].push_back({y,val});   //store weight of path like x/y=2, x->y (2)
            adj[y].push_back({x,double(1)/val}); //store reverse path x/y=2 , y->x (1/2)
        }
       
         
        for(int i=0;i<queries.size();i++)  //traverse queries
        {   
             string x=queries[i][0],y=queries[i][1];
            if(adj.count(x)==0||adj.count(y)==0) 
             {
                res.push_back(double(-1));continue; 
                //check if variable is absent in equation then result will be -1.00
             }
              
             map <string,int> vis; //create visites map to check visited variables
            //call find function to solve query 
             find(x,y,vis,double(1)*(1.0));
            //if we didn't find val like for x/y=2 , p/q=3
            //we have to find x/p which is impossible so we will insert -1.00
             if(res.size()!=i+1) res.push_back(double(-1));
            
        }
        return res;
        
    }
};
