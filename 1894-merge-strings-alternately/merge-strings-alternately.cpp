class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();

        int i = 0;
        int j = 0;

        string res;
        while (i < m && j < n)
        {
           res += word1[i];
           res += word2[j];
           i++;
           j++;
        }

        while (i < m)
        {
          res += word1[i];
          i++;
        }

        while (j < n)
        { 
           res += word2[j];
           j++;
        }

        return res;
    }
};