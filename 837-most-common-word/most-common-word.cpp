class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
           unordered_set<string> banned_set;
           for (string word: banned)
           {
             for (char& c: word)
               c = tolower(c);

             banned_set.insert(word);
           }

           // 使用& 就可以重新赋值了 进而改变原值了
           for (char& c: paragraph)
           {
               if (isalpha(c))
                 c = tolower(c);
               else
                 c = ' ';
           }

           stringstream ss(paragraph);
          
           unordered_map<string, int> word2cnt;
           string word;
           while (ss >> word)
           {
              if (!banned_set.count(word))
                word2cnt[word]++;
           }

           int maxCnt = 0;
           string maxCntString;
           for (auto it: word2cnt)
           {
              if (it.second > maxCnt)
              {
                maxCntString = it.first;
                maxCnt = it.second;
              }
           }

           return maxCntString;
    }
};