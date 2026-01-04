class Solution {
public:
vector<vector<string>> groupStrings(vector<string>& strings) {
      
      unordered_map<string, vector<string>> groups;
      
      int n = strings.size();
      
      for (string str: strings)
        groups[makeKey(str)].push_back(str);
      
      vector<vector<string>> res;
      for (auto [key, v]: groups)
      {
         sort(v.begin(), v.end());
         res.push_back(v);
      }
      
      return res;
   
}
string makeKey(const string& s)
{
   if (s.empty())
     return "";
    
   int n = s.size();
   int base = s[0] - 'a';
   
   string key;
   for (int i = 0; i < n; i++)
   {
      int diff = (s[i] - 'a' - base + 26) % 26;
      key += to_string(diff);
      key.push_back('#'); 
   }
   
   return key;
}
};