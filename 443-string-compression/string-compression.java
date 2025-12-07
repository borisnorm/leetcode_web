class Solution {
    public int compress(char[] chars) {
        
        int n = chars.length;

        int cnt = 1;
        char c = chars[0];
        int write = 0;

        for (int i = 1; i <= n; i++)
        {
            if((i == n) || chars[i] != chars[i-1])
            {
               c = chars[i-1];
               chars[write++] = c;

               if (cnt > 1)
               {
                  String cntString = String.valueOf(cnt);
                  for (char d: cntString.toCharArray())
                    chars[write++] = d;
               }

               cnt = 1;
            }
            else
              cnt++;
        }

        return write;

    }
}