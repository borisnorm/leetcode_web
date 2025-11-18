class Solution {
public:
    bool isValid(string s) {
        if (s.empty())
          return true;

        stack<char> st;
        for (int i = 0; i < s.size(); i++)
        {
           char c = s[i];
           if (s[i] == '{' || s[i] == '[' || s[i]== '(')
              st.push(s[i]);
           else
           {
              if (!st.empty())
              {
                char d = st.top();
                if (c == matchedChar(d))
                  st.pop();
                else
                  return false;
              }
              else
                return false;
           }

        }

         return (st.empty()) ? true : false;
    }

    char matchedChar(char c)
    {
       if (c == '(')
         return ')';
       else if (c == '[')
         return ']';
       else if (c == '{')
         return '}';
       else
         return ' ';
    }
};