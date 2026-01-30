class Solution {
public:

   string reverseStr(string s, int k) {
      
      int n = s.size();
      if (n == 0)
        return s;
      
      for (int i = 0; i < n; i+= 2*k)
      {
         int l = i;

        //[l, r]
         //正常应该是 i+k 的,但题目要求 fewer k characters left, reverse all of them;
         int r = min(i + k-1, n-1);
        
         //reverse(s.begin() + l, s.begin()+r);
         reverseSubstr(s, l, r);
         
      }

      return s;
}

  void reverseSubstr(string& s, int l, int r)
  {
      if (l > r)
        return;
      //[l, r]
      while(l < r)
      {
        swap(s[l], s[r]);
        l++;
        r--;
      }
  }

/*
class Solution {
public:

   string reverseStr(string s, int k) {
      
      int n = s.size();
      if (n == 0)
        return s;
      
      for (int i = 0; i < n; i+= 2*k)
      {
         int l = i;

         //正常应该是 i+k 的,但题目要求 fewer k characters left, reverse all of them;
         //[l, r)
         int r = min(i + k, n);
        
         reverse(s.begin() + l, s.begin()+r);         
      }

      return s;
}
*/

/*
    正确
    string reverseStr(string s, int k) {
        
        int n = s.size();
        if (n == 0 || k == 0)
          return s;

    
        //if (n < k)
        //{
        //  reverse(s.begin(), s.end());
        //  return s;
       // }
    

        bool isReversed = false;
        for (int i = 0; i < n; i+=k)
        {
            if (!isReversed)
            {
               if (i + k - 1 < n)
               {
                 reverse(s.begin()+i, s.begin()+i+k);
               }
               else
               {
                 reverse(s.begin()+i, s.end());
               }
               isReversed = true;
            }
            else
            {
               isReversed = false;
            }
        }

        return s;
    }
    
    */
};