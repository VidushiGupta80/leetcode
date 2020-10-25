//Minimum Number of Frogs Croaking -> 10/23/2020 19:58
class Solution {
int index(char ch)
    {
        string pattern="croak";
        for(int i=0;i<5;i++)
        {
            if(ch==pattern[i])
                return i;
        }
        return -1;
    }
    bool check(vector<int>&c)
    {
        for(int i=0;i<4;i++)
        {
            if(c[i]<c[i+1])
                return false;
        }
        return true;
    }
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        if(croakOfFrogs.size() % 5 != 0)
            return -1;
        vector<int> freq(5, 0);
        int countC = 0;
        int countFree = 0;
        for(int i = 0; i < croakOfFrogs.size(); i++)
        {
            if(croakOfFrogs[i] == 'c')
            {
                if(countFree > 0)
                    countFree--;
                else 
                    countC++;
            }
            else if(croakOfFrogs[i] == 'k')
                countFree++;
            freq[index(croakOfFrogs[i])]++;
            if(check(freq))
                continue;
            else
                return -1;
        }
        for(int i=0;i<4;i++)
        {
            if(freq[i]!=freq[i+1])
                return -1;
        }
        return countC;
    }
};
