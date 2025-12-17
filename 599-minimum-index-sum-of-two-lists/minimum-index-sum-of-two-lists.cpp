class Solution {
public:

vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        vector<string> res;

        int m = list1.size();
        int n = list2.size();
        
        unordered_map<string, int> list1_word2idx;
        for (int i = 0; i < m; i++)
          list1_word2idx[list1[i]] = i;

        int minIdxSum = INT_MAX;
        for (int j = 0; j < n; j++)
        {
            if (list1_word2idx.count(list2[j]))
            {
               int idxSum = j + list1_word2idx[list2[j]];
               if (idxSum < minIdxSum)
               {
                  res.clear();
                  res.push_back(list2[j]);
                  minIdxSum = idxSum;
               }
               else if (idxSum == minIdxSum)
                 res.push_back(list2[j]);
            }
        }

        return res;
    }
    /*
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        vector<string> res;

        int m = list1.size();
        int n = list2.size();

        int iSum = INT_MAX;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)   // hash map  在这里使用
            {
               if (list1[i] == list2[j])
               {
                  if (i + j <= iSum)
                  {
                     if (i + j < iSum && !res.empty())
                       res.pop_back();
                    
                     iSum = i + j;
                     res.push_back(list1[i]);
                  }
                  
               }
            }
        }

        return res;
    }
    */
};