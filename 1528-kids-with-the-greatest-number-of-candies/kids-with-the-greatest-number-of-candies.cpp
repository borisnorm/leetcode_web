class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
         auto it = max_element(candies.begin(), candies.end());
         int maxCandy = *it;

         int n = candies.size();
         vector<bool> res(n);

         for (int i = 0; i < n; i++)
           res[i] = (candies[i] + extraCandies) >= maxCandy ? true : false;

        
        return res;
    }
};