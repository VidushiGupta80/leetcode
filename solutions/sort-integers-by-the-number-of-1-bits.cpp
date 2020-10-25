//Sort Integers by The Number of 1 -> 05/23/2020 13:51
class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
//         map<int, vector<int> > countMap;
//         vector<int> result;
//         int count = 0;
        
//         for(size_t i = 0; i < arr.size(); i++)
//         {
//             if((arr[i] & (arr[i] - 1)) == 0)
//                 countMap[1].push_back(arr[i]);
//             else if(arr[i] == 0)
//                 countMap[0].push_back(arr[i]);
//             else if(arr[i] & (arr[i] - 1) != 0)
//             {
//                 int x = arr[i];
//                 int nearestPow = log(x) / log(2);
//                 while(true)
//                 {
//                     if(x == 0)
//                         break;
//                     else if(x == 1)
//                     {
//                         count++;
//                         break;
//                     }
//                     else
//                     {
//                         x = x - powl(2, nearestPow);
//                         nearestPow = log(x) / log(2);
//                         count++;
//                     }
//                 }
//                 countMap[count].push_back(arr[i]);
//             }
//         }
        
//          map<int, vector<int> > :: iterator it = countMap.begin();
//         while(it != countMap.end())
//         {
//             sort(it->second.begin(), it->second.end());
//             result.insert(result.end(), it->second.begin(), it->second.end());
//         }
//         return result;
        
        
        
        map<int, vector<int>> hash;
        vector<int> ans;
        
        for(auto num : arr) hash[bitNum(num)].push_back(num);
        
        for(auto it  = hash.begin(); it != hash.end(); ++it){
            vector<int> temp(it->second);
            if(temp.size()) sort(temp.begin(), temp.end());
            ans.insert(ans.end(), temp.begin(), temp.end());
        }
        
        return ans;
    }
    
    int bitNum(int n){
        int cnt = 0;
        
        while(n != 0){
            if(n % 2 == 1) cnt++;
            n /= 2;
        }
        
        return cnt;
    }
    
};
