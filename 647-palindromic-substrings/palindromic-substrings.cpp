class Solution {
public:
    int countSubstrings(string s) {
        if (s.empty())
          return 0;
        int n = s.size(); 
        long long ans = 0;
        
        /*
        auto expand = [&](int l, int r){
            int cnt = 0;
             
            while (l >=0 && r < n && s[l]==s[r])
            {
                l--;
                r++;
                cnt++;
            }
            return cnt;
        };
        */

        for (int i = 0; i < n; i++)
        {
           ans += expand(s, i, i);
           ans += expand(s, i, i+1);   
        }

        return ans;
    }

    long long expand(const string &s, int l, int r)
    {
        long long cnt = 0;
        int n = s.size();

        while (l >= 0 && r < n && s[l] == s[r])
        {
           l--;
           r++;
           cnt++;
        }

        return cnt;
    }
};