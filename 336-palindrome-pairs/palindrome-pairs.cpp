class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        int n = words.size();

        vector<vector<int>> res;
        unordered_map<string, int> word2idx;
        for (int i = 0; i < n ; i++)
          word2idx[words[i]] = i;

        for (int i = 0; i < n; i++)
        {
           string& word = words[i];

           int len = word.size();
           
           for (int cut = 0; cut <= len; cut++)
           {
              // left is pal,  reverse(right) + left + right
              if (isPal(word, 0, cut-1))
              {
                 string right = word.substr(cut);
                 string revRight = reverseStr(right);

                 if (word2idx.count(revRight) && word2idx[revRight] != i)
                 {
                    res.push_back({word2idx[revRight], i});
                 } 
              }

              // right is pal, left + right + reverse(left)
              // 当 cut == len 时： 所以需要 添加 cur < len
              //right = ""
              //空串本身也是回文。
              //所以如果第二个分支也照常做，会和别的切分重复。
              if (cut < len &&  isPal(word, cut, len-1))
              {
                 string left = word.substr(0, cut);
                 string revLeft = reverseStr(left);

                 if (word2idx.count(revLeft) && word2idx[revLeft] != i)
                 {
                    //如果 right 是回文，那么只需要后面补上 reverse(left)：
                    //left + right + reverse(left)
                    // 所以此时答案应该是：
                    //[ i, index(reverse(left)) ]
                    res.push_back({i, word2idx[revLeft]});
                 }
              }
           }
        }
        return res;
    }

    string reverseStr(const string& s)
    {
        string t = s;
        reverse(t.begin(), t.end());
        return t;
    }

    bool isPal(const string& s, int l, int r)
    {
       while (l < r)
       {
          if (s[l] != s[r])
            return false;
          
          l++;
          r--;
       }
       return true;
    }
};