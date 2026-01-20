class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        
        vector<int> tripDist(1001, 0);

        for (auto& trip: trips)
        {
            int nPassangers = trip[0];
            int from = trip[1];
            int to = trip[2];

            tripDist[from] += nPassangers;
            tripDist[to]   += -nPassangers;
        }

        int curPassangers = 0;
        for (int i = 0; i <= 1000; i++)
        {
            curPassangers += tripDist[i];

            if (curPassangers > capacity)
               return false;
        }

        return true;
    }
};