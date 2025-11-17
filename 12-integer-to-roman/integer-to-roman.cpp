class Solution {
public:
    string intToRoman(int num) {
        vector<pair<int, string>> roman_str = 
        {
          {1, "I"},{5, "V"},{10, "X"},{50, "L"},
          {100, "C"},{500, "D"}, {1000, "M"},
          {4, "IV"}, {9, "IX"}, 
          {40, "XL"}, {90, "XC"},
          {400, "CD"}, {900, "CM"}
         };

          string res;
          sort(roman_str.rbegin(), roman_str.rend());
          for (auto& it: roman_str)
            {
              while (num >= it.first)
              {
                num -= it.first;
                res += it.second;
              }
            }
            
           return res;
    }
};