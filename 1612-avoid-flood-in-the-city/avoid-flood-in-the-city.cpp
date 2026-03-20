class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();

        vector<int> res(n, -1);
        unordered_map<int, int> lastRain;
        set<int> sunny;

        for(int i = 0; i < n; i++)
        {
           if (rains[i] == 0)
           {
              sunny.insert(i);
              res[i] = 1;
           }
           else
           {
              int lake = rains[i];
              res[i] = -1;
              if (lastRain.count(lake))
              {
                int preDay = lastRain[lake];

                // find >= preDay
                auto it = sunny.lower_bound(preDay);
                if (it == sunny.end())
                    return {};

                res[*it] = lake;
                sunny.erase(it);
              }

              lastRain[lake] = i;
           }
        }
        return res;
    }
};