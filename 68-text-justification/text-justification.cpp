class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        if (words.empty() || maxWidth <= 0)
          return {};

        int n = words.size();
        vector<string> res;

        int i = 0;
        while (i < n)
        {

            int j = i;
            int sumLen = 0;

            while (j < n)
            {
                int newLen = sumLen + (j - i) + words[j].size();
                if (newLen > maxWidth)
                  break;
                sumLen += words[j].size();
                j++;
            }

            int wordCount = j - i;
            bool isLastLine = (j == n);
            string line;

            if (isLastLine || wordCount == 1)
            {
                line = words[i];
                for (int k = i + 1; k < j; k++)
                  line += " " + words[k];
                line.append(maxWidth - line.size(), ' ');   
            }
            else
            {
                int gaps = wordCount - 1;
                int totalSpaces = maxWidth - sumLen;
                int spaceEach = totalSpaces / gaps;
                int extra = totalSpaces % gaps;

                for (int k = i; k < j; k++)
                {
                   line += words[k];

                   if (k == j -1 )
                     break;
                    
                    int spaces = spaceEach + ((k-i) < extra ? 1: 0);
                    line.append(spaces, ' ');
                }
            }

            res.push_back(line);
            i = j;

        }
        
        return res;

        
    }
};