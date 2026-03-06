class Solution {
public:

    bool isValidParentheses(const string& s)
    {
        int n = s.size();
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
           if (s[i] == '(')
             cnt++;
           else if (s[i] == ')')
             cnt--;

           if (cnt < 0)
             return false;
        }

        return (cnt == 0) ? true : false;
    }


    //N = 字符串长度，最坏情况全是括号
    //时间O(2^N × N)：每层最多生成 2^N 个子串，每个验证 O(N)
    //空间O(2^N × N)：visited set 存储所有访问过的字符串
    vector<string> removeInvalidParentheses(string s) {
        int n = s.size();

        unordered_set<string> visited;
        queue<string> q;

        q.push(s);
        visited.insert(s);
     // BFS 按删除数量分层：
     // 第0层：原字符串（删0个）
     // 第1层：所有删1个括号的字符串
     // 第2层：所有删2个括号的字符串
        vector<string> res;
        while (!q.empty())
        {
          int q_sz = q.size();
          bool found = false;

          for (int i = 0; i < q_sz; i++)
          {
             string cur = q.front();
             q.pop();

             if (isValidParentheses(cur))
             {
                res.push_back(cur);
                found = true;
             }

             if (found)
               continue;

             for (int j = 0; j < cur.size(); j++)
             {
                //处理字母
                if (cur[j] != '(' && cur[j] != ')')
                  continue;
              
                string nxt = cur.substr(0, j) + cur.substr(j+1);

                if (visited.count(nxt))
                  continue;

                visited.insert(nxt);
                q.push(nxt);
             }
          }

          if (found)
            break;
        }
        return res;
    }
};