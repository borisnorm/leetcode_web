class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

         if (strs.empty())
           return "";

         int m = strs.size();
         int n = strs[0].size();
      
         string prefix = strs[0];

         for (int i = 1; i < m; i++)
         {
            int j = 0;
            while (j < prefix.size() && j < strs[i].size() &&
                   prefix[j] == strs[i][j])
              j++;
            
            prefix = prefix.substr(0, j);

            if (prefix.empty())
              return "";
         }

         return prefix;
 

    }
};