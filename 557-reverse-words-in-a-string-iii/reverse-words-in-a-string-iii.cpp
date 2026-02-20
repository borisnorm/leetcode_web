class Solution {
public:
    string reverseWords(string s) {
        if (s.empty())
          return "";
        
        int n = s.size();
        int i = 0;

        while(i < n)
        {
           while(i < n && s[i] == ' ')
             i++;
           if (i == n)
             break;
           
           int start = i;
           while(i < n && s[i] != ' ')
             i++;
           int end = i;

           //reverse(s.begin()+start, s.begin()+end);
           reverse2(s, start, end-1);
        }

        return s;
    }

    void reverse2(string& s, int l, int r)
    {
        while(l < r)
        {
           swap(s[l], s[r]);
           l++;
           r--;
        }
    }
};
/*
class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        if (n == 0)
          return "";

        int i = 0;
        int l = 0;
        int r = 0;
        while (i < n)
        {
           l = i;
           while(i < n && s[i] != ' ')
             i++;
           r = i - 1;
           reverseWord(s, l, r);

           while(i < n && s[i] == ' ')
             i++;
        }
        return s;
    }

    void reverseWord(string& s, int l, int r)
    {
       int n = s.size();

       while (l < r && r < n)
       {
          swap(s[l], s[r]);
          l++;
          r--;
       }
    }
};

*/