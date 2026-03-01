class Solution {
public:
    vector<vector<string>> partition(string s) {
        if (s.empty())
          return {};
        
        int n = s.size();
        vector<string> path;
        vector<vector<string>> res;

        backtrack(s, 0, path, res);

        return res;
    }

    void backtrack(string& s, int start, vector<string>& path, vector<vector<string>>& res)
    {
        if (start == s.size())
        {
           res.push_back(path);
           return;
        }

        for (int i = start; i < s.size(); i++)
        {
            if (!isPalindrome(s, start, i))
              continue;
            
            path.push_back(s.substr(start, i-start+1));
            backtrack(s, i + 1, path, res);
            path.pop_back();
        }
    }

    bool isPalindrome(string& s, int l, int r)
    {
        if (l > r)
          return false;

        while(l < r)
        {
            if (s[l] != s[r])
              return false;
            
            l++;
            r--;
        }
        return true;
    }
};


/*
class Solution {
public:
    vector<vector<string>> res;
    vector<string> path;
    vector<vector<string>> partition(string s) {

       backtrack(s, 0);
       return res;
    }

    void backtrack(string s, int start)
    {
        if (start == s.size())
          res.push_back(path);
        
        for (int i = start; i < s.size(); i++)
        {
          if (!isPalindrome(s, start, i))
            continue;
        
          path.push_back(s.substr(start, i-start+1));
          backtrack(s, i + 1);
          path.pop_back();
       }
    }

    // 从 [l, r] 向中心收缩
    bool isPalindrome(string s, int l, int r)
    {
        while (l < r)
        {
            if (s[l] != s[r])
              return false;
            
            l++;
            r--;
        }

        return true;
    }
};

*/