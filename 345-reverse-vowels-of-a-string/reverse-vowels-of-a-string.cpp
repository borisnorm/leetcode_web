class Solution {
public:
    string reverseVowels(string s) {
        unordered_set<char> vowels_set = {'a', 'e', 'i', 'o','u', 'A', 'E', 'I', 'O', 'U'};

        int n = s.size();

        int l = 0;
        int r = n - 1;

        while (l < r)
        {
           while (l < r && !vowels_set.count(s[l]))
             l++;

           while (l < r && !vowels_set.count(s[r]))
             r--;

           if (l < r)
           {
              swap(s[l], s[r]);
              l++;
              r--;
           }

        }

       return s;
    }
};
 