class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
         int m = word.size();
         int n = abbr.size();
         int i = 0; 
         int j = 0;
         while (i < m && j < n){
            if (isalpha(abbr[j]))
            {
                if (word[i] != abbr[j])
                  return false;
                
                i++;
                j++;
            }
            else
            {
               if (j < n && abbr[j] == '0')
                 return false;
                
               int num = 0;
               while (j < n && isdigit(abbr[j])){
                  num = num*10 + (abbr[j]-'0');
                  j++;
               }

               i+= num;
            }
         }
         return i == m && j == n;
    }
};