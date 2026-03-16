class StreamChecker {
public:
    
    struct TrieNode{
      TrieNode* children[26];
      bool isEnd;
      TrieNode(){
        for (int i = 0; i < 26; i++)
          children[i] = nullptr;
        
        isEnd = false;
      }
    };

    TrieNode* root;
    deque<char> buf;
    int maxLen;

    void insert(const string& word){
      TrieNode* cur = root;
      for (int i = word.size() - 1; i >= 0; i--)
      {
        int idx = word[i] - 'a';

        if (!cur->children[idx])
          cur->children[idx] = new TrieNode();
        
        cur = cur->children[idx];
      }
      cur->isEnd = true;
    }
    StreamChecker(vector<string>& words) {
       root = new TrieNode();
       maxLen = 0;
       for (auto& word: words)
       {
          insert(word);
          maxLen = max(maxLen, (int)word.size());
       }
    }
    
    bool query(char letter) {
        buf.push_front(letter);

        if (buf.size() > maxLen)
          buf.pop_back();
        
        TrieNode* cur = root;
        for (char c: buf)
        {
           int idx = c - 'a';
           if (!cur->children[idx])
             return false; 
           cur = cur->children[idx];

           // 走完这条路径才能 判断是否 end
           if (cur->isEnd)
             return true;
        }
        return false;
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */