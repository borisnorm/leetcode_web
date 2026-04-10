
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

         if (strs.empty())
           return "";

         int m = strs.size();
         int n = strs[0].size();

         for (int col = 0; col < n; col++)
         {  
            //这是 第0 行
            char c = strs[0][col];
            for (int row = 1; row < m; row++)
            {
              if (strs[row].size() <= col || strs[row][col] != c)
                return strs[0].substr(0, col);  
            }
         }

         return strs[0];
    }
};

/*
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
*/