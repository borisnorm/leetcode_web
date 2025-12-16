class Solution {
public:
    bool rotateString(string s, string goal) {
          if (s.empty() || goal.empty())
            return false;
        
          int m = s.size();
          int n = goal.size();

          if (m != n )
            return false;
        
          string t;
          for (int i = 0; i < m; i++)
          {
             s = s.substr(1, m - 1) + s[0];

             if (s == goal)
               return true;
          }

          return false;
    }
};