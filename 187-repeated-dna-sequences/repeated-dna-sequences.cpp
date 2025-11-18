class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
         if (s.empty())
           return {};
        
         vector<string> res;
         int n = s.size();

         unordered_map<string, int> substr_mp;

         for (int i = 0; i + 10 <= n; i++)
         {
            string substr = s.substr(i, 10);
            substr_mp[substr]++;

            if (substr_mp[substr] == 2)
              res.push_back(substr);
         }

         return res;
    }
};