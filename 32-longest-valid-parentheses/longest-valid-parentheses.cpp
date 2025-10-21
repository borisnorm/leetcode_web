class Solution {
public:
    int longestValidParentheses(string s) {
      stack<int> st;
      st.push(-1);

      int ans = 0;
      int n = s.size();
      for (int i = 0; i < n; i++)
      {
        char c = s[i];
        if (c == '(')
          st.push(i);
        else
        {

           st.pop();          
           if (st.empty())
           {
             st.push(i);
           }
           else
           {
              ans = max(ans, i - st.top());
           }
        }

      }

      return ans;
    }
};