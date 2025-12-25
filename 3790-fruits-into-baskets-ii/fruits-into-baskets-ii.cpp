class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {

        int m = baskets.size();
        int n = fruits.size();

        vector<int> filled(m, 0);

        int unplaced = 0;
        for (int i = 0; i < n; i++)
        {
           bool ith_filled = false;
           for (int j = 0; j < m; j++)
           {
             if (!filled[j] && fruits[i] <= baskets[j])
             {
                filled[j] = 1;
                ith_filled = true;
                break;
             }
           }

           if (!ith_filled)
             unplaced++;
        }

        return unplaced;
    }
};