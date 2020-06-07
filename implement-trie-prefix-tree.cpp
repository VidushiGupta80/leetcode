//Implement Trie (Prefix Tree) -> 06/07/2020 22:09
class Trie {
public:
    
    bool end;
    Trie* children[26];
    /** Initialize your data structure here. */
    Trie() {
        
        // Trie* root = new Trie;
        this->end = false;
        for(int i = 0; i < 26; i++)
            this->children[i] = NULL;
        // return root;
        
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie* crawl = this;
        for(int i = 0; i < word.size(); i++)
        {
            char c = (char)word[i];
            if(!crawl->children[(int)c - 97])
            {
                crawl->children[(int)c - 97] = new Trie();
            }
            crawl = crawl->children[(int)c - 97];
        }
        crawl->end = true;
        // delete crawl;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie* crawl = this;
        for(int i = 0; i < word.size(); i++)
        {
            char c = (char)word[i];
            if(!crawl->children[(int)c - 97])
                return false;
            crawl = crawl->children[(int)c - 97];
        }
        if(!crawl->end)
            return false;
        return true;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie* crawl = this;
        for(int i = 0; i < prefix.size(); i++)
        {
            char c = (char)prefix[i];
            if(!crawl->children[(int)c - 97])
                return false;
            crawl = crawl->children[(int)c - 97];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
