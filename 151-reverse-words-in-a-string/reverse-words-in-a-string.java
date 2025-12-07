class Solution {
    public String reverseWords(String s) {


        int i = 0;
        /*
        while (i < n && s.charAt(i) == ' ')
          i++;
        if (i == n)
          return res;
        */
        s = s.trim();
        int n = s.length();
        StringBuilder sb   = new StringBuilder();
        List<String> words = new ArrayList<String>();

        
        while (i < n)
        {
          int start = i;
          while (i < n && s.charAt(i) != ' ')
            i++;
          int end = i;
          String word = s.substring(start, end);
          
          words.add(word);

          while (i < n && s.charAt(i) == ' ')
            i++;
        }

        for (int k = words.size() - 1; k >= 0; k--)
        {
           if (sb.length() > 0)
             sb.append(' ');
           
           sb.append(words.get(k));
        }
        
        return sb.toString();
    }
}