class Solution {
public:
    int res = 0;
    int maxLength(vector<string>& arr) {
        
        int n = arr.size();
        vector<int> masks;
        vector<int> lens;

        for(string str: arr)
        {
          // single words duplicates check
          bool dup = false;
          int wordMask = 0;
          for (char c: str)
          {
             int mask = 1 << (c-'a');
             if ((wordMask & mask) != 0)
             {
                dup = true;
                break;
             }
             wordMask |= mask;
          }

          if (!dup)
          {
             masks.push_back(wordMask);
             lens.push_back(str.size());
          }

        }

        int maxLen = 0;
        int curMask = 0;
        int curLen = 0;
        int idx = 0;
        dfs(masks, idx, curMask, curLen, lens, maxLen);
        return maxLen;
    }

    void dfs(vector<int>& masks, int idx, int curMask, int curLen, vector<int>& lens, int& maxLen)
    {
        maxLen = max(maxLen, curLen);

        if (idx == masks.size())
          return;

        for (int i = idx; i < masks.size(); i++)
        {
           if ((curMask & masks[i]) == 0)
             dfs(masks, i+1, curMask | masks[i], curLen + lens[i], lens, maxLen);
        }
    }
};
/*
class Solution {
public:
    int res = 0;
    int maxLength(vector<string>& arr) {
        
        int n = arr.size();
        vector<int> masks;

        for(string str: arr)
        {
          // single words duplicates check
          bool dup = false;
          int wordMask = 0;
          for (char c: str)
          {
             int mask = 1 << (c-'a');
             if ((wordMask & mask) != 0)
             {
                dup = true;
                break;
             }
             wordMask |= mask;
          }

          if (!dup)
             masks.push_back(wordMask);

        }

        int maxLen = 0;
        int curMask = 0;
        int idx = 0;
        dfs(masks, idx, curMask, maxLen);
        return maxLen;
    }

    void dfs(vector<int>& masks, int idx, int curMask, int& maxLen)
    {
        maxLen = max(maxLen, __builtin_popcount(curMask));

        if (idx == masks.size())
          return;

        for (int i = idx; i < masks.size(); i++)
        {
           if ((curMask & masks[i]) == 0)
             dfs(masks, i+1, curMask | masks[i], maxLen);
        }
    }
};
*/