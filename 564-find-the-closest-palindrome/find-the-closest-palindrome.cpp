class Solution {
public:
    string nearestPalindromic(string n) {
        int len = n.size();
        long long num = stoll(n);

        vector<long long> cands;

        cands.push_back((long long)pow(10, len-1) - 1);
        cands.push_back((long long)pow(10, len) + 1);

        // "12345" len = 5   6/2 = 3
        //  123 
        long long half = stoll(n.substr(0, (len+1)/2));
        
        for (int delta = -1; delta <= 1; delta++)
        {
          long long h = half + delta;

          // positive str
          string h_str = to_string(h);
          
          // rev str
          string rev = h_str;
          reverse(rev.begin(), rev.end());

          string mirror = h_str + rev.substr(len % 2);
          cands.push_back(stoll(mirror));
        }

        long long ans = -1;
        for (long long cand : cands)
        {
           if (cand == num)
             continue;
          
           if (ans == -1 ||
                abs(cand - num) < abs(ans - num) || 
               (abs(cand - num) == abs(ans - num) && cand < ans))
            {
               ans = cand;
            }
        }
        return to_string(ans);
    }
};