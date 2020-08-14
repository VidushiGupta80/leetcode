//Longest Palindrome -> 08/14/2020 12:59
class Solution {
public:
    int longestPalindrome(string s) {
        map<char, int> freq;
        for(int i = 0; i < s.size(); i++)
        {
            freq[(char)s[i]]++;
        }
        int total = 0;
        int odd = 0;
        map<char, int> :: iterator it = freq.begin();
        for(; it != freq.end(); it++)
        {
            if(it->second % 2 == 0)
                total += it->second;
            else
            {
                if(it->second >= odd)
                {
                    if(odd > 0)
                        total += odd - 1;
                    odd = it->second;
                }
                else
                    total += it->second - 1;
            }
        }
        // cout << odd << " " << total << endl;
        // odd = odd/2 + 1;
        // total /= 2;
        total += odd;
        return total;
    }
};
