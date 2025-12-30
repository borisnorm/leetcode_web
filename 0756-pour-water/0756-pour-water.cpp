class Solution {
public:
    vector<int> pourWater(vector<int>& heights, int volume, int k) {
        int n = heights.size();

        while(volume)
        {
           
            int prev = k;
            int minPos = k;
            for (int i = k-1; i >= 0; i--)
            {
                if (heights[i] > heights[prev])
                  break;
                
                if (heights[i] < heights[minPos])
                {
                    minPos = i;
                }

                prev = i;
            }

            if (minPos != k)
            {
                heights[minPos]++;
                // continue to flow on left;
                volume--;
                continue;
            }

            minPos = k;
            prev   = k;

            for (int i = k + 1; i < n; i++)
            {
                if (heights[i] > heights[prev])
                  break;

                if (heights[i] < heights[minPos])
                  minPos = i;

                prev = i;
            }

            // flow to right or worst case on k idx;
            heights[minPos]++;

            volume--;
        }

        return heights;
    }
};