//Minimum Number of Steps to -> 04/29/2020 15:43
class Solution {
public:
    int minSteps(string s, string t) {
        map<char, int> freqMap;
        int count = s.length();
        for(size_t i = 0; i < s.length(); i++)
        {
            if(freqMap.find(s[i]) != freqMap.end())
            {
                map<char, int>::iterator it = freqMap.find(s[i]);
                it->second += 1;
            }
            else
            {
                freqMap.insert(make_pair(s[i], 1)); 
            }
        }
        for(size_t i = 0; i < t.length(); i++)
        {
            map<char, int>::iterator it = freqMap.find(t[i]);
            if(it != freqMap.end() && it->second != 0)
            {
                it->second -= 1;
                count--;
            }
        }
        return count;
    }
};
