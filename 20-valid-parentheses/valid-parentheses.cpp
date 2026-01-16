class Solution {
public:
   bool isValid(string s) {
      // more left
      // more right
      // mismatched left and right;

      if (s.empty())
        return false;

      stack<char> st;
      for (char c: s)
      {
        if (c == '[' || c == '(' || c == '{')
        {
           st.push(c);
        }
        else
        {
           // more right parenthese
           if (st.empty())
             return false;
           
           if (c == matchedChar(st.top()))
           {
              st.pop();
           }
           else
           {
              return false;
           }
        }

         
      }
      return st.empty() ? true: false;
   }

   char matchedChar(char c)
   {    
     // if (c == '')
      //  return '';

      if (c == '(')
        return  ')';
      else if (c == '[')
        return  ']';
      else if (c == '{')
        return  '}';
      else 
        return  ' ';

   }
    /*
    bool isValid(string s) {
       stack<char> st;
       unordered_map<char, char> mp = {
         {')', '('},  
         {']', '['}, 
         {'}', '{'}
       };

       for (char c: s)
       {  
          // right parenthese
          if (mp.count(c))
          {
             if (st.empty() || st.top() != mp[c])
               return false;
             st.pop();
          }
          else
          {
             st.push(c);
          }
       }

       return st.empty();
    }

    */
};