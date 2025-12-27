class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> alpha2idx;

        for (int i = 0; i < order.size(); i++)
          alpha2idx[order[i]] = i;
        
        int n = words.size();
        if (n <= 1)
          return true;
        
        for (int i = 1; i < n; i++)
        {
            string word1 = words[i-1];
            string word2 = words[i];
           
            int j = 0;

            while (j < word1.size() && j < word2.size())
            {
               if (word1[j] != word2[j])
                 break;
            
               j++;
            }

            // word1 没有结束, 但 word2 结束了
            if (j < word1.size() && j == word2.size())
              return false;
            // word1 结束了,  但 word2 没有结束
            else if (j == word1.size() && j < word2.size())
              continue;
            // word1, word2 有 相同的大小, 没有找到合适的 j, k
            else if (j == word1.size() && j == word2.size())
              continue;
            
            if (!(alpha2idx[word2[j]] >= alpha2idx[word1[j]]))
              return false;
        }

        return true;
    }
};