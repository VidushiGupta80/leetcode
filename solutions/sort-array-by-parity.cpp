//Sort Array By Parity -> 08/21/2020 21:40

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        vector<int> ans(A.size());
        for(int i = 0, j = A.size() - 1, k = 0; k < A.size(); k++)
        {
            if(A[k] % 2 == 0)
            {
                ans[i] = A[k];
                i++;
            }
            else if(A[k] % 2 == 1)
            {
                ans[j] = A[k];
                j--;
            }
        }
        return ans;
    }
};
