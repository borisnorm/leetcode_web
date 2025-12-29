class Solution {
public:
    bool detectCapitalUse(string word) {
        
        if (word.empty())
           return true;

        int preStatus = 0;  // 1, 2
        int status = 0;
        int n = word.size();
        if (n <= 1)
          return true;
       
        for (int i = 0; i < n; i++)
        {
           char c = word[i];
           if ('A' <= c && c <= 'Z')
             status = 1;
           else if ('a' <= c && c <= 'z')
             status = 2;

           if (preStatus != 0 && status != preStatus)
           {
             if (! (i == 1 && preStatus == 1 && status == 2))
               return false;
           }
          
           preStatus = status;
           
        }

        return true;
    }
};