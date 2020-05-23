//Climbing Stairs -> 05/23/2020 19:17
class Solution {
private:
//     long long fact(int n){
//         if(n == 1)
//             return n;
        
//         return n * fact(n - 1);
//     }
//     long long Sfact(int n, int x)
//     {
//         if(n == x)
//             return 1;
        
//         return n * Sfact(n - 1, x);
//     }
public:
    int climbStairs(int n) {
        // int count;
        // if(n % 2 == 0)
        //     count = 2;
        // else
        //     count = 1;
        // int temp = n - 1;
        // int twos = 1;
        // int ones = temp - twos;
        // while(temp > n / 2)
        // {
        //     count += Sfact(temp, ones) / fact(twos) ;
        //     ones -= 2;
        //     twos++;
        //     temp--;
        // }
        // return count;
        
        vector <int> dp;
        dp.push_back(0);
        dp.push_back(1);
        dp.push_back(2);

            for(int i=3;i<=n;i++)
            dp.push_back(dp[i-1]+dp[i-2]);
            return dp[n];
        }   
    
};
