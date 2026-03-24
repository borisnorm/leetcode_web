
class TextEditor {
public:
    string L, R;
    TextEditor() {
        L = "";
        R = "";
    }
    
    void addText(string text) {
        L += text;
    }
    
    int deleteText(int k) {
        int del = min(k, (int)L.size());
        L.resize(L.size()-del);
        return del;
    }
    
    string cursorLeft(int k) {
        while(k && !L.empty())
        {
           R += L.back();
           L.pop_back();
           k--;
        }

        return getLeft();
    }
    
    // 初始化的是 R 是 "", 
    // 初始 Right 为 L: 'abcdefgh' R: ''
    //         变成  L: 'abcde'    R: 'hgf'
    string cursorRight(int k) {
        while (k && !R.empty())
        {
           L += R.back();
           R.pop_back();
           k--;
        }
        return getLeft();
    }

    string getLeft()
    {
      //从光标位置往左最多 10 个字符，不是从 L 的开头
      //                         n - k  = startPos
      int start = max(0, (int)L.size() - 10);
      return L.substr(start);
    }
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */

 /*
 //超时 TLE
 #include <iostream>
#include <stack>
#include <string>
#include <algorithm>

class TextEditor
{
public:
    stack<char> L, R; // 光标左右两侧字符

    TextEditor() {}

    // 在光标位置插入 text，每个字符 push 进 L
    void addText(string text)
    {
        for (char c : text)
            L.push(c);
    }

    // 从光标左侧删除最多 k 个字符，返回实际删除数
    int deleteText(int k)
    {
        int del = 0;
        while (k-- && !L.empty())
        {
            L.pop();
            del++;
        }
        return del;
    }

    // 光标左移 k 步：把 L 的 top 转移到 R
    string cursorLeft(int k)
    {
        while (k-- && !L.empty())
        {
            R.push(L.top());
            L.pop();
        }
        return getLeft(); // 返回光标左侧最多 10 个字符
    }

    // 光标右移 k 步：把 R 的 top 转移到 L
    string cursorRight(int k)
    {
        while (k-- && !R.empty())
        {
            L.push(R.top());
            R.pop();
        }
        return getLeft();
    }

private:
    // 从 L 的栈顶取最多 10 个字符（即光标左侧最近 10 个）
    string getLeft()
    {
        // 把 L 顶部最多 10 个字符倒序放入结果
        string res;
        stack<char> tmp = L; // 复制一份用于读取
        int cnt = min((int)tmp.size(), 10);
        res.resize(cnt);
        for (int i = cnt - 1; i >= 0; i--)
        {
            res[i] = tmp.top(); // 越靠近光标的字符越靠右
            tmp.pop();
        }
        return res;
    }
};
 */