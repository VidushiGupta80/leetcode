//Excel Sheet Column Number -> 08/10/2020 13:23
class Solution {
public:
    int titleToNumber(string s) {
        int title = 0;
        for(int i = 0; i < s.size(); i++)
        {
         title = title * 26 + ((int)s[i] - 64);   
        }
        return title;
    }
};
