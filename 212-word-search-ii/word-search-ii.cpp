
class TrieNode{
  public: 
         unordered_map<char, TrieNode*> children;
         string word;
         TrieNode(){
            word = "";
         }
};


class Solution {
public:
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        if (board.empty() || words.empty())
          return {};

        TrieNode* root = buildTrie(words);
        int m = board.size();
        int n = board[0].size();
        
        unordered_set<string> found_words;

        for (int i = 0; i < m; i++)
          for (int j = 0; j < n; j++)
            dfs(board, i, j, root, found_words);
      
        vector<string> res(found_words.begin(), found_words.end());

        return res;
    }

    //dfs
    //trie 
    void dfs(vector<vector<char>>& board, int i, int j, TrieNode* node, unordered_set<string>& foundWords)
    {
       int m = board.size();
       int n = board[0].size();

       if (i < 0 || i >=m || j < 0 || j >=n)
         return;
       
       char c = board[i][j];
       if (node->children.find(c) == node->children.end())
         return;

       node = node->children[c];

       if (!node->word.empty())
         foundWords.insert(node->word);

       board[i][j] = '#';
     
       dfs(board, i+1, j, node, foundWords);
       dfs(board, i-1, j, node, foundWords);
       dfs(board, i, j+1, node, foundWords);
       dfs(board, i, j-1, node, foundWords);

       board[i][j] = c;
    }

    TrieNode* buildTrie(vector<string> words)
    {
        TrieNode* root = new TrieNode();    
        for (string word: words)
        {
           TrieNode* node = root;
           for (char c : word)
           {
              if (node->children.find(c) == node->children.end())
              {
                  node->children[c] = new TrieNode();
              }

              node = node->children[c];
           }
           node->word = word;
        }  
        return root;
    }
};