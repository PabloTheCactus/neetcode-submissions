class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        unordered_map<int, int> line1, line2;
        for(int i = 0; i < s.size(); i++){
            line1[(int)s[i]]++;
            line2[(int)t[i]]++;
        }
        if(line1 == line2) return true;
        else return false;
    }
};
