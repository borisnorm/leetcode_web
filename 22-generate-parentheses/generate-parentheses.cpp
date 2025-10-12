class Solution {
public:
    vector<string> res;
    string track;
    vector<string> generateParenthesis(int n) {
         if (n <= 0)
           return res;
         
         int left = n;
         int right = n;
         
         backtrack(left, right);
         
         return res;
    }

    void backtrack(int left, int right)
    {
        if (right < left)
          return;

        if (right < 0)
          return;
         
        if (left == 0 && right == 0)
        {
            res.push_back(track);
            return;
        }

        if (left > 0)
        {
            track.push_back('(');
            backtrack(left-1, right);
            track.pop_back();
        }

        if (right > left)
        {
           track.push_back(')');
           backtrack(left, right-1);
           track.pop_back(); 
        }
    }
};