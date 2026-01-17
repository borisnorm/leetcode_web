class Solution {
public:
    int maxFreqSum(string s) {
        

        int freq[26] = {0};
        int maxVowel = 0;
        int maxConsonant = 0;
        for (char c : s)
        {
           if (c == 'a' || c == 'e' || c == 'i' || c =='o' || c == 'u')
           {
              freq[c-'a']++;
              maxVowel = max(maxVowel, freq[c-'a']);
           }
           else
           {
              freq[c-'a']++;
              maxConsonant = max(maxConsonant, freq[c-'a']);
           }
        }

        return maxVowel + maxConsonant;

    }
};