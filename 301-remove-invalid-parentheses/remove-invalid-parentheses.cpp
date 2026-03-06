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

    vector<string> removeInvalidParentheses(string s) {
        int n = s.size();

        unordered_set<string> visited;
        queue<string> q;

        q.push(s);
        visited.insert(s);

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