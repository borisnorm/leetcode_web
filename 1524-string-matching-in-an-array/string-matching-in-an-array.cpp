class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        
         int n = words.size();

         vector<string> res;
         
         unordered_set<string> substr_set;
         for (int i = 0; i < n; i++)
         {

            for (int j = 0; j < n ; j++)
            {
                if (i == j)
                  continue;
                
                if (isSubstring(words[i], words[j]))
                {
                    //substr_set.insert(words[i]);
                    res.push_back(words[i]);
                    break;
                }
            }

         }

         //vector<string> res(substr_set.begin(), substr_set.end());
         return res;
    }

    // a is substr of b
    bool isSubstring(string a, string b)
    {
        int a_sz = (int)a.size();
        int b_sz = (int)b.size();
        if (a_sz > b_sz)
          return false;
        
        // “如果我从 start 开始，取 asz 个字符，
       // 最后一个字符会落在哪个下标？”
        for (int i = 0; i + a_sz - 1 < b_sz; i++)
        {
           int k = 0;
           while (k < a_sz && b[i + k] == a[k])
             k++;
           
           if (k == a_sz)
             return true;
        }

        return false;

    }
};