class Solution {
public:

    string encode(vector<string>& strs) {
        string estr;
        for(auto i : strs){
            estr.append(std::to_string(i.length()) + '#' + i);
        }
        return estr;
    }

    vector<string> decode(string s) {
        vector<string> dstrs; // Має бути вектор рядків, а не цілих чисел
        int i = 0;

        while (i < s.length()) {
            // Знаходимо позицію символа '#'
            int sharp_pos = s.find('#', i);

            // Отримуємо довжину рядка (це все до '#')
            int len = stoi(s.substr(i, sharp_pos - i));

            // Отримуємо сам рядок за довжиною len
            string decoded_str = s.substr(sharp_pos + 1, len);

            // Додаємо розкодовний рядок до вектора
            dstrs.push_back(decoded_str);

            // Оновлюємо індекс i: рухаємося далі на позицію після цього рядка
            i = sharp_pos + 1 + len;
        }
        return dstrs;
    }
};
