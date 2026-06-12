class Solution {
public:
    int characterReplacement(string s, int k) {
        std::unordered_map<char, int> chars;//для цього тут і стоїть int
        int l = 0;
        int result = 0;
        int mostFrq = 0;
        for (int r = 0; r < s.length(); r++) {
            chars[s[r]]++;// додаємо частоту елемента, він попався нам стількито раз
            mostFrq = max(mostFrq, chars[s[r]]);
            while (r - l + 1 - mostFrq > k) {
                chars[s[l]]--;
                ++l;
            }
            result = max(result, r - l + 1);
        }
        return result;
    }
};