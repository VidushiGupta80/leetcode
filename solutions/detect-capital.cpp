//Detect Capital -> 08/03/2020 14:08
class Solution {
private:
    bool allCaps(string& word)
    {
        bool allCap = true;
        for(int i = 1; i < word.size(); i++)
        {
           if((char)word[i] >= 'A' && (char)word[i] <= 'Z') 
               allCap = allCap && true;
            else
                allCap = allCap && false;
        }
        return allCap;
    }
    bool allSmall(string& word)
    {
        bool small = true;
        for(int i = 1; i < word.size(); i++)
        {
            if((char)word[i] >= 'a' && (char)word[i] <= 'z') 
               small = small && true;
            else
                small = small && false;
        }
        return small;
    }
    
public:
    bool detectCapitalUse(string word) {
        if(word.size() == 1)
            return true;
        if(allCaps(word))
            return((char)word[0] >= 'A' && (char)word[0] <= 'Z');
        else if(allSmall(word))
            return (((char)word[0] >= 'A' && (char)word[0] <= 'Z') || 
                    ((char)word[0] >= 'a' && (char)word[0] <= 'z'));
        return false;
    }
};
