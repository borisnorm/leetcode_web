class Solution {
    public int lengthOfLongestSubstring(String s) {
        if (s.isEmpty())
          return 0;
        
        int n = s.length();

        int l = 0;
        int r = 0;

        HashMap<Character, Integer> char2freq = new HashMap<>();

        int maxLen = 0;
        while (r < n)
        {
           char c = s.charAt(r);
           char2freq.put(c, char2freq.getOrDefault(c, 0)+1);
           r++;

           while (char2freq.get(c) > 1)
           {
              char d = s.charAt(l);
              char2freq.put(d, char2freq.getOrDefault(d, 0)-1);
              l++;
           }

           maxLen = Math.max(maxLen, r - l );

        }

        return maxLen;
    }
}