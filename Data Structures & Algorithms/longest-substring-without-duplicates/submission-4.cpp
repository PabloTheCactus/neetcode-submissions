class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> characters;
        int l = 0;// пойнтер зліва
        int maxLen = 0;
        for(int r = 0; r < s.length(); r++){
            while(characters.find(s[r]) != characters.end()){
                characters.erase(s[l]);//допоки в нас той елемент в сеті, ми видаляємо елементи зліва допоки не видалимо той елемент
                l++;// ну і зсуваємо пойнтер
            }
            characters.insert(s[r]);//нашарюємо
            maxLen = max(maxLen, r - l + 1);
        }
        return maxLen;
    }
};
