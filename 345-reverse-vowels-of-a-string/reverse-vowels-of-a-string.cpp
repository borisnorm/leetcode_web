class Solution {
public:
    string reverseVowels(string s) {
        if (s.empty())
          return "";

        string res;

        //vector<pair<char, int>> char2idx;
        vector<int> char2idx;

        int n = s.size();
        for (int i = 0; i < n; i++)
        {
          if (isVowel(s[i]))
            char2idx.push_back(i);
          //  char2idx.push_back(make_pair(s[i], i)); 
        }

        int l = 0;
        int r = char2idx.size() - 1;

        while (l < r)
        {
           //int l_idx = char2idx[l].second;
           //int r_idx = char2idx[r].second;

           int l_idx = char2idx[l];
           int r_idx = char2idx[r];
           swap(s[l_idx], s[r_idx]);

           l++;
           r--;
        }

        res = s;

        return res;
    }

    bool isVowel(const char c)
    {
       if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
           c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
         return true;
    
       return false;
    }
};