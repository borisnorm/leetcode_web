class Solution {
    public boolean closeStrings(String word1, String word2) {
        
        int[] word1_char_freq = new int[26];
        int[] word2_char_freq = new int[26];

        for (char c : word1.toCharArray())
          word1_char_freq[c-'a']++;

        for (char c : word2.toCharArray())
          word2_char_freq[c-'a']++;

        for (int i = 0; i < 26; i++)
        {
            boolean isCharInWord1 = word1_char_freq[i] > 0 ? true : false;
            boolean isCharInWord2 = word2_char_freq[i] > 0 ? true : false;

            if (isCharInWord1 != isCharInWord2)
              return false;
         }

         Arrays.sort(word1_char_freq);
         Arrays.sort(word2_char_freq);

         for (int i = 0; i < 26; i++)
         {
            if (word1_char_freq[i] != word2_char_freq[i])
              return false;
         }

         return true;
     }
}