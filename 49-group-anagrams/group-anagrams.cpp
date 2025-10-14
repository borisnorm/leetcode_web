class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        
        unordered_map<string, vector<string>> mp;
        for (auto& s : strs)
        {
           int cnt[26]={0};
           for (char c: s)
             cnt[c-'a']++;

           string key;
           for (int i = 0; i < 26; i++)
           {
              key.push_back('#');
              key += to_string(cnt[i]);
           } 

           mp[key].push_back(s);
        }

        
        for (auto& iter: mp)
           res.push_back(iter.second);    

        return res;
    }
};