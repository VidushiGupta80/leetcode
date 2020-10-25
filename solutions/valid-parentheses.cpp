//Valid Parentheses -> 08/29/2020 20:00
class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for(int i = 0; i < s.size(); i++)
        {
            if((char) s[i] == '(' || (char) s[i] == '[' || (char) s[i] == '{')
                stk.push((char)s[i]);
            else
            {
               if(!stk.empty())
               {
                   if((char) s[i] == ')' && stk.top() == '(')
                        stk.pop();
                    else if((char) s[i] == ']' && stk.top() == '[')
                        stk.pop();
                    else if((char) s[i] == '}' && stk.top() == '{')
                        stk.pop();
                   else return false;
               }
                
                else return false;
            }
        }
        if(stk.empty())
            return true;
        return false;
    }
};
