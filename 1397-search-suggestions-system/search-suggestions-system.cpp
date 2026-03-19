class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
      
        sort(products.begin(), products.end());

        vector<vector<string>> res;

        string prefix = "";
        for (char c : searchWord)
        {
           prefix += c;

           auto it = lower_bound(products.begin(), products.end(), prefix);

           vector<string> match;
           for (int i = 0; i < 3 && it != products.end(); i++, it++)
           {
              // 错误 if (*it.substr(0, prefix.size()) == prefix)
              // 正确 if ((*it).substr(0, prefix.size()) == prefix)  // .的优先级 高于 *
              // 也是正 if (it->substr(0, prefix.size()) == prefix)
              if ((*it).substr(0, prefix.size()) == prefix)
                match.push_back(*it);
              else
                break;
           }

           res.push_back(match);
        }

        return res;

        return res;
    }
};