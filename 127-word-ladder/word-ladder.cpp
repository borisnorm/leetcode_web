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