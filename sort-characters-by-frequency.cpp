//Sort Characters By Frequency -> 07/23/2020 11:44
class Solution {
   
public:
    string frequencySort(string s) {
        string result;
        if(s.size() == 0)
            return result;
        sort(s.begin(), s.end());
        multimap <int, char> freqMap;
        char c, d;
        int count = 1;
        for(size_t i = 0; i < s.size() - 1; i++)
        {
            c = s[i];
            d = s[i + 1];
            if(c == d)
                count++;
            else
            {
                freqMap.insert(make_pair(count, c));
                count = 1;
            }
        }
        // if(s[s.size() - 1] != s[s.size() - 2])
            freqMap.insert(make_pair(count, s[s.size() - 1]));
        
        // string result;
        multimap <int, char> :: reverse_iterator it = freqMap.rbegin();
        while(it != freqMap.rend())
        {
            for(int i = 0; i < it->first; i++)
            {
                result += it->second;
            }
            it++;
        }
        
        return result;
    }
        
        
       
   
};
