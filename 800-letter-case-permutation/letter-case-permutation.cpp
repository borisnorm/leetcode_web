class Solution {
public:
    vector<string> res;
    vector<string> letterCasePermutation(string s) {
        if (s.empty())
          return  {};
        
        string permuation;
        backtrack(s, 0, permuation);

        return res;
    }

    void backtrack(string s, int pos, string permutation)
    {
    
       int n = s.size();
       if (permutation.size() == s.size())
       {
          res.push_back(permutation);
          return;
       }
       else if (pos >= n)
       {
          return;
       }
       
      /*
       // 正确 但 彻底在 破坏 backtrack 的结构
       if (isdigit(s[pos]))
       {
         permutation += s[pos];
         pos++;
         if (pos == n && permutation.size() == s.size())
         {
            res.push_back(permutation);
            return;
         }
       }
       */
       
       
       if (isalpha(s[pos]))
       {
          char c = s[pos];
          
          permutation.push_back(tolower(s[pos]));
          backtrack(s, pos + 1, permutation);
          permutation.pop_back();

          permutation.push_back(toupper(s[pos]));
          backtrack(s, pos + 1, permutation);
          permutation.pop_back();
       }
       else if (isdigit(s[pos]))
       {
          permutation.push_back(s[pos]);
          backtrack(s, pos + 1, permutation);
          permutation.pop_back();
       }

       return;
    }
};