class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
         vector<pair<int, int>> events;

         for(auto& b: buildings)
         {
            int x1 = b[0];
            int x2 = b[1];
            int h =  b[2];
            events.push_back({x1, -h});
            events.push_back({x2, h});
         }

         sort(events.begin(), events.end());

         multiset<int> heights;
         heights.insert(0);

         int prevMax = 0;
         vector<vector<int>> res;

         for(auto& event: events)
         {
            int x = event.first;
            int h = event.second;

            if (h < 0)
              heights.insert(-h);
            else
              heights.erase(heights.find(h));

            int curMax = *heights.rbegin();
            if (curMax != prevMax)
            {
               res.push_back({x, curMax});
               prevMax = curMax;
            }
         }

         return res;
    }
};