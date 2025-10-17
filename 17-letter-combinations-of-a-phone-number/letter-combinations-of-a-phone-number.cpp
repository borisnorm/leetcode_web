class Solution {
public:

    unordered_map<char, string> mp={
          {'2', "abc"}, {'3',"def"}, {'4',"ghi"}, {'5', "jkl"},
          {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}
       };

    vector<string> res;
    string track;

    vector<string> letterCombinations(string digits) {
        if (digits.empty())
          return res;
        backtrack(digits, 0);
        return res;
    }

    void backtrack(string digits, int start)
    {
        if (track.size() == digits.size())
        {
          res.push_back(track);
          return;
        }

        char digit = digits[start];
        for (char c : mp[digit])
        {
            track.push_back(c);
            backtrack(digits, start+1);
            track.pop_back();
        }
    }
};