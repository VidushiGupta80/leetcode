//Validate Stack Sequences -> 08/22/2020 11:59
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> stk;
        int popp = 0;
        for(int pushh = 0; pushh < pushed.size(); pushh++)
        {
            stk.push(pushed[pushh]);
            while(!stk.empty() && stk.top() == popped[popp])
            {
                stk.pop();
                popp++;
            }
        }
        return popp == popped.size();
    }
};
