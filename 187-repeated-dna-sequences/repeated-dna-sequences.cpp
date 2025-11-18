class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n = s.size();
        vector<string> res;

        if (n < 10)
          return res;
        
        unordered_map<string, int> cnt_mp;

        for (int i = 0; i + 10 <= n; i++)
        {
           string sub = s.substr(i, 10);
           cnt_mp[sub]++;

           if (cnt_mp[sub] == 2)
             res.push_back(sub);
        }

        return res;
    }
};