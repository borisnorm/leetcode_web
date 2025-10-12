class Solution {
public:
    bool backspaceCompare(string s, string t) {
        return build(s) == build(t);
    }

    string build(const string& in)
    {
      string out;

      for (char c : in)
      {
         if (c != '#')
           out.push_back(c);
         else
         {
            if (!out.empty())
              out.pop_back();
         }
      }

      return out;
    }
};