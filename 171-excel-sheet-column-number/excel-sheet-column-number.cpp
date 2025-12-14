class Solution {
public:
    int titleToNumber(string columnTitle) {
        if (columnTitle.empty())
          return 0;

        int n = columnTitle.size();

        long long sum = 0;
        for (int i = 0; i < n; i++)
        {
           int digit = columnTitle[i] - 'A' + 1;
           sum = sum * 26 + digit;           
        }

        return static_cast<int>(sum);
    }
};