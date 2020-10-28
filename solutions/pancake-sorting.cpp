//Pancake Sorting -> 08/29/2020 13:01

class Solution {
public:
    vector<int> pancakeSort(vector<int>& A) {
        vector<int> ans;
        vector<int> sorted (A);
        sort(sorted.begin(), sorted.end());
        while(true)
        {
            if(A == sorted)
                break;
            else if(*min_element(A.begin(), A.end()) == A[0])
            {
                for(int i = 1; i < A.size(); i++)
                {
                    if(A[i - 1] > A[i])
                    {
                        ans.push_back(i );
                        reverse(A.begin(), A.begin() + i);
                        break;
                    }
                }
            }
            else 
            {
                for(int i = A.size() - 1; i > 0; i--)
                {
                    if(A[i] < A[0])
                    {
                        ans.push_back(i + 1);
                        reverse(A.begin(), A.begin() + i + 1);
                        break;
                    }
                }
            }
        }
        return ans;
    }
};