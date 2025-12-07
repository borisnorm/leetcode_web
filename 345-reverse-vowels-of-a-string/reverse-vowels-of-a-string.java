class Solution {
    public String reverseVowels(String s) {
        int n = s.length();
        int l = 0;
        int r = n - 1;
       
        char[] arr = s.toCharArray();
        Set<Character> vowels_set = new HashSet<>(Set.of('a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'));

        while (l < r)
        {
           while (l < r && !vowels_set.contains(s.charAt(l)))
             l++;

           while (l < r && !vowels_set.contains(s.charAt(r)))
             r--;

            if (l < r)
            {
               char t = arr[l];
               arr[l] = arr[r];
               arr[r] = t;

               l++;
               r--;
            }
        }
        return new String(arr);
    }
}