
class Solution {
public:
    vector<string> digit2letter = {
            "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
        };
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        string letter;
        backtrack(digits, 0, letter, res);
        return res;
    }
    
    void backtrack(string digits, int start, string& letter, vector<string>& res)
    {
        if (letter.size() == digits.size())
        {
            res.push_back(letter);
            return;
        }

        int digit_idx = digits[start] - '0';
        string letter_comb = digit2letter[digit_idx];

        for (int i = 0; i < letter_comb.size(); i++)
        {
            letter.push_back(letter_comb[i]);
            backtrack(digits, start+1, letter, res);
            letter.pop_back();
        }

    }

};

/*

class Solution {
public:

    unordered_map<char, string> digit2letter ={
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
        for (char c : digit2letter[digit])
        {
            track.push_back(c);
            backtrack(digits, start+1);
            track.pop_back();
        }
    }
};

*/