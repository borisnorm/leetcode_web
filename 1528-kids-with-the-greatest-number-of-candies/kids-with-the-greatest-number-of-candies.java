class Solution {
    public List<Boolean> kidsWithCandies(int[] candies, int extraCandies) {
        
        int n = candies.length;
        int maxCandy = 0;

        for (int c: candies)
          maxCandy = Math.max(maxCandy, c);
 
        List<Boolean> res = new ArrayList<>(n);
        for (int i = 0; i < n; i++)
          res.add((candies[i] + extraCandies) >= maxCandy ? true: false);
        
        return res;
          
    }
}