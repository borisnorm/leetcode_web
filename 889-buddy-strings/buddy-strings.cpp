class Solution {
public:
    bool buddyStrings(string s, string goal) {
        
        int m = s.size();
        int n = goal.size();

        if (m != n)
          return false;
        
        if (s == goal){
            int freq[26];
            for (char c: s)
            {
               int idx = c - 'a';
               freq[idx]++;
               if (freq[idx] == 2)
                 return true;
            }            
          
          return false;
            
        }

        vector<int> diff;
        for (int i = 0; i < m; i++)
        {
          if (s[i] != goal[i])
            diff.push_back(i);
        }

        if (diff.size() != 2)
          return false;
        
        int i = diff[0];
        int j = diff[1];

        if (s[i] == goal[j] && goal[i] == s[j])
          return true;
        
        return false;
    }
};