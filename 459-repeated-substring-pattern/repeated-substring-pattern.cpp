class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();

        vector<int> lps(n, 0);
        
        int j = 0;
        for (int i = 1; i < n; i++)
        {
            //int j = lps[i-1];

            while (j > 0 && s[i] != s[j])
              j = lps[j-1];

            if (s[i] == s[j])
              j++;

            lps[i] = j;
        }

        int l = lps[n-1];
        return (l > 0 && (n %(n-l) == 0)) ? true: false;
    }

/*
    bool repeatedSubstringPattern(string s) {
         string t = s + s;
        
         int t_sz = t.size();
         // 去掉头尾, 找 rotated substring pattern
         string rotated_substr = t.substr(1, t_sz - 2);

         if (rotated_substr.find(s) != string::npos)
           return true;
        
        return false;
    }
*/
};