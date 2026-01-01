class Solution {
public:
    string entityParser(string text) {
        unordered_map<string, char> mp = {
            {"&quot;",  '\"'}, 
            {"&apos;",  '\''}, 
            {"&amp;",   '&'}, 
            {"&gt;",    '>'}, 
            {"&lt;",    '<'}, 
            {"&frasl;", '/'}
        };

        int n = (int)text.size();
   
        string res;
        for (int i = 0; i < n; )
        {
            if (text[i] != '&')
            {
               res.push_back(text[i]);
               i++;
               continue;
            }
        
            bool replaced = false;
            for (auto kv: mp)
            {
               string key = kv.first;
               int key_sz = key.size();

               if (i + key_sz <= n && text.compare(i, key_sz, key) == 0)
               {
                  res.push_back(kv.second);
                  i += key_sz;
                  replaced = true;
                  break;
               }
            }

            if (!replaced)
            {
               res.push_back(text[i]);
               i++;
            }
        }

        return res;
    }
};