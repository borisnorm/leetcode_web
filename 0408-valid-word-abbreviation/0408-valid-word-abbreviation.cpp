class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int m = word.size();
        int n = abbr.size();

        if (word == abbr)
           return true;

        int i = 0; 
        int j = 0;
        while (i < m && j < n){

            while (i < m && j < n && word[i] == abbr[j])
            {
              i++;
              j++;
            }

            if (i == m && j == n)
              return true;
            
            if (!(i < m && j < n))
              return false;

            if (word[i] != abbr[j] && !isdigit(abbr[j]))
              return false;
            
            if (isdigit(abbr[j]) && abbr[j] == '0')
              return false;

            int num = 0;
            while (j < n && isdigit(abbr[j]))
            {
              num = num * 10 + (abbr[j]-'0');
              j++;
            }

            i+= num;
            if (i < m && j < n && word[i] != abbr[j])
              return false;
        }

        if (i == m && j == n)
          return true;

        return false;
    }
};