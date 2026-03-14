class Solution {
public:
    int maxDepth(string s) {
        int depth = 0;
        int maxDep = 0;

        for (char c: s)
        {
          if (c == '(')
          {
             depth++;
             maxDep = max(maxDep, depth);
          }
          else if (c == ')')
          {
             depth--;
          }
        }

        return maxDep;
    }
};

/*
class Solution {
public:
    int maxDepth(string s) {
        
        int maxDep = 0;
        stack<char> st;

        for (char c: s)
        {
           if (c == '(')
           {
              st.push(c);
              maxDep = max(maxDep, (int)st.size());
           }
           else if (c == ')')
           {
              st.pop();
           }
        }
        return maxDep;
    }
};

*/