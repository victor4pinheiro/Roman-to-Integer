#include <iostream>
using namespace std;

struct RomanValues
{
    char key;
    int value;
};

class Solution
{
public:
    int romanToInt(string s)
    {
        int result = 0;
        RomanValues values[7] = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == 'I' && s[i + 1] == 'V') {
                result += 4;
                i += 1;
            } else if (s[i] == 'I' && s[i + 1] == 'X') {
                result += 9;
                i += 1;
            } else if (s[i] == 'X' && s[i + 1] == 'L') {
                result += 40;
                i += 1;
            } else if (s[i] == 'X' && s[i + 1] == 'C') {
                result += 90;
                i += 1;
            } else if (s[i] == 'C' && s[i + 1] == 'D') {
                result += 400;
                i += 1;
            } else if (s[i] == 'C' && s[i + 1] == 'M') {
                result += 900;
                i += 1;
            } else {
                for (RomanValues number: values) {
                    if (s[i] == number.key) {
                        result += number.value;
                    }
                }
            }
        }
        
        return result;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;

    cout << solution.romanToInt("LVIII") << "\n";
    return 0;
}