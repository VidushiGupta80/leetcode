//Partition Labels -> 10/01/2020 18:02
class Solution {
public:
    vector<int> partitionLabels(string S) {
        map<char, int> last;
        for(int i = 0; i < S.size(); i++)
        {
            last[(char)S[i]] = i;
        }
        vector<int> ans;
        for(int i = 0; i < S.size(); )
        {
            int index = last[(char)S[i]];
            int j;
            for(j = i; j <= index; j++)
            {
                index = max(index, last[(char)S[j]]);
                // cout << (char)S[j] << " " << index << endl;
            }
            ans.push_back(j - i);
            i = j;
        }
        return ans;
    }
};
