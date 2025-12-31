class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st;

        int n = s.size();
        vector<bool> valid(n, true);

        for (int i = 0; i < n; i++)
        {
           char c = s[i];
           if (c == '(')
           {
              st.push(i);
           }
           else if (c == ')')
           {
              //  不需要判断, 因为只 push 了 '('
              //if (!st.empty() && s[st.top()] == '(')
              if(!st.empty())
              {
                  st.pop();
              } 
              else
              {
                 valid[i] = false;
              }
           }
        }
        
        while (!st.empty())
        {
            valid[st.top()] = false;
            st.pop();
        }

        string res;

        for (int i = 0; i < n; i++)
          if (valid[i])
            res += s[i];
        
        return res;

    }
};