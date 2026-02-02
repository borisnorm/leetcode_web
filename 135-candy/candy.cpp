class Solution {
public:
    int candy(vector<int>& ratings) {
        
        if (ratings.empty())
          return 0;

        int n = ratings.size();
        vector<int> candies(n, 1);


        //Children with a higher rating get [more candies] than [their neighbors].
        //                                       +1         +  candy[i-1]      

        //rating 更高的孩子，必须比「相邻的孩子」糖果多
        //这里的“相邻”是 左右两个方向，而不是单向的。
        //left to right
        //右边孩子比左边孩子得分高
        for (int i = 1; i < n; i++)
        {
          if (ratings[i] > ratings[i-1])
            candies[i] = candies[i-1] + 1;  
        }

        //right to left
        //左边孩子比右边孩子得分高
        for (int i = n - 2; i >= 0 ; i--)
        {
            if (ratings[i] > ratings[i+1])
              // 左右 两个方向, 自然是取 最大的那一个
              candies[i] = max(candies[i], candies[i+1] + 1);
        }

        int total = 0;
        for (int cnt : candies)
          total += cnt;

        return total;
    }
};