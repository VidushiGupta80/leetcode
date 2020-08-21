//Baseball Game -> 08/21/2020 20:21
class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> stk;
        int sum = 0;
        for(int i = 0; i < ops.size(); i++)
        {
            if((char)ops[i][0] == 'C')
            {
                int last = stk.top();
                sum -= last;
                stk.pop();
            }
            else if((char)ops[i][0] == '+')
            {
                int temp = 0;
                int last = stk.top();
                temp += last;
                stk.pop();
                int prev = stk.top();
                temp += prev;
                sum += temp;
                stk.push(last);
                stk.push(temp);
            }
            else if((char)ops[i][0] == 'D')
            {
                int temp = 2 * stk.top();
                stk.push(temp);
                sum += temp;
            }
            else
            {
               
                int temp = stoi(ops[i]);
                // if(temp < 0)
                //     temp++;
                // cout << temp << endl;
                stk.push(temp);
                sum += stk.top();                    
            }
        }
        return sum;
    }
};
