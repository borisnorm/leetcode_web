class Solution {
public:
    int longestSubstring(string s, int k) {
         // >= k  < k 作为边界
        int n = s.size();
        // [l, r)
        return dfs(s, 0, n, k);
    }

    int dfs(const string& s, int l, int r, int k)
    {
         if (r - l < k)
           return 0;
         
         int freq[26] = {};
         for (int i = l; i < r; i++)
           freq[s[i]-'a']++;
       
        for (int i = l; i < r; i++)
        {
            if (freq[s[i]-'a'] < k)
            {
               //不包括 s[i]这个位置
               int mid = i + 1;
               while (mid < r && freq[s[mid]-'a'] < k)
                  mid++;

               int left = dfs(s, l, i, k);
               int right = dfs(s, mid, r, k);
               return max(left, right);
            }
        }

        // 没有分割点 → [l, r) 整段满足条件 
        return r-l;
    }
};