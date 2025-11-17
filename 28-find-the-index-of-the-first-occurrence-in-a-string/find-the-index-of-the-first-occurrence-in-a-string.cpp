class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty())
          return 0;

        if (haystack.empty())
          return -1;

         int m = haystack.size();
         int n = needle.size();

        for (int i = 0; i + n <= m; i++)
        {
            int j = 0;
            while (j < n && haystack[i+j] == needle[j])
              j++;
            if (j == n)
              return i;
        }

        return -1;
    }
};