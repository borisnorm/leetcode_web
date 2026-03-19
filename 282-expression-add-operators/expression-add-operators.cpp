class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> res;
        string path;
        dfs(num, target, 0, 0, 0, path, res);
        return res;
    }

    void dfs(string& num, long long target, int idx, long long eval, long long last, string& path, vector<string>& res)
    {
       int n = num.size();
       if (idx == num.size())
       {
          // expression val
          if (eval == target)
            res.push_back(path);
          return;
       }

       int pathLen = path.size();
       long long cur = 0;

       for (int i = idx; i < n; i++)
       {
         if (i > idx && num[idx] == '0')
           break;
         
         cur = cur * 10 + (num[i] - '0');
         string curStr = num.substr(idx, i - idx + 1);
         
         if (idx == 0)
         {
            path += curStr;
            dfs(num, target, i+1, cur, cur, path, res);
            path.resize(pathLen);
         }
         else
         {
            path += "+" + curStr;
            dfs(num, target, i+1, eval+cur, cur, path, res);
            path.resize(pathLen);

            path += "-" + curStr;
            dfs(num, target, i+1, eval-cur, -cur, path, res);
            path.resize(pathLen);

            path += "*" + curStr;
            dfs(num, target, i+1, eval-last+last*cur, last * cur, path, res);
            path.resize(pathLen);

         }

       }
    }
};