//Edit Distance -> 09/02/2020 14:06
class Solution {
int dp(int indexA, int indexB, string& A, string& B, map<pair<int, int>, int>& cache )
{
    if(indexA == A.size() && indexB < B.size())
        // return B.size() - A.size();
        return B.size() - indexB;
    if(indexB == B.size() && indexA < A.size()) 
        // return A.size() - B.size();
        return A.size() - indexA;
    if(indexA == A.size() && indexB == B.size())
        return 0;
        
    map<pair<int, int>, int> :: iterator it = cache.find(make_pair(indexA, indexB));
    if(it != cache.end())
        return cache[make_pair(indexA, indexB)];
        
    int ans = INT_MAX;
    int add = INT_MAX, del = INT_MAX, rep = INT_MAX;
    if(A[indexA] == B[indexB])
        ans = dp(indexA + 1, indexB + 1, A, B, cache);
    else
    {
        add = 1 + dp(indexA, indexB + 1, A, B, cache);
        del = 1 + dp(indexA + 1, indexB, A, B, cache);
        rep = 1 + dp(indexA + 1, indexB + 1, A, B, cache);
        ans = min(add, min(del, rep));
    }
    cache.insert(make_pair(make_pair(indexA, indexB), ans));
    return ans;
}

public:
    int minDistance(string A, string B) {
         map<pair<int, int>, int> cache;
        int ans = dp(0, 0, A,  B, cache);
        return ans;
    }
};



