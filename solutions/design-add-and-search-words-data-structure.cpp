//Design Add and Search Words Data Structure</a -> 08/07/2020 23:01
class WordDictionary {
public:
    
    WordDictionary *children[26];
    bool end;
    /** Initialize your data structure here. */
    WordDictionary() {
        // WordDictionary *node = new WordDictionary();
        
        this->end = false;
        for(int i = 0; i < 26; i++)
            this->children[i] = NULL;
        
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        WordDictionary *crawl = this;
        for(int i = 0; i < word.size(); i++)
        {
            int index = word[i] - 'a';
            if(!crawl->children[index])
                crawl->children[index] = new WordDictionary();
            crawl = crawl->children[index];
        }
        crawl->end = true;
    }
    bool searching(WordDictionary *crawl, string word, int index)
    {
        if(crawl == NULL)
            return false;
        if(index == word.size() - 1)
        {
            if(word[index] != '.')
                return(crawl->children[word[index] - 'a'] && crawl->children[word[index] - 'a']->end);
            else
            {
                for(int i = 0; i < 26; i++)
                {
                    if(crawl->children[i] && crawl->children[i]->end)
                        return true;
                    
                }
                return false;
            }
        }
        
        bool ans = false;
        if(word[index] != '.')
        {
            ans = ans || searching(crawl->children[word[index]- 'a'], word, index + 1);
        }
        else
        {
            for(int i = 0; i < 26; i++)
            {
                ans = ans || searching(crawl->children[i], word, index + 1);
            }
        }
        return ans;
        
    }
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        WordDictionary *crawl = this;
        bool ans = searching(crawl, word, 0);
        return ans;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
