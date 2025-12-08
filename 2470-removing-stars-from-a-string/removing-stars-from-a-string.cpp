class Solution {
public:
    string removeStars(string s) {
        
        string res;
 
        int n = s.size();
        for (int i = 0; i < n; i++)
        {
           if (s[i] == '*')
           {
              if (!res.empty())
                res.pop_back();
           }
           else
             res.push_back(s[i]);
        }

        return res;
    }
};