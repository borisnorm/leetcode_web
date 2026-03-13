class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size();
        int m = potions.size();

        sort(potions.begin(), potions.end());
        vector<int> pairs(n);
        for (int i = 0; i < n; i++)
        {
           int l = 0;
           int r = m-1;
          // 应该初始化为0, pairs[i] 返回的是个数, 
          // 没有找到的时候  也就是 全部 < success的时候, firstFoundIdx 不会被赋值
           int firstFoundIdx = m;
           while (l <= r)
           {
              int mid = l + (r-l)/2;
              long long product = 1LL * spells[i] * potions[mid];

              // at least means >=
              if (product >= success)
              {
                 firstFoundIdx = mid;
                 r = mid - 1;
              }
              else
              {
                 l = mid + 1;
              }
           }

           pairs[i] = m - firstFoundIdx;
        }

        return pairs;
    }
};
/*
class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        

          int  n = spells.size();

          vector<int> res;
          for (int i = 0; i < n; i++)
          {

            int m = potions.size();
            vector<int> pair(m);
            int spell = spells[i];
            
            int cnt = 0;
            for (int j = 0; j < m; j++)
            {
               if ((1LL * potions[j] * spell) >= success)
                 cnt++;
            }

            res.push_back(cnt);
          }

          return res;
    }
};
*/