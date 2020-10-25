//Find All Anagrams in a String -> 08/29/2020 18:40
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        vector<int> pMap(26);
        vector<int> sMap(26);
        int n = p.size();
        if(s.size() < n) return res;
        for(int i = 0; i < n; i++){
            pMap[p[i] - 'a']++;
            sMap[s[i] - 'a']++;
        }
        
        if(sMap == pMap) res.push_back(0);
        for(int i = 1; i <= s.size() - n; i++){
            sMap[s[i-1] - 'a']--;
            sMap[s[i + n - 1] - 'a']++;
            if(sMap == pMap){
                res.push_back(i);
            }
        }
        return res;
    }
};
