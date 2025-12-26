class Solution {
public:
   bool validPalindrome(string s) {
     if (s.empty())
       return false;
     int n = s.size();

     int l = 0;
     int r = n - 1;
    
     if (isPalindrome(s, l, r))
       return true;
    
     while (l < r)
     {
        if (s[l] == s[r])
        {
           l++;
           r--;
        }
        else
        {
           return isPalindrome(s, l + 1, r) || isPalindrome(s, l, r-1);
        }
     }

     return true;

      
 }

   bool isPalindrome(string s, int l, int r)
   {
      while (l < r)
      {
         if (s[l] != s[r])
           return false;
         l++;
         r--;
      }

      return true;
   }

    /*
    bool validPalindrome(string s) {
        if (s.empty())
          return false;

        if (isPalindrome(s))
          return true;
        
        int n = s.size();
        for (int i = 0; i < n; i++)
        {

           string target_str = s.substr(0, i - 0);
        
           if (i + 1 < n)
           {
             target_str += s.substr(i+1, n - i - 1); // n - (n-2) -1  = 1
           }
        
           if (isPalindrome(target_str))
             return true;
           
          //  string target_str = s;
          // target_str.erase(i, 1);
          // if (isPalindrome(target_str))
          //   return true;
           
        }

        return false;
    }


    bool isPalindrome(string s)
    {
       if (s.empty())
         return true;
       
       int n = s.size();
       int l = 0; 
       int r = n - 1;

       while (l < r)
       {
          if (s[l] != s[r])
            return false;
          
          l++;
          r--;
       }

       return true;
    }
    */
};