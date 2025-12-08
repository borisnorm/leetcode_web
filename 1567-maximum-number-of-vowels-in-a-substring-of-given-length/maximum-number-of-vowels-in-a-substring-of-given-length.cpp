class Solution {
public:
    int maxVowels(string s, int k) {
        
        int n = s.size();
        int l = 0;
        int r = 0;
        int ans = 0;
        int cnt_vowel = 0;
        while (r < n)
        {
           if (isVowel(s[r]))
             cnt_vowel++;
           r++;

           while (r - l > k)
           {
              if (isVowel(s[l]))
                cnt_vowel--;
              l++;
           }

           ans = max(ans, cnt_vowel);
        }

        return ans;
    }

    bool isVowel(char c)
    {
       if (c == 'a' || c == 'e' || c == 'i' || c =='o' || c == 'u')
         return true;
       
       return false;
    }
};