//Destination City -> 06/13/2020 23:42
class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        set<string> s;
        set<string> d;
        int len = paths.size();
        // s.insert(paths[0][0]);
        // d.insert(paths[0][1]);
        for(int i = 0; i < len; i++)
        {
            if(!d.empty())
            {
                if(d.find(paths[i][0]) != d.end())
                    d.erase(d.find(paths[i][0]));
                else 
                    s.insert(paths[i][0]);
            }
            else
                s.insert(paths[i][0]);
            if(!s.empty())
            {
                if(s.find(paths[i][1]) != s.end())
                    s.erase(s.find(paths[i][1]));
                else
                    d.insert(paths[i][1]); 
            }
            else
                 d.insert(paths[i][1]);
           
        }
        // cout << d.size() << " " << s.size();
        set<string> :: iterator it = d.begin();
        return *it;
    }
};
