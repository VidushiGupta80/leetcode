//Iterator for Combination -> 08/13/2020 13:08

class CombinationIterator {
    vector<string> combinations;
    int i = 0;
    
    void rec(int index, string& temp, string& characters, int combi)
    {
        if(characters.size() == combi)
        {
            combinations.push_back(characters);
            return;
        }
        if(temp.size() == combi)
        {
            combinations.push_back(temp);
            return;
        }
        for(int i = index; i < characters.size(); i++)
        {
            temp += (char)characters[i];
            rec(i + 1, temp, characters, combi);
            temp.pop_back();
        }
        return;
    }
    
public:
    CombinationIterator(string characters, int combinationLength) {
        string temp;
        rec(0, temp, characters, combinationLength);
    }
    
    string next() {
        return combinations[i++];
    }
    
    bool hasNext() {
        return i < combinations.size();
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */