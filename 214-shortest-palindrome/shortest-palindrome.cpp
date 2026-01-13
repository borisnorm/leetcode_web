class Solution {
public:

    string shortestPalindrome(string s) {
      
       int n = s.size();
       
       string r = s;
       reverse(r.begin(), r.end());
       
       string t = s + '#' + r;

       int m = t.size();

       vector<int> lps(m, 0);
       for (int i = 1; i < m; i++)
       {
          int j = lps[i-1];

          while (j > 0 && t[i] != t[j])
            j = lps[j-1];

          if (t[i] == t[j])
            j++;
    
          lps[i] = j;
       }

       int L = lps.back();
       
       string add = s.substr(L);
       reverse(add.begin(), add.end());

       return add + s;

    }

/*
    string shortestPalindrome(string s) {
        int n = s.size();
        if (n <= 1)
          return s;
        
        string r = s;
        reverse(r.begin(), r.end());

        string t = s + '#' + r;  //  正序 + # + 逆序

        // build lps (prefix function)
        vector<int> lps(t.size(), 0);
        for (int i = 1; i < t.size(); i++)
        {
           // j is previous element position
           int j = lps[i-1];
           while (j > 0 && t[i] != t[j])
             j = lps[j-1];

            if (t[i] == t[j])
              j++;
            
            lps[i] = j;
        }

        int L = lps.back();
        string add = s.substr(L);
        reverse(add.begin(), add.end());

        return add + s;
    }
    */
};