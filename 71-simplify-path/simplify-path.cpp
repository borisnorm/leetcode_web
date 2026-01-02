class Solution {
public:
    string simplifyPath(string path) {
        vector<string> st;
        string token;
        stringstream ss(path);

        while(getline(ss, token, '/'))
        {
           if (token == "" || token == ".")
             continue;
           
           if (token == "..")
           {
              if (!st.empty())
                st.pop_back();
           }
           else
             st.push_back(token);
        }

        if (st.empty())
          return "/";
        
        string res;
        for (string &dir : st)
          res += "/" + dir;
        
        return res;
    }
};