class Solution {
public:
    string convert(string s, int numRows) {
        //  a
        //  b
        //  c
        //  还是读 abc 没变

        if (numRows <= 1 || (int)s.size() <= numRows)
          return s;
        
        vector<string> rows(numRows);

        // index with direction
        int curRow = 0;
        bool down = false;

        for (char c: s)
        {
           rows[curRow].push_back(c);

           //idx 更新 with 方向检测, 触底翻转
           if (curRow == 0 || curRow == numRows - 1)
              down = !down;
           curRow += down ? 1 : -1;
        }

        string res;
        for (string row: rows)
          res += row;
        
        return res;
    }
};