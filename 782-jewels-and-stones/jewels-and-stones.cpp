class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        vector<int> stonefreq(128, 0);

        for (char c: stones)
          stonefreq[c-'A']++;

        int stoneCnt = 0;
        for (char c: jewels)
        {
           if (stonefreq[c-'A'] > 0)
              stoneCnt += stonefreq[c-'A'];
        }

        return stoneCnt;

    }
};