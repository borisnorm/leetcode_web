class Solution {
public:

   int hIndex(vector<int>& citations) {
      int n = citations.size();
      
      vector<int> cnt(n+1, 0);

      for (int c: citations)
      {
          if (c >= n)
            cnt[n]++;
          else
            cnt[c]++;
      }


      int published_papers = 0;
      for (int h = n; h >= 0; h--)
      {   
        published_papers += cnt[h];
        if (published_papers >= h)
          return h; 
      }

      return 0;
  }
    /*
    int hIndex(vector<int>& citations) {
        if (citations.empty())
          return 0;

        int n = citations.size();

        sort(citations.begin(), citations.end());

        int h = 0;
        for (int i = 0; i < n; i++)
        {
           //citations[i] ≤ citations[i+1] ≤ ... ≤ citations[n-1]
           //这 n-i 篇论文中，最少的引用数 = citations[i]
           //n表示发的 paper 的总数量, i 是当前 paper,  n-1 - i + 1 = n - i;
           int published_h_papers = n - i;  
           if (citations[i] >= published_h_papers)
             h = max(h, published_h_papers);
        }

        return h;
    }
    */
};