class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        // judge-->trust->nobody
        // everyone-->truxt -> judge;

        vector<int> inDegree(n+1, 0);
        vector<int> outDegree(n+1, 0);

        for(auto relation: trust)
        {
            int a = relation[0];
            int b = relation[1];
            
            inDegree[b]++;
            outDegree[a]++;
        }

        int cnt = 0;

        int judge = 0;
        for (int i = 1; i <= n; i++)
        {
            if (outDegree[i] == 0 && inDegree[i] == (n-1))
            {
               judge = i;
               cnt++;
            }
        }

        return cnt == 1 ? judge : -1;
    }
};