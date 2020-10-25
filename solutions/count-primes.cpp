//Count Primes -> 04/17/2020 14:08
class Solution {
public:
    int countPrimes(int n) {
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
        for(int i = 2; i < n; i++)
        {
            if(arr[i]){
                // cout << i << endl;
                count++;
            }
        }
        return count; 
//         int prefix[n + 1];
//         prefix[0] = prefix[1] = 0; 
//         for (int p = 2; p <= n; p++) { 
//             prefix[p] = prefix[p - 1]; 
//             if (arr[p] != 0) 
//                 prefix[p]++; 
//         } 
       
//         return prefix[n];
    }
};
