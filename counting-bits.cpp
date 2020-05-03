//Counting Bits -> 05/03/2020 12:54
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> output;
        output.push_back(0);
        for(int i = 1; i <= num; i++)
        {
            if(i & (i - 1) == 0)
            {
                output.push_back(1);
            }
            else
            {
                int n = log2(i);
                int nearestPower = pow(2, n);
                int countOnes = 1;
                int temp = i;
                temp -= nearestPower;
                countOnes += output[temp];
                output.push_back(countOnes);
                
            }
        }
        return output;
    }
};
