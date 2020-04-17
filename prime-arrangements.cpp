//Prime Arrangements -> 04/17/2020 15:45
class Solution {
public:
    int numPrimeArrangements(int n) {
         bool arr[n  + 1];
        for(int i = 0; i < n + 1 ; i++)
        {
            arr[i] = true;
        }
        for(int i = 2; i*i <= n; i++)
        {
            if(arr[i]){
                for(int j = i*i; j < n + 1; j += i)
                {
                    arr[j] = false;
                }
            }
        }
        int count = 0;
        for(int i = 2; i <= n; i++)
        {
            if(arr[i]){
                // cout << i << endl;
                count++;
            }
        }
        long int mod = powl(10, 9) + 7;
        long int resultPrime = 1, result = 1, resultOdd = 1;
        for(int i = count; i > 0; i--)
        {
            resultPrime *= i;
            resultPrime %= mod;
        }
        resultPrime %= mod;
        resultPrime %= mod;
        for(int i = n - count; i > 0; i--)
        {
            resultOdd *= i;
            resultOdd %= mod;
        }
        resultOdd %= mod;
        resultOdd %= mod;
        result = resultPrime * resultOdd;
        return result % mod;
    }
};
