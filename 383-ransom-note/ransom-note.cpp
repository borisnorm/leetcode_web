class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        // magazine -> ransomNote 
        unordered_map<char, int> magazine_map;
        for (int i = 0; i < magazine.length(); i++)
          magazine_map[magazine[i]]++;

        for (auto c: ransomNote)
        {
            magazine_map[c]--;
            if (magazine_map[c] < 0)
              return false;
        } 

        return true;
        
    }
};