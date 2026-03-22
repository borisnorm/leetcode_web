class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> prefix;

        for(int x: arr1)
        {
           while (x)
           {
              prefix.insert(x);
              x /= 10;
           }
        }

        int maxLen = 0;
        for (int y: arr2)
        {
          
           while(y)
           {
              if (prefix.count(y))
              {
                 int len = to_string(y).size();
                 maxLen = max(maxLen, len);
                 break;
              }
              y /= 10;
           }
        }

        return maxLen;
    }
};
/*
class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<string> prefix;

        for(int x: arr1)
        {
           string x_str = to_string(x);

          // 错误 x_str.substr 是 [l, r) 的用法
           //for (int i = 0; i < x_str.size(); i++)
           for (int i = 1; i <= x_str.size(); i++)
              prefix.insert(x_str.substr(0, i));
        }

        int maxLen = 0;
        for (int y: arr2)
        {
           string y_str = to_string(y);
           for (int i = y_str.size(); i > 0; i--)
           {
              if (prefix.count(y_str.substr(0, i)))
              {
                 maxLen = max(maxLen, i);
                 break;
              }
           }
        }

        return maxLen;
    }
};

*/