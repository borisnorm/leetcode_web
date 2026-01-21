class Solution {
public:

    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        if (strs.empty())
          return {};

        vector<vector<string>> res;

        unordered_map<string, vector<string>> key2anagram;
        for (auto& str: strs)
        {
            // count freq
            int freq[26] = {0};
            for(char c: str)
              freq[c -'a']++;
            
            // construct key
            string key;
            for (int i = 0; i < 26; i++)
            { 
               string freq_str = '#' +  to_string(freq[i]); 
               key += freq_str;
            }

            //group by key
            key2anagram[key].push_back(str);
        }

        for (auto& it: key2anagram)
        {
           res.push_back(move(it.second)); 
        }

        return res;


    }
    
/*    
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

        for (auto& iter: key2anagram)
           res.push_back(move(iter.second));    

        return res;
    }

    */
};