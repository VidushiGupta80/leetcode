//Goat Latin -> 08/20/2020 11:21

bool vowels(char c)
{
    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' 
       || c == 'E' || c == 'I' || c == 'O' || c == 'U' )
        return true;
    return false;
}
class Solution {
public:
    string toGoatLatin(string S) {
        stringstream ss(S);
        istream_iterator<string> begin(ss);
        istream_iterator<string> end;
        vector<string> arr(begin, end);
        string ans;
        for(int i = 0; i < arr.size(); i++)
        {
            if(i > 0)
                ans += " ";
            if(!vowels((char)arr[i][0]))
            {
                string temp = "";
              for(int k = 1; k < arr[i].size(); k++)
              {
                 // cout << arr[i][k] << endl;
                  temp += arr[i][k]; 
              }
                temp += (char)arr[i][0];
                arr[i] = temp;
            }
            arr[i] += "ma";
            for(int j = 0; j <= i; j++)
            {
                arr[i] += 'a';
            }
            ans += arr[i];
        }
        return ans;
        
    }
};