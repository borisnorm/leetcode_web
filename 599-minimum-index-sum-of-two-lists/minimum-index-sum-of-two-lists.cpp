class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        vector<string> res;

        int m = list1.size();
        int n = list2.size();

        int iSum = INT_MAX;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
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
};