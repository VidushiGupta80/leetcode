//Complement of Base 10 Integer -> 10/07/2020 20:30

int toggle(int n)
{
    if(n == 1)
        return 0;
    return 1;
}
class Solution {
public:
    int bitwiseComplement(int N) {
        int ans = 0;
        stack<int> stk;
        while(true)
        {
            int rem = N % 2;
            stk.push(rem);
            N = N / 2;
            if(N == 0)
                break;
        }
        while(!stk.empty())
        {
            ans = ans * 2 + toggle(stk.top());
            stk.pop();
        }
        return ans;
    }
};