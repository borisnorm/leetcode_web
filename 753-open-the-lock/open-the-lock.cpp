class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> dead(deadends.begin(), deadends.end());

        if (dead.count("0000"))
          return -1;
        
        if (target == "0000")
          return 0;

        auto neighbors=[&](const string& s){
            vector<string> res;
            for (int i = 0; i < 4; i++)
            {
                string t = s;

                t[i] = (s[i] == '9') ? '0' : s[i] + 1;
                res.push_back(t);

                t[i] = (s[i] == '0') ? '9' : s[i] - 1;
                res.push_back(t);
            }

            return res;
        };

        queue<string> q;
        unordered_set<string>  visited;
        q.push("0000");
        visited.insert("0000");

        int steps = 0;
        while (!q.empty())
        {
           int q_size = q.size();

           for (int i = 0; i < q_size; i++)
           {
              string cur = q.front();
              q.pop();

              for (auto& nei : neighbors(cur))
              {
                 if (dead.count(nei) || visited.count(nei))
                   continue;
                
                 if (nei == target)
                   return steps + 1;

                  visited.insert(nei);

                  q.push(nei);
              }
           }

           steps++;
        }

        return -1;
    }

};