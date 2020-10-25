//Decrypt String from Alphabet to Integer Mapping</a -> 06/20/2020 10:41
class Solution {
public:
    string freqAlphabets(string s) {
        string ans = "";
        int i, j, k;
        for(i = 0, j = i + 1, k = i + 2; k < s.size(); )
        {
            if(s[k] == '#')
            {
                int temp = 10 * (s[i] - 48) + (s[j] - 48);
                char c = 96 + temp;
                ans += c;
                i = k + 1;
                j = i+ 1;
                k = j + 1;
            }
            else
            {
                int temp = s[i] - 48;
                char c = 96 + temp;
                ans += c;
                i++;
                j = i+ 1;
                k = j + 1;
            }
        }
        if( i < s.size())
        {
            for(; i < s.size(); i++)
            {
               int temp = s[i] - 48;
                char c = 96 + temp;
                ans += c; 
            }
        }
        return ans;
        
        // queue<char> qp;
        // int count = 0;
        // qp.push((char)s[0]);
        // count = 1;
        // for(int i =1; i < s.len(); i++)
        // {
        //     if(count == 2 && s[i] == '#')
        //     {
        //         qp.push((char)s[i]);
        //         int temp = 0;
        //         for(int j = 0; j < 2; j++)
        //         {
        //             temp = temp * 10 + (qp.front() - 48);
        //             qp.pop();
        //         }
        //         char c = 96 + temp;
        //         ans += c;
        //         qp.pop();
        //         count = 0;
        //     }
        //     else if(count == 2 && s[i] != '#')
        //     {
        //        qp.push((char)s[i]);
        //         int temp = 0;
        //         for(int j = 0; j < 2; j++)
        //         {
        //             temp = qp.front() - 48;
        //             char c = 96 + temp;
        //             ans += c;
        //             qp.pop();
        //         }
        //         count = 1;
        //     }
        //     else
        //     {
        //         qp.push((char)s[i]);
        //         count++;
        //     }
        // }
        // int temp = 0;
        // while(!qp.empty())
        // {
        //     temp = qp.front() - 48;
        //     char c = 96 + temp;
        //     ans += c;
        //     qp.pop();
        // }
    }
};
