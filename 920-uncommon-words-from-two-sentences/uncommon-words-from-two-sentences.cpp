class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> s1_mp;
        unordered_map<string, int> s2_mp;
        //unordered_set<string> uncommon_set;

        vector<string> res;

        string s1_word;
        stringstream s1_ss(s1);
        while(s1_ss >> s1_word)
           s1_mp[s1_word]++;
          
        string s2_word;
        stringstream s2_ss(s2);
        while(s2_ss >> s2_word)
          s2_mp[s2_word]++;;
        
        for(auto it: s1_mp)
        {
           if (!s2_mp.count(it.first) && it.second == 1)
             res.push_back(it.first);
        }

        for (auto it: s2_mp)
        {
            if (!s1_mp.count(it.first) && it.second == 1)
              res.push_back(it.first);
        }

        return res;
    }
};