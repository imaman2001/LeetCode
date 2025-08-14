class Solution {
public:
    string largestGoodInteger(string num) {
        int count = 0;
        char current = '\0';
        int maxDigit = -1;

        for (char c : num) {
            if (c == current) {
                count++;
                if (count == 3 && (c - '0') > maxDigit) {
                    maxDigit = c - '0';
                }
            } else {
                current = c;
                count = 1;
            }
        }

        return maxDigit < 0 ? "" : string(3, '0' + maxDigit);
    }
};
