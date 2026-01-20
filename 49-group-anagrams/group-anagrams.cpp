class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        
        unordered_map<string, vector<string>> key2anagram;
        for (auto& word : strs)
        {
           //统计频率
           int cnt[26]={0};
           for (char c: word)
             cnt[c-'a']++;

           //由频次生成 key
           string key;
           for (int i = 0; i < 26; i++)
           {
              key.push_back('#');
              key += to_string(cnt[i]);
              //key += "#" + to_string(cnt[i]);
           } 

           // anagram 有相同的的 key, 以上不同 str 会在这里完成汇聚
           key2anagram[key].push_back(word);
        }

        for (auto& [key, anagram_vec]: key2anagram)
           res.push_back(move(anagram_vec));    

        return res;
    }
};