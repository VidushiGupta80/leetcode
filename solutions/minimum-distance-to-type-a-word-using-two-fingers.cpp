class Solution {
unordered_map<string, int> dp;
int calcDist(int index, pair<int, int> f1, pair<int, int> f2, string& word, vector<pair<int, int> >& keypad)
{
    if(index >= word.size())
        return 0;
    int f1r = f1.first;
    int f1c = f1.second;
    int f2r = f2.first;
    int f2c = f2.second;
    string temp = "";
    temp += to_string(index);
    temp += to_string(f1r);
    temp += to_string(f1c);
    temp += to_string(f2r);
    temp += to_string(f2c);
    if(dp.find(temp)!= dp.end())
        return dp[temp];
    int r = keypad[(char)word[index] - 'A'].first;
    int c = keypad[(char)word[index] - 'A'].second;
    int x = 0, y = 0;
    if(f1r != -1 && f1c != -1)
        x = abs(f1r - r) + abs(f1c - c);
    if(f2r != -1 && f2c != -1)
        y = abs(f2r - r) + abs(f2c - c);
    f1 = {r, c};   
    int ans = x + calcDist(index + 1, f1, f2, word, keypad);
    f1 = {f1r, f1c};
    f2 = {r, c};
    ans = min(ans, y + calcDist(index + 1, f1, f2, word, keypad));
    f2 = {f2r, f2c};
    return dp[temp] = ans;
}
public:
    int minimumDistance(string word) {
        vector<pair<int, int> > keypad(26);
        for(int i = 0; i < 26; i++)
        {
            int row = 0;
            int column = 0;
            if(i >= 0 && i <= 5)
                row = 0;
            else if(i >= 6 && i <= 11)
                row = 1;
            else if(i >= 12 && i <= 17)
                row = 2;
            else if(i >= 18 && i <= 23)
                row = 3;
            else if(i >= 24 && i <= 25)
                row = 4;
            column = i % 6;
            keypad[i] = {row, column};
        }
        pair<int, int> f1 = {-1, -1};
        pair<int, int> f2 = {-1, -1};
        
        // for(int i = 0; i < word.size(); i++)
        // {
        //     for(int j = 0; j < 26; j++)
        //     {
        //         for(int k = 0; k < 26; k++)
        //             dp[i][j][k] = -1;
        //     }
        // }
        return calcDist(0, f1, f2, word, keypad);
    }
};
