//Keys and Rooms -> 07/19/2020 15:29

class Solution {
private:
    void dfs(int i, vector<vector<int>>& rooms, vector<bool>& haveKey, vector<bool>& visited)
    {
        visited[i] = true;
        if(rooms[i].size() == 0)
            return;
        
        
        for(int j = 0; j < rooms[i].size(); j++)
        {
            haveKey[rooms[i][j]] = true;
            if(!visited[rooms[i][j]])
               dfs(rooms[i][j], rooms, haveKey, visited);
            // else if(visited[rooms[i][j]])
            //     state = state || 
        }
        
        return;
    }

public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> haveKey(rooms.size(), false);
        vector<bool> visited(rooms.size(), false);
        haveKey[0] = true;
        
        for(int i = 0; i < rooms.size(); i++)
        {
            if(haveKey[i] && !visited[i])
              dfs(i, rooms, haveKey, visited);
        }
        for(int i = 0; i < rooms.size(); i++)
        {
            if(!haveKey[i] )
                return false;
        }
        return true;
    }
};