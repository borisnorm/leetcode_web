class Solution {
public:
    bool isNumber(string s) {

        // + / - 号 只能出现在两个位置
        //1.字符串最开头
        //2.紧跟在 e 或 E 后面

        // .
        // 1.（小数点）只能出现一次，
        // 2.只能出现在指数 e/E 之前。


        // e/E
        // 1. 只能出现1次
        // 2. 前面必须有数字
        // 3. e 后面必须有数字, seenDigit 重置

        // ' '
        // 1. 错误的想法: 前面不能有任何动 . e/E, digit ,  前面可以有, 
        //   "  3.14  " " -2e10"
        // 1.正确的:  [合法数字部分][空格][后缀] 一旦在“数字解析过程中”遇到空格： 后面只能再有空格，不能再出现任何有效字符。
         // 空格只允许出现在：
        // 开头（leading spaces） 程序一开始就处理了
        // 结尾（trailing spaces） 


        //digit
        //isdigit 判定,

        int n = s.size();

        int i = 0;
        while (i < n && s[i] == ' ')
          i++;
        
        bool isDigitSeen = false;
        bool isExpSeen = false;
        bool isDotSeen = false;

        while (i < n)
        {
           char c = s[i];
        
           if (isdigit(c))
           {
             isDigitSeen = true;
           }
           else if (c == '+' || c == '-')
           {
              if (! (i == 0 || (s[i-1] == 'E' || s[i-1] == 'e')))
                return false;
           }
           else if (c == '.')
           {  
              if (isDotSeen || isExpSeen)
                return false;
            
              isDotSeen =  true;
   
           }
           else if (c == 'E' || c == 'e')
           {
               if (isExpSeen || !isDigitSeen)
                 return false;
                
               isExpSeen = true;
               isDigitSeen = false;
           }
           else  if (c == ' ')
           {
                 while (i < n && s[i] == ' ')
                   i++;

                 return  i == n && isDigitSeen;
           }
           else
           {
             return false;
           }
           i++;
        }

        return isDigitSeen;

    }
};