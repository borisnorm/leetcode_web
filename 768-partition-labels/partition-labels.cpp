class Solution {
public:
    vector<int> partitionLabels(string s) {
        if (s.empty())
           return {};

        int n = static_cast<int>(s.size());
        vector<int> lastPos(128, -1);
      
        vector<int> res;

        for (int i = 0; i < n; i++)
          lastPos[s[i]-'a'] = i;

        int end = INT_MIN;
        int start = 0;
        for (int i = 0; i < n; i++)
        {
          end = max(end, lastPos[s[i]-'a']); 

          if (i == end)
          {
             int len = end - start + 1;
             res.push_back(len);
             start = i + 1;
          }
        }

        return res;
        


    }
};