class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> charContainer(26,0);
        for(int i = 0;i < magazine.size();i++){
            charContainer[magazine[i]-'a']++;
        }

        for(int i = 0;i < ransomNote.size();i++){
            if(charContainer[ransomNote[i]-'a'] == 0){
                return false;
            }
            charContainer[ransomNote[i]-'a']--;
        }
        return true;
    }
};