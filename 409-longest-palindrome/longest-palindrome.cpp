class Solution {
public:
    int longestPalindrome(string s) {

        if (s.empty())
          return 0;
        
        vector<int> s_vec(128,0);
        int s_length = s.length();
        for (int i = 0; i < s_length; i++)
          s_vec[s[i]]++;

        int cnt = 0;
        bool odd_char = false;
        for (int i= 0 ; i < s_vec.size(); i++)
        {
            cnt += (s_vec[i]/2)*2;
          
           if (s_vec[i]%2 != 0)
             odd_char = true;
        }

        if (odd_char)
          cnt = cnt + 1;

        return cnt;
    }
};