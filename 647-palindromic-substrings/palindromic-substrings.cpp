class Solution {
public:
    int countSubstrings(string s) {
        if (s.empty())
          return 0;
        int n = s.size(); 
        int ans = 0;
        
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

        for (int i = 0; i < n; i++)
        {
           ans += expand(i, i);
           ans += expand(i, i+1);   
        }

        return ans;
    }
};