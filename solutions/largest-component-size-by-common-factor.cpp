//Largest Component Size by Common Factor -> 08/30/2020 18:11

class Solution {
    unordered_map<int,int> pm;//Prime number map
    unordered_map<int,int> cm;//count map
    int parent(int j)
    {
        return (pm[j] == j)?j:(pm[j] = parent(pm[j]));
    }
    
    void calP(int i)
    {
        int m = (int)sqrt(i) + 1;
        int j = 2, fj = -1, k = 0;
        while(j <= m+1)
        {
            k = (j==m+1)?i:j;
            if (k!=1 && i%k==0)
            {  
                if (fj == -1)
                {
                    if (pm.count(k) == 0)
                    {
                        fj = k;
                        cm[fj] = 1;
                    }
                    else
                    {
                        fj = parent(pm[k]);
                        cm[fj] += 1;
                    }
                }
                
                if (pm.count(k) == 0)
                    pm[k] = fj;
                int v = parent(pm[k]);
                if (v != fj)
                {
                    if (cm.count(v) > 0)
                    {
                        cm[fj] += cm[v];
                        cm.erase(v);
                    }
                    pm[k] = pm[v] = fj;
                }
                i/=k;
                while(i%k==0)
                    i/=k;
            }
            j++;
        }
        maxc = max(cm[fj],maxc);
    }

    int maxc;
public:
    int largestComponentSize(vector<int>& A) {
        maxc = 1;
        int n = A.size();
        for (int i=0; i<n; i++)
            calP(A[i]);
        return maxc;
    }
};