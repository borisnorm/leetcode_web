class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();

        vector<int> pre(n+1, 0);
        for (int i = 0; i < n; i++)
          pre[i+1] = pre[i] + cardPoints[i]; 
        
        int maxScore = 0;
        // 左边取 i 右边取 k-i
        for (int i = 0; i <= k; i++)
        {
           int left = pre[i];
           int right = pre[n] - pre[n-(k-i)];
           maxScore = max(maxScore, left + right);
        }

        return maxScore;
    
    }
};