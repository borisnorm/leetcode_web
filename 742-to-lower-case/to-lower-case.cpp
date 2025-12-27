class Solution {
public:
    string toLowerCase(string s) {
         if (s.empty())
           return s;
        
          // A < B < C ... < Z < a < b
          //'A' = 65
          //'Z' = 90

          //'a' = 97
          //'z' = 122

         for (int i = 0 ; i < s.size(); i++)
         {
            //if (s[i] - 'a' < 0)
            if ( 'A' <= s[i] && s[i] <= 'Z')
              s[i] = 'a' + (s[i] - 'A');
         }

         return s;
     }
};