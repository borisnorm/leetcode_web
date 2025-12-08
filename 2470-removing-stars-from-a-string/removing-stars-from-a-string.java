class Solution {
    public String removeStars(String s) {
        StringBuilder sb = new StringBuilder();
        char[] str = s.toCharArray();
 
        for (int i = 0; i < s.length(); i++)
        {
           if (str[i] == '*')
           {
              if (!sb.isEmpty())
              {
                  int lastPos = sb.length() - 1;
                  sb.deleteCharAt(lastPos);
              }
           }
           else
             sb.append(str[i]);
        }

        return sb.toString();
    }
}