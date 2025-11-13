class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

         if (strs.empty())
           return "";

         int m = strs.size();
         int n = strs[0].size();

         for (int col = 0; col < n; col++)
         {
            char c = strs[0][col];
            for (int row = 1; row < m; row++)
            {
              if ( !(col < strs[row].size() && strs[row][col] == c))
                return strs[0].substr(0, col);  
            }
         }

         return strs[0];
    }
};