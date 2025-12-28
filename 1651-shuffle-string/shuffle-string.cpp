class Solution {
public:

    string restoreString(string s, vector<int>& indices) {
          int n = s.size();
          string shuffled_str(n, ' ');
          
          for (int i = 0 ; i < n; i++)
          {
              shuffled_str[indices[i]] = s[i];
          }
          return shuffled_str;

    }
  /*
    string restoreString(string s, vector<int>& indices) {
        
          unordered_map<int, char> idx2char;
 
          int n = s.size();
          vector<char> s2(n);
          for (int i = 0; i < n; i++)
          {
             s2[indices[i]] = s[i];
          }

          string shuffled_str;
          for (int i = 0; i < n; i++)
            shuffled_str += s2[i];
        
          return shuffled_str;
    }

    */
};