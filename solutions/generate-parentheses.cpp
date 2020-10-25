//Generate Parentheses -> 06/20/2020 12:17
class Solution {
private:
    void helper(vector<string>& ans, string temp, int curr, int total, int n)
    {
        // cout << temp << endl;
        if(total == n && curr == 1)
        {
            temp += ')';
            ans.push_back(temp);
            return;
        }
        
        else if(total == n && curr <= n)
        {
            temp += ')';
            helper(ans, temp, curr - 1, total, n);
        }
        else if(total < n && curr < n && curr > 0)
        {
            temp += '(';
            helper(ans, temp, curr + 1, total + 1, n);
            temp.pop_back();
            temp += ')';
            helper(ans, temp, curr - 1, total, n);
        }
        else if(total < n && curr == 0)
        {
            temp += '(';
            helper(ans, temp, curr + 1, total + 1, n);
        }
        
        return;
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string temp = "(";
        helper(ans, temp, 1, 1, n);
        return ans;
    }
};
