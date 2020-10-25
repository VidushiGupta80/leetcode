//Frog Jump -> 10/23/2020 19:25
class Solution {
bool dp(int pos, int lastJump, vector<int>& stones, map<pair<int, int> , bool>& cache, set<int>& positions)
{
    if(pos == stones[stones.size() - 1])
        return true;
    if(pos > stones[stones.size() - 1])
        return false;
    if(cache.find({pos, lastJump}) != cache.end())
        return cache[{pos, lastJump}];
    bool ans = false;
    for(int i = lastJump - 1; i <= lastJump + 1; i++)
    {
        if(i <= 0)
            continue;
        else if(positions.find(pos + i) != positions.end())
        {
            bool temp = dp(pos + i, i,stones, cache, positions);
            ans = ans || temp;
        }
        
    }
    return cache[{pos, lastJump}] = ans;
}
public:
    bool canCross(vector<int>& stones) {
        set<int> positions;
        for(int i = 0; i < stones.size(); i++)
            positions.insert(stones[i]);
        map<pair<int, int>, bool> cache;
        return dp(0, 0, stones, cache, positions);
    }
};
