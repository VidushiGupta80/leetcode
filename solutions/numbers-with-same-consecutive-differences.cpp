//Numbers With Same Consecutive Differences -> 08/19/2020 11:12

void rec(int index, int num, int N, int K, vector<int>& ans)
{
    if(index == N)
    {
        vector<int> :: iterator it;
        it = find(ans.begin(), ans.end(), num);
        if(it == ans.end())
            ans.push_back(num);
        return;
    }
    
    int temp = num % 10;
    if(temp + K <= 9)
    {
        rec(index + 1, num * 10 +(temp + K), N, K, ans);
    }
    if(temp - K >= 0)
        rec(index + 1, num * 10 + (temp - K), N, K, ans);
    return;
}
class Solution {
public:
    vector<int> numsSameConsecDiff(int N, int K) {
        int temp = 0;
        vector<int> ans;
        if(N == 1)
            ans.push_back(0);
        for(int i = 1; i <= 9; i++)
        {
            temp = i;
            if(N > 1 && temp + K <= 9)
            {
                rec(2, temp * 10 +(i + K), N, K, ans);
            }
            if(N > 1 && temp - K >= 0)
                rec(2, temp * 10 + (i - K), N, K, ans);
            else if(N == 1)
                ans.push_back(temp);
        }
        return ans;
    }
};