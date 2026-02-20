class Solution {
public:
    void reverseWords(vector<char>& s) {
        if (s.empty())
          return;
        
        reverse(s.begin(), s.end());

        int n = s.size();
        int i = 0;
        while (i < n)
        {
           while(i < n && s[i] == ' ')
             i++;
           int start = i;
           while (i < n && s[i] != ' ')
             i++;
           int end = i;
           reverse2(s, start, end-1);
        }
    }

    void reverse2(vector<char>& s, int l, int r)
    {
       while(l < r)
         swap(s[l++], s[r--]);
    }
};