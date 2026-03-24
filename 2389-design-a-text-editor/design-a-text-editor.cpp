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
    
    // 初始 Right 为 L: 'abcde' R: 'hgf'
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