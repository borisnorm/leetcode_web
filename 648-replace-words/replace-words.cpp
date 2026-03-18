class Solution {
public:
    struct Trie{
      Trie* child[26];
      bool isEnd;
      Trie()
      {
         for (int i = 0; i < 26; i++)
           child[i] = nullptr;
         isEnd = false; 
      }
    };

    Trie* root;
    void insert(string& word)
    {
       Trie* cur = root;
       int n = word.size();
       for(int i = 0; i < n; i++)
       {
          char c = word[i];

          if (!cur->child[c-'a'])
          {
            cur->child[c-'a'] = new Trie();
          }
          cur = cur->child[c-'a'];

          if (i == n - 1)
            cur->isEnd = true;
       }
    }

    string find(string& word)
    {
       Trie* cur = root;
       int n = word.size();
       string res = "";
       for (int i = 0; i < n; i++)
       {
          char c = word[i];
          if (!cur->child[c-'a'])
            return word;
          res += c;
          cur = cur->child[c-'a'];
          if (cur->isEnd)
            break;
       }
      
       return res;
    }
    string replaceWords(vector<string>& dictionary, string sentence) {
         
        root = new Trie();
        for(string& word: dictionary)
          insert(word);

        string res = "";
        stringstream ss(sentence);
        string word = "";
        bool first = true;
        while (ss >> word)
        {
           if (!first)
             res += ' ';
           res += find(word);
           first = false;
        }
        return res;
    }
};