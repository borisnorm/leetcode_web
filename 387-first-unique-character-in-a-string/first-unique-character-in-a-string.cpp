class Solution {
public:
    int firstUniqChar(string s) {
        
        int n = s.size();
        unordered_map<char, int> char2freq;
        int slow = 0;
        for (auto& c: s)
           char2freq[c]++;

        for (int i = 0; i < n; i++)
        {
           if (char2freq[s[i]] == 1)
             return i;
        }

        return -1;
    }
};