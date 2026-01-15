class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        if (s.empty())
          return 0;
 
        int n = s.size();

        int left = 0;
        int right = 0;

        // 使用 char c 作为index 也是可以的
        //int char2freq[128] = {0};
          int window[128] = {0};
        //unordered_map<char, int> window;

        int maxLen = 0;
        while (right < s.size())
        {
            char c = s[right];
            right++;
            window[c]++;

            while (window[c] > 1)
            {
              char d = s[left];
              left++;
              window[d]--;
            }

            maxLen = max(maxLen, right-left);
        }
        return maxLen;
    }
};