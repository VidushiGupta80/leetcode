//Decode String -> 08/27/2020 11:18
class Solution {
string helper(int num, int st, int e, string& s)
{
    string ans;
    string temp;
    string c;
    for(int i = st; i <= e; i++)
    {
        if(((char)s[i] >= 'a' && (char)s[i] <= 'z') || ((char)s[i] >= 'A' && (char)s[i] <= 'Z'))
                temp += s[i];
        else if((char)s[i] == '[')
        {
            int count = 1;
            int j = i;
            
            int num = stoi(c);
            c = "";
            while(count > 0)
            {
                i++;
                if((char)s[i] == '[')
                    count++;
                else if((char)s[i] == ']')
                    count--;

            }
            temp += helper(num, j + 1, i - 1, s);
        }
        else
           c += (char)s[i];
    }
    for(int i = 0; i < num; i++)
        ans += temp;
    return ans;
}
public:
    string decodeString(string s) {
        string ans;
        string c;
        for(int i = 0; i < s.size(); i++)
        {
            
            if(((char)s[i] >= 'a' && (char)s[i] <= 'z') || ((char)s[i] >= 'A' && (char)s[i] <= 'Z'))
                ans += s[i];
            else if((char)s[i] == '[')
            {
                int count = 1;
                int j = i;
                int num = stoi(c);
                c = "";
                while(count > 0)
                {
                    i++;
                    if((char)s[i] == '[')
                        count++;
                    else if((char)s[i] == ']')
                        count--;
                    
                }
                ans += helper(num, j + 1, i - 1, s);
            }
            else
                c += (char)s[i];
        }
        return ans;
    }
};
