class Solution {
public:
    int hIndex(vector<int>& citations) {
        

        int n = citations.size();
        int h = 0;
        for (int i = 0; i < n; i++)
        {
            int papers = n - i;
            if (papers <= citations[i])
              h = max(h, papers);
        }

        return h;
    }
};