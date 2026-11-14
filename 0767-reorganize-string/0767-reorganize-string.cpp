class Solution {
public:
    string reorganizeString(string str) {
        int hash[26] = {0};

        for (int i = 0; i < str.length(); i++) {
            hash[str[i] - 'a']++;
        }

        int max = 0, letter = 0;
        for (int i = 0; i < 26; i++) {
            if (hash[i] > max) {
                max = hash[i];
                letter = i;
            }
        }
        if (max > (str.length() + 1) / 2) {
            return "";
        }
        string res(str.length(), ' ');

        int idx = 0;
        while (hash[letter] > 0) {
            res[idx] = char(letter + 'a');
            idx += 2;
            hash[letter]--;
        }

        for (int i = 0; i < 26; i++) {
            while (hash[i] > 0) {
                if (idx >= res.length()) {
                    idx = 1;
                }
                res[idx] = char(i + 'a');
                idx += 2;
                hash[i]--;
            }
        }

        return res;
    }
};