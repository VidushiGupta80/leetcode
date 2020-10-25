//Longest Palindromic Substring -> 08/12/2020 21:36
class Solution {
    
public:
    string longestPalindrome(string s) {
        
        if(s.size() == 0)
            return "";
        if(s.size() == 1)
            return s;
        int n = s.size();
        vector<vector<bool> > cache(n + 1, vector<bool> (n + 1, false));
        for(int i = n - 1; i >= 0; i--){
            for(int j = 0; j < n; j++){
                if(j < i)
                    continue;
                else if(i == j)
                    cache[i][j] = true;
                else{
                    if(abs(j - i) == 1 && s[i] == s[j]){
                        cache[i][j] = true;
                    }
                    else if(s[i] == s[j]){
                        cache[i][j] = cache[i + 1][j - 1];       
                    }
                }
            }
        }
        int start = 0,dist = 0;
        for(int u = 0; u < n + 1; u++){
            for(int v = 0; v < n + 1; v++){
                if(cache[u][v]){
                    if(v - u > dist){
                        start = u;
                        dist = v - u;
                    }
                }
            }
        }
        return s.substr(start, dist + 1);
        }
        
    
};
