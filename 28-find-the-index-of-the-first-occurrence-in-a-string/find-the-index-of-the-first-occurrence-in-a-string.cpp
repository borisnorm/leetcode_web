class Solution {
public:
    int strStr(string haystack, string needle) {
       int m = haystack.size();
       int n = needle.size();

       vector<int> lps(n, 0);

       int j = 0;
       for (int i = 1; i < n; i++)
       {
           while (j > 0 && needle[i] != needle[j])
           {
              j = lps[j-1];
           }

           if (needle[i] == needle[j])
             j++;
           
           lps[i] = j;
       }

       j = 0;
       for (int i = 0; i < m; i++)
       {
          while(j > 0 && haystack[i] != needle[j])
             j = lps[j-1];

          if (haystack[i] == needle[j])
            j++;
        
          if (j == n)
            return i - n + 1;  //返回起始索引
       }
      return -1;
    }
};

/*
class Solution {
public:
    int strStr(string haystack, string needle) {

         int m = haystack.size();
         int n = needle.size();

         if (m < n || m == 0)
           return -1;
        
         // 空串是任何字符串的子串,位置在 0
         if (n == 0)
           return 0;

        // [i, i+n-1] 要在 [0, m-1] 之内
        // i + n - 1 <= m - 1
        // i + n <= m
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

*/