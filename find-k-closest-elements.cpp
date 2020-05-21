//Find K Closest Elements -> 05/21/2020 13:24
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> result;
        if(arr.size() == 1 && k == 1)
            return arr;
        else if(arr.size() == 2)
        {
            if(k == 2)
                return arr;
            else
            {
                if(abs(x - arr[0]) <= abs(x - arr[1]))
                    result.push_back(arr[0]);
                else
                    result.push_back(arr[1]);
            }
            return result;
        }
        if(x <= arr[0])
        {
            result.insert(result.begin(), arr.begin(), arr.begin() + k);
        }
        else if(x >= arr[arr.size() - 1])
        {
            result.insert(result.begin(), arr.rbegin(), arr.rbegin() + k);
        }
        
        else
        {
            
            int left = 0, right = arr.size() - 1, mid;
            while(left <= right)
            {
                mid = left + (right - left) / 2;
                if(arr[mid] == x)
                    break;
                else if(arr[mid - 1] < x && arr[mid] > x)  
                {
                    left = mid - 1;
                    right = mid;
                    break;
                } 
                else if(arr[mid + 1] > x && arr[mid] < x)
                {
                    left = mid;
                    right = mid + 1;
                    break;
                }   
                else if(arr[mid] > x && arr[mid + 1] >= x )
                    right = mid - 1;
                else if(arr[mid] < x && arr[mid - 1] <= x )
                    left = mid + 1;
            }
            // cout << arr[mid] << endl;
            if(arr[mid] == x)
            {
                result.push_back(arr[mid]);
                k--;
                left = mid - 1;
                right = mid + 1;
            }
            while(k > 0)
            {
                if(left >= 0 && right <= arr.size() - 1)
                {
                    if(abs(x - arr[left]) <= abs(x - arr[right]))
                    {
                        result.push_back(arr[left]);
                        left--;
                        k--;
                    } 
                    else if(abs(x - arr[left]) > abs(x - arr[right]))
                    {
                        result.push_back(arr[right]);
                        right++;
                        k--;
                    }
                    // else if(abs(x - arr[left]) == abs(x - arr[right]) && k >= 2)
                    // {
                    //     result.push_back(arr[left]);
                    //     left--;
                    //     result.push_back(arr[right]);
                    //     right++;
                    //     k--;
                    //     k--;
                    // }
                    // else if(abs(x - arr[left]) == abs(x - arr[right]) && k == 1)
                    // {
                    //    result.push_back(arr[left]);
                    //     left--;
                    //     k--;
                    // }
                }
                else if(left >= 0 && right > arr.size() - 1)
                {
                    result.push_back(arr[left]);
                    left--;
                    k--;
                }
                else if(left < 0 && right <= arr.size() - 1)
                {
                    result.push_back(arr[right]);
                    right++;
                    k--;
                }                
            }
           
        }
        sort(result.begin(), result.end());
        return result;
    }
};
