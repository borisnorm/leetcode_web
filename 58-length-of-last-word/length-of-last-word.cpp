class Solution {
public:
    int lengthOfLastWord(string s) {
        
        int n = s.size();
        int i = n -1;

        while (i >= 0 && s[i] == ' ')
          i--;
        
        int len = 0;
        while (i >= 0 && s[i] != ' ')
        {
           i--;
           len++;
        }

        return len;

    }
};

/*
class Solution {
public:
    int lengthOfLastWord(string s) {
        if (s.empty())
          return 0;
           
        int n = s.size();
        int l = 0;
        int r = n - 1;

        while (r >= 0 && s[r] == ' ')
          r--;
        
        int pos = -1;
        while (l < r)
        {
           if (s[l] == ' ')
             pos = l;

           l++; 
        }

        return r-pos;
        
    }
};

*/