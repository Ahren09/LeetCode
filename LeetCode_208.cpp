class Trie {
public:
    /** Initialize your data structure here. */
    Trie() : root(new TrieNode()){}
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* p=root;
        for(char c:word)
        {
            if(!p->children[c-'a'])
                p->children[c-'a']=new TrieNode();
            p=p->children[c-'a'];
        }
        p->isWord=true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(const string& word) const {
        const TrieNode* p=root->find(word,root);
        return p && p->isWord;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(const string& prefix) const{
        return root->find(prefix,root) != nullptr;
    }
    
    
private:
    struct TrieNode
    {
        TrieNode():isWord(false), children(26,nullptr){}
        
        ~TrieNode()
        {
            for(int i=0;i<26;i++)
            {
                if(children[i])
                    delete children[i];
            }
            
        }
        
        const TrieNode* find(const string& word, const TrieNode* root) const
        {
            const TrieNode* p=root;
            for(const char c:word)
            {
                p=p->children[c-'a'];
                if(p==nullptr)
                    break;
            }
            return p;
        }
        
        bool isWord;
        vector<TrieNode*> children;
    };
    TrieNode* root;
    
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */
