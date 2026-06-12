class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> c1;
        unordered_map<char, int> c2;
        int l = 0;
        for (char i : s1) {
            c1[i]++;
        }
        for (int r = 0; r < s2.size(); r++) {
            c2[s2[r]]++;
            if (r - l + 1 == s1.size()) {
                if (c1 == c2) { return true; }
                if (c2[s2[l]] == 1) c2.erase(s2[l]);
                else c2[s2[l]]--;
                l++;
            }
        }
        return false;

    }
};