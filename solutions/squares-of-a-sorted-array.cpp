//Squares of a Sorted Array -> 05/22/2020 17:40
class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        vector<int> result;
//         if(A.size() == 1)
//         {
//             result.push_back(A[0] * A[0]);
//             return result;
//         }
//         else if(A.size() == 2)
//         {
//             if(A[0] < 0)
//             {
//                 result.push_back(A[1] * A[1]);
//                 result.push_back(A[0] * A[0]);
//                 return result;
//             }
//             else
//             {
//                 result.push_back(A[0] * A[0]);
//                 result.push_back(A[1] * A[1]);
//                 return result;
//             }
//         }
//         int left = 0, right = A.size() - 1, mid;
//         // find first positive number
//         if(A[0] >= 0)
//         {
//             while(left < A.size())
//             {
//                 result.push_back(A[left] * A[left]);
//                 left++;
//             }
//             return result;
//         }
//         else
//         {
//              while(left <= right)
//              {
//                  mid = left + (right - left) / 2;
//                  if((A[mid - 1] < 0 && A[mid] >= 0) || mid == 0)
//                      break;
//                  else if(A[mid] < 0)
//                      left = mid + 1;
//                  else if(A[mid] >= 0 && A[mid - 1] >= 0)
//                  {
//                      right = mid - 1;
//                  }
//              }
//         }
        
//         right = mid;
//         left = mid - 1;
//         // while(right < A.size())
//         // {
//         //     result.push_back(A[right] * A[right]);
//         //     right++;
//         // }
//         // while(left >= 0)
//         // {
//         //     result.push_back(A[left] * A[left]);
//         //     left--;
//         // }
//         // return result;
        
//         while(left >= 0 && right < A.size())
//         {
//             if(A[right] > abs(A[left]))
//             {
//                result.push_back(A[left] * A[left]);
//                 left--;
//             }
//             else
//             {
//                 result.push_back(A[right] * A[right]);
//                 right++;
//             }
//         }
//         if(left < 0)
//         {
//             while(right < A.size())
//             {
//                 result.push_back(A[right] * A[right]);
//                 right++;
//             }
//         }
//         else if(right == A.size())
//         {
//             while(left >= 0)
//             {
//                 result.push_back(A[left] * A[left]);
//                 left--;
//             }
//         }
        
        for(size_t i = 0; i < A.size(); i++)
        {
            result.push_back(A[i] * A[i]);
        }
        sort(result.begin(), result.end());
        return result; 
    }
};
