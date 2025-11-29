class Solution {
public:
    int totalMoney(int n) {
        // Tue: +1
        // Wen: +1+1
        // Suny +6

        // 1 + 2 +3

        int base = 1;
        int sum = 0;
        int addon = 0;
        for (int i = 1; i <= n; i++)
        {
            sum += base + addon;
            addon++;

            if (i%7 == 0)
            {
              base++;
              addon = 0;
            }
        }

        return sum;
    }
};