/*
class Solution {
public:
    string reverseWords(string s) {
        if (s.empty())
          return "";
        
        reverse(s.begin(), s.end());
        int n = s.size();

        int i = 0;
        // 目的是reverse 单词, 空格如何跳过 无所谓
        while (i < n)
        {
           while(i < n && s[i] == ' ')
             i++;
           if (i == n)
             break;

           int start = i;
           while(i < n && s[i] != ' ')
            i++;
           int end = i;
           reverse(s.begin()+start, s.begin()+end);
        }

        int slow = 0;
        int fast = 0;
        while(fast < n)
        {
           while (fast < n && s[fast] == ' ')
             fast++;
           if (fast == n)
             break;

           // ' word1', ' word2', 空格+单词, 这样 merge 进去的
           if (slow != 0)
             s[slow++] = ' ';
        
           while (fast < n && s[fast] != ' ')
             s[slow++] = s[fast++];
        }

        s.resize(slow);

        return s;
    }
};

*/
/*
// 有前导0 提前过滤 反转 + 无前导0 写入
class Solution {
public:
    string reverseWords(string s) {
        if (s.empty())
          return "";
        
        int n = s.size();
        reverse(s.begin(), s.end());

        int i  = 0;

        while (i < n && s[i] == ' ')
            i++;

        while (i < n)
        {
          int start = i;
          while (i < n && s[i] != ' ')
            i++;
          int end = i;
          reverse(s.begin()+start, s.begin()+end);
          
          while(i < n && s[i] == ' ')
            i++;
        }

        int slow = 0;
        int fast = 0;
    
        while(fast < n)
        {
           while (fast < n && s[fast] == ' ')
             fast++;
           if (fast == n)
             break;
           
           if (slow != 0)
             s[slow++] = ' ';

           while (fast < n && s[fast] != ' ')
           {
             s[slow++] = s[fast++];
           }
        }

        s.resize(slow);

        return s;
    }
};
*/

// 前导0 提前过滤 反转  + 前导0 提前过滤 写入 slow
class Solution {
public:
    string reverseWords(string s) {
        if (s.empty())
          return "";
        
        int n = s.size();
        reverse(s.begin(), s.end());

        int i  = 0;

        while (i < n && s[i] == ' ')
            i++;
        while (i < n)
        {
          int start = i;
          while (i < n && s[i] != ' ')
            i++;
          int end = i;
          reverse(s.begin()+start, s.begin()+end);
          
          while(i < n && s[i] == ' ')
            i++;
        }

        int slow = 0;
        int fast = 0;
        while (fast < n && s[fast] == ' ')
             fast++;
        while(fast < n)
        {  
           if (slow != 0)
             s[slow++] = ' ';

           while (fast < n && s[fast] != ' ')
             s[slow++] = s[fast++];
           
           while (fast < n && s[fast] == ' ')
             fast++;
        }
        
        s.resize(slow);

        return s;
    }
};


/*
// 无前导 0 处置 + vector<string> 版
class Solution {
public:
    string reverseWords(string s) {
        if (s.empty())
          return "";
        
        int n = s.size();
        int i = 0;
        vector<string> words;
       
        //split and collect words
        while (i < n)
        {
          while (i < n && s[i] == ' ')
            i++;
          if (i == n)
            break;
          
          int start = i;
          while (i < n && s[i] != ' ')
            i++;
          int end = i;
          words.push_back(s.substr(start, end-start));
        }

        //reverse words
        reverse(words.begin(), words.end());

        // contcate words
        string res;
        for (int i = 0; i < words.size(); i++)
        {
            // ' word1', ' word2', 空格+单词, 这样 merge 进去的
            if (i != 0)
              res += ' ';

            res += words[i];
        }

        return res;
    }
};
*/

/*
// 有前导 0 处置 + vector<string> 版
class Solution {
public:
    string reverseWords(string s) {
        if (s.empty())
          return "";
    
        string res;
        vector<string> words;

        int n = (int)s.size();
        int i = 0;

        //前置 leading space ' ', hello 前面的空格
        while (i < n && s[i] == ' ')
          i++;

        while (i < n)
        {
           int start = i;
           while (i < n && s[i] != ' ')
             i++;
           int end = i;
           string word = s.substr(start, end - start);
           words.push_back(word);
           
           //处理 单词间空格 以及 后置 leading space ' ', world 后来的空格
           while (i < n && s[i] == ' ')
            i++;
        }

        reverse(words.begin(), words.end());
        for (int i = 0; i < words.size(); i++)
        {
            if (i > 0)
              res += ' ';

            res += words[i];
        }

        return res;
    }
};
*/