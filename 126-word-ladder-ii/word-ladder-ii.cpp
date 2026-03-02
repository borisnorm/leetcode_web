
class Solution
{
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList){
        unordered_set<string> dict(wordList.begin(), wordList.end());

        vector<vector<string>> res;
        if (!dict.count(endWord))
          return {};
        
        unordered_map<string, int> dist;
        unordered_map<string, vector<string>> par;

        queue<string> q;
        q.push(beginWord);
        dist[beginWord] = 0;

        int L = (int)beginWord.size();
        int foundEndDist = -1;

        while(!q.empty())
        {
           int q_sz = q.size();
           for (int i = 0; i < q_sz; i++)
           {
              string cur = q.front();
              q.pop();

              int curDist = dist[cur];
              
              if (foundEndDist != -1 && curDist >= foundEndDist)
                continue;

              //go throgh current word 
              string nxt = cur;
              for (int p = 0; p < L; p++)
              {
                  char old = nxt[p];
                  for (char c = 'a'; c <= 'z'; c++)
                  {
                    if (c == old)
                      continue;
                    
                    nxt[p] = c;

                    if (!dict.count(nxt))
                       continue;
                    
                    if (!dist.count(nxt))
                    {
                       dist[nxt] = curDist + 1;
                       par[nxt].push_back(cur);
                       q.push(nxt);

                       if (nxt == endWord)
                         foundEndDist = dist[nxt];
                    }
                    else if (dist[nxt] == curDist + 1)
                    {
                        par[nxt].push_back(cur);
                    }
                  }

                  nxt[p] = old;
              }
           }

           if (foundEndDist != - 1)
             break;
        }

        if(foundEndDist == - 1)
          return res;
        
        vector<string> path;
        path.push_back(endWord);
        dfs(endWord, beginWord, par, path, res);

        return res;
    }

    void dfs(string& cur, string& beginWord, unordered_map<string, vector<string>>& par, vector<string>& path, vector<vector<string>>& res)
    {
       if (cur == beginWord)
       {
          vector<string> one = path;
          reverse(one.begin(), one.end());
          res.push_back(one);
          return;
       }

       if (!par.count(cur))
         return;

       vector<string>& parList = par[cur];
       for (int i = 0; i < parList.size(); i++)
       {
           string& pre = parList[i];
           path.push_back(pre);
           dfs(pre, beginWord, par, path, res);
           path.pop_back();
       }
    }

};
/*
class Solution
{
public:
    vector<vector<string>> res;
    unordered_map<string, vector<string>> par; // par[w] = w 的所有最短前驱

    void bfs(const string& begin, const string& end, unordered_set<string>& dict)
    {
        queue<string> q;
        q.push(begin);
        unordered_map<string, int> dist;
        dist[begin] = 0;
        dict.erase(begin);
        bool found = false;

        while (!q.empty() && !found)
        {
            int sz = q.size();
            unordered_set<string> visited; // 本层新发现的词

            for (int i = 0; i < sz; i++)
            {
                string cur = q.front(); q.pop();
                int L = cur.size();
                string tmp = cur;

                for (int p = 0; p < L; p++)
                {
                    char orig = tmp[p];
                    for (char c = 'a'; c <= 'z'; c++)
                    {
                        if (c == orig) continue;
                        tmp[p] = c;

                        if (!dict.count(tmp))  // 不在字典跳过
                        {
                            tmp[p] = orig;
                            continue;
                        }

                        if (!dist.count(tmp))  // 第一次发现
                        {
                            dist[tmp] = dist[cur] + 1;
                            visited.insert(tmp);
                            q.push(tmp);
                        }

                        if (dist[tmp] == dist[cur] + 1) // 合法前驱边
                            par[tmp].push_back(cur);    // tmp 的前驱是 cur

                        if (tmp == end) found = true;

                        tmp[p] = orig;
                    }
                }
            }

            for (auto& w : visited)
                dict.erase(w); // 整层处理完再删，防止回头
        }
    }

    // 从 end 往回溯到 begin，最后 reverse
    void dfs(const string& cur, const string& begin, vector<string>& path)
    {
        if (cur == begin)
        {
            vector<string> one = path;
            reverse(one.begin(), one.end()); // 翻转得到正向路径
            res.push_back(one);
            return;
        }
        if (!par.count(cur)) return;
        for (auto& pre : par[cur])
        {
            path.push_back(pre);
            dfs(pre, begin, path);
            path.pop_back();
        }
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList)
    {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (!dict.count(endWord)) return {};

        bfs(beginWord, endWord, dict);

        if (!par.count(endWord)) return {};

        vector<string> path = {endWord}; // 从终点开始回溯
        dfs(endWord, beginWord, path);
        return res;
    }
};

*/
