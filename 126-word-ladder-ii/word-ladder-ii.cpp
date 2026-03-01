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
