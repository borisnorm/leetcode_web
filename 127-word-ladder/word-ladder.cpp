class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (!dict.count(endWord))
          return 0;
        
        unordered_set<string> front = {beginWord};
        unordered_set<string> back = {endWord};

        if (dict.count(beginWord))
          dict.erase(beginWord);
        
        dict.erase(endWord);

        int step = 1;

        while(!front.empty() && !back.empty())
        {
          // 确保 front 里面 单词是少数
          if (front.size() > back.size())
            swap(front, back);
          
          unordered_set<string> nxt;

          for(string word : front)
          {
             for (int i = 0; i < word.size(); i++)
             {
                int old = word[i];
                for (char c = 'a'; c <= 'z'; c++)
                {
                   if (c == old)
                     continue;
                   
                   word[i] = c;

                   if (back.count(word))
                      return step + 1;
                    
                   if (dict.count(word))
                   {
                      nxt.insert(word);
                      dict.erase(word);
                   }
                }

                word[i] = old;
             }
          }
          front = nxt;
          step++;
        }

        return 0;
    }
};

/*
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());

        if (!dict.count(endWord))
          return 0;
        
        queue<pair<string, int>> q;
        q.push({beginWord, 1});

        while(!q.empty())
        {
           auto [word, step] = q.front();
           q.pop();

           int n = word.size();

           for (int i = 0; i < n; i++)
           {
              char orig = word[i];

              for (char c = 'a'; c <= 'z'; c++)
              {
                  if (c == orig)
                    continue;
                  
                  word[i] = c;

                  if (word == endWord)
                    return step + 1;

                  if (dict.count(word))
                  {
                     dict.erase(word);
                     q.push({word, step + 1});
                  }
              }

              word[i] = orig;
           }
        }

        return 0;
    }
};
*/

/*
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if (wordList.empty())
          return 0;

        unordered_set<string> wordSet(wordList.begin(), wordList.end());

        if (wordSet.find(endWord) == wordSet.end())
          return 0;

        queue<string> wordq;
        wordq.push(beginWord);
        
        int level = 1;
        while(!wordq.empty())
        {
            int q_size = wordq.size();
            for (int i = 0; i < q_size; i++)
            {
               string word = wordq.front();
               wordq.pop();

               if (word == endWord)
                 return level;

               for (int j= 0; j < word.size(); j++)
               {
                  char oldchar = word[j];
                  
                  // change
                  for (char c = 'a'; c <= 'z'; c++)
                  {
                      word[j] = c;
                      if (wordSet.find(word) != wordSet.end())
                      {
                         wordq.push(word);
                         wordSet.erase(word);
                      }
                  }

                  word[j] = oldchar;
               } 
            }
            level++;
        }

        return 0;
    }
};
*/

/*
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int L = beginWord.size();
        bool found = false;

        for (auto &w: wordList)
        {
           if (w == endWord)
           {
              found = true;
              break;
           }
        }

        if (!found)
          return 0;

        bool hasBegin = false;
        for (auto &w: wordList)
        {
            if (w == beginWord)
            {
                hasBegin = true;
                break;
            }
        }

        if (!hasBegin)
          wordList.push_back(beginWord);

        //1. patter-> words
        unordered_map<string, vector<string>> patternMap;
        
        for (const string &word: wordList)
        {

            for (int i = 0; i < L; i++)
            {
                string pattern = word;
                pattern[i] = '*';
                patternMap[pattern].push_back(word);
            }
        }

        queue<pair<string, int>> q;
        q.push({beginWord, 1});

        unordered_set<string> visited;
        visited.insert(beginWord);

        while (!q.empty())
        {
            auto [word, step] = q.front();
            q.pop();

            if (word == endWord)
              return step;

            for (int i = 0; i < L; i++)
            {
               string pattern = word;
               pattern[i] = '*';

               auto it = patternMap.find(pattern);
               if (it == patternMap.end())
                 continue;

               for (const string &next: it->second)
               {
                  if (!visited.count(next))
                  {
                     visited.insert(next);
                     q.push({next, step + 1});
                  }
               }

               it->second.clear();
            }
        }

        return 0;
    }
};

*/