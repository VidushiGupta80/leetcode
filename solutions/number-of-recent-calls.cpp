//Number of Recent Calls -> 10/01/2020 13:46

class RecentCounter {
public:
    vector<int> req;
    RecentCounter() {
        
    }
    
    int ping(int t) {
        req.push_back(t);
        int finder = t - 3000;
        if(finder < 0)
            return req.size();
        int index = 0;
        while(req[index] < finder)
            index++;
        return req.size() - index;
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */