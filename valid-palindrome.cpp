//Valid Palindrome -> 08/03/2020 18:21
class Solution {
public:
    bool isPalindrome(string s) {
        transform(s.begin(), s.end(), s.begin(), ::tolower); 
        for(int i = 0, j = s.size() - 1; i <= j; )
        {
            if(((char)s[i] >= 'a' && (char)s[i] <= 'z') || ((char)s[i] >= 'A' && (char)s[i] <= 'Z')
               || ((char)s[i] >= '0' && (char)s[i] <= '9') )
            {
                if(((char)s[j] >= 'a' && (char)s[j] <= 'z')|| ((char)s[j] >= 'A' && (char)s[j] <= 'Z')
                    || ((char)s[j] >= '0' && (char)s[j] <= '9'))
                {
                    if((char)s[i] != (char)s[j])
                        return false;
                    else
                    {
                        i++;
                        j--;
                    }
                }
                else
                    j--;
                
            }
            else
                i++;
        }
        return true;
    }
};
