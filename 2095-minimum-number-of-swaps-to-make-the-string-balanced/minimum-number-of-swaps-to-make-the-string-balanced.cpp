class Solution {
public:
    int minSwaps(string s) {
        
        int n = s.size();
        int balance = 0;
        int nSwaps = 0;
        int minSwaps = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '[')
              balance++;
            else
              balance--;
            
            minSwaps = min(minSwaps, balance);
        }

        return (abs(minSwaps) + 1)/2;
    }
};