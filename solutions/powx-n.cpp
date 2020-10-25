//Pow(x, n) -> 07/23/2020 13:53
class Solution {
public:
    double myPow(double x, int n) {
        // if(n == 0 || x == 1)
        //     return 1;
        // if(x == 0)
        //     return 0;
        // double result;
        // if(n < 0)
        //      result = myPower(1.00000/ x, abs(n));
        // else
        //      result = myPower(x, abs(n));
        // return result;
        
         if(n==0)
            return 1;
        else if(n==1)
            return x;
        else if(n==-1)
            return 1.00/x;
        else
        {
            if(n%2==0)
            {
                double ans=myPow(x,n/2);
                return ans*ans;
            }
            else
            {
                double ans=myPow(x,(n-1)/2);
                return ans*ans*x;
            }
    }
    
// private:
//     double myPower(double x, int n)
//     {
//         if(n == 1)
//             return x;
//         double result = myPower(x, n/2);
//         if(n % 2 != 0)
//         {
//             return x * result * result;
//         }

        
//         return result * result;

//     }
    }
        
};

