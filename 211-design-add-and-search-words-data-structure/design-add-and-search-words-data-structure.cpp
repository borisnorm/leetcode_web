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
    
    /*
    bool search(string word) {
        vector<TrieNode*> frontier = {root};
        for (char c : word)
        {
            vector<TrieNode*> nextFrontier;

            if (c == '.')
            {
               for (TrieNode* node : frontier)
               {
                  if (!node)
                    continue;

                  for (TrieNode* child : node->children)
                    if (child)
                      nextFrontier.push_back(child);
               }

            }
            else
            {
               int idx = c -'a';
               for(TrieNode* node : frontier)
               {
                 if (node && node->children[idx])
                   nextFrontier.push_back(node->children[idx]);
               }
            }

            if (nextFrontier.empty())
              return false;
            
            frontier.swap(nextFrontier);
        }

        for (TrieNode* node: frontier)
          if (node && node->isEnd)
            return true;

        return false;
    }
*/



       bool search(string word) {
        return searchWord(word, root, 0);
    }
    
    bool searchWord(string &word, TrieNode *p, int i) {
        if (i == word.size()) 
          return p->isEnd;

        if (word[i] == '.') {
            for (auto &a : p->children) {
                if (a && searchWord(word, a, i + 1)) return true;
            }
            return false;
        } else {
            return p->children[word[i] - 'a'] && searchWord(word, p->children[word[i] - 'a'], i + 1);
        }
    }


};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */