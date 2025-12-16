class Solution {
public:
    bool rotateString(string s, string goal) {

          int m = s.size();
          int n = goal.size();

          if (m != n)
            return false;
        
          // if bott empty, it should return true
          if (s.empty())
            return false;
        

          for (int i = 0; i < m; i++)
          {
             s = s.substr(1, m - 1) + s[0];

             if (s == goal)
               return true;
          }

          return false;
    }
};