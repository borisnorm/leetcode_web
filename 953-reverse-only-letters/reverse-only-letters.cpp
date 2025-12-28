class Solution {
public:
    string reverseOnlyLetters(string s) {
        
        int n = s.size();
        if (n == 1)
          return s;
        
        int l = 0;
        int r = n - 1;

        while (l < r)
        {
           while(l < r && !isalpha(s[l]))
             l++;
           
           while(l < r && !isalpha(s[r]))
             r--;

           swap(s[l], s[r]);

           l++;
           r--;
        }

        return s;
    }
};