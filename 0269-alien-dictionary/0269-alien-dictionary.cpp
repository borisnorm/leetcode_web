class Solution {
public:
    string alienOrder(vector<string>& words) {
        unordered_map<char, unordered_set<char>> graph;
        unordered_map<char, int> indegree;

        // init indegree
        for (string word: words)
        {
           for (char c: word)
             indegree[c] = 0;
        }

        int n = words.size();
        for (int i = 0; i + 1 < n; i++)
        {
           string& word1 = words[i];
           string& word2 = words[i+1];

           bool found = false;
           int len = min(word1.size(), word2.size());

           for (int j = 0; j < len; j++)
           {
             if (word1[j] != word2[j])
             {
               if (!graph[word1[j]].count(word2[j]))
               {
                 graph[word1[j]].insert(word2[j]);
                 indegree[word2[j]]++;
               }
               found = true;
               break;
             }
           }

           if (!found && word1.size() > word2.size())
             return "";
        }

        queue<char> q;
        for (auto& [c, deg] : indegree)
        {
            if (deg == 0)
              q.push(c);
        }

        string res;
        while (!q.empty())
        {
           int q_sz = q.size();
           //for (int i = 0; i < q_sz; i++)
           {
              char cur = q.front();
              q.pop();
              res.push_back(cur);

              for (auto& nei : graph[cur])
              {
                  indegree[nei]--;
                  if (indegree[nei] == 0)
                    q.push(nei);
              }
           }
        }

        if (res.size() != indegree.size())
          return "";
        
        return res;
    }
};