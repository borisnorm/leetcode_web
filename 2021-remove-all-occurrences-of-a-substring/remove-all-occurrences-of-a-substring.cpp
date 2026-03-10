class Solution {
public:
    string removeOccurrences(string s, string part) {
         if (s.empty() || part.empty())
           return s;
        
         int n = s.size();
         int m = part.size();

         while (s.find(part) != string::npos)
         {
            int pos = s.find(part);

            s.erase(pos, m);
         }

         return s;
    }
};