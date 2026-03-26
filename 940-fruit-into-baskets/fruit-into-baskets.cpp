class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        
        int n = fruits.size();
        int l = 0;
        int r = 0;
        unordered_map<int, int> fruitType2cnt;
        int maxFruits = 0;
        while (r < n)
        {
            int fruitType = fruits[r];
            fruitType2cnt[fruitType]++;
            r++;

            while (fruitType2cnt.size() > 2)
            {
               int fruitType2 = fruits[l];
               fruitType2cnt[fruitType2]--;
               if (fruitType2cnt[fruitType2] == 0)
                  fruitType2cnt.erase(fruitType2);
               l++;
            }

            // 不不能是  == 2, 但 <= 2 是可以的, 因为还有 全相等的情 [1, 1, 1,1, 1, 1]
            //if (window == 2)
            {
              maxFruits = max(maxFruits, r - l);
            }
        }

        return maxFruits;
    }
};
/*
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        
        int n = fruits.size();
        int l = 0;
        int r = 0;
        unordered_map<int, int> fruit2cnt;
        int window = 0;

        int maxFruits = 0;
        while (r < n)
        {
            int fruit = fruits[r];
            if (!fruit2cnt.count(fruit))
              window++;
            fruit2cnt[fruit]++;
            r++;

            while (window > 2)
            {
               int fruit2 = fruits[l];
               fruit2cnt[fruit2]--;
               if (fruit2cnt[fruit2] == 0)
               {
                  window--;
                  fruit2cnt.erase(fruit2);
               }
               l++;
            }

            // 不不能是  == 2, 但 <= 2 是可以的, 因为还有 全相等的情 [1, 1, 1,1, 1, 1]
            //if (window == 2)
            {
              maxFruits = max(maxFruits, r - l);
            }
        }

        return maxFruits;
    }
};
*/