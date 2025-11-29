class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> cntS(26, 0);
        vector<int> cntT(26, 0);

        for (auto& c : s)
          cntS[c-'a']++;

        for (auto& c: t)
          cntT[c-'a']++;

        int steps = 0;
        for (int i = 0; i < 26; i++)
          if (cntS[i] > cntT[i])
             steps += cntS[i] - cntT[i];
        
        return steps;
    }
};