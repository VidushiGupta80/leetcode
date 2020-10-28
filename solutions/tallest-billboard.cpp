//Tallest Billboard -> 07/04/2020 18:25
class Solution {
    
private:
    int dp(int i, int diff, vector<unordered_map<int, int> >& cache, vector<int>& rods)
    {
        if(i == rods.size() && diff == 0)
            return 0;
        if(i == rods.size() && diff != 0)
            return INT_MIN;
        
        unordered_map<int, int> :: iterator it = cache[i].find(diff);
        if(it != cache[i].end())
            return it->second;
        
        int ans = max(rods[i] + dp(i + 1, diff + rods[i], cache, rods),
                      max(dp(i + 1, diff - rods[i], cache, rods), dp(i + 1, diff, cache, rods)));
        cache[i].insert(make_pair(diff, ans));
        return ans;
    }
    
public:
    int tallestBillboard(vector<int>& rods) {
        
        vector<unordered_map<int,int> > cache(rods.size());
        int ans = dp(0, 0, cache, rods);
        // if(ans < 0)
        //     ans = 0;
        return ans;
    }
};
