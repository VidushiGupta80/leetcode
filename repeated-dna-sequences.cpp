//Repeated DNA Sequences -> 08/12/2020 17:22
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        map<string, int> freq;
        vector<string> ans;
        int n = s.size();
        ;
        if( n <= 10)
        {
            return ans;
        }
        for(int i = 0; i <= n - 10; i++)
        {
            freq[s.substr(i, 10)]++;
        }
        map<string, int> :: iterator it = freq.begin();
        for(; it != freq.end(); it++)
        {
            if(it->second > 1)
                ans.push_back(it->first);
        }
        return ans;
    }
};
