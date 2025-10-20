class WordDictionary {
public:
    struct TrieNode{
        vector<TrieNode*> children;
        bool isEnd;
        TrieNode(): children(26) {
            this->isEnd = false;
            for (int i = 0; i < 26; i++)
              children[i] = nullptr;
        }
    };

    TrieNode* root;

    WordDictionary() {
        this->root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* node = root;
        for (char c: word)
        {
           int idx = c - 'a';
           if (node->children[idx] == nullptr)
             node->children[idx] = new TrieNode();
            
            node = node->children[idx];
        }

        node->isEnd = true;
    }
    
    bool search(string word) 
    {
      return searchWord(word, root, 0);
    }
    
    bool searchWord(string &word, TrieNode *p, int i) {
        if (!p)
          return false;
        if (i == word.size()) 
          return p->isEnd;

        char c = word[i];
        if (c == '.') 
        {
          for (auto &child : p->children) 
          {
            if (child && searchWord(word, child, i + 1)) 
              return true;
          }
          return false;
        } 
        else 
        {
            int idx = c - 'a';
            TrieNode* child = p->children[idx];
            if (child)
              return searchWord(word, child, i + 1);
            return false;
        }
    }


};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */