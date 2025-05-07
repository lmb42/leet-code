#include <iostream>
#include <string>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
private:
    void expad(const string& s, int left, int right, int& start, int& maxLen) {
        int n = s.length();
        while (left >= 0 && right < n && s[left] == s[right]) {
            if (right - left + 1 > maxLen) {
                start = left;
                maxLen = right - left + 1;
            }
            left--;
            right++;
        }
    }

public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";
        int start = 0, maxLen = 1;
        int n = s.length();
        for (int i = 0; i < n; i++) {
            expad(s, i, i, start, maxLen);     // odd
            expad(s, i, i + 1, start, maxLen); // even
        }
        return s.substr(start, maxLen);
    }
};

void runTest(string input, string expected) {
    Solution sol;
    string result = sol.longestPalindrome(input);
    cout << "Input: \"" << input << "\" → Output: \"" << result << "\"" << endl;
    assert(result == expected);
}

int main() {
    // 10 tests
    runTest("cbbd", "bb");
    runTest("babad", "bab"); // or "aba"
    runTest("a", "a");
    runTest("ac", "a"); // or "c"
    runTest("", "");
    runTest("racecar", "racecar");
    runTest("aaaa", "aaaa");
    runTest("abacdfgdcaba", "aba");
    runTest("abcda", "a");
    runTest("forgeeksskeegfor", "geeksskeeg");

    cout << "✅ All 10 tests passed!" << endl;
    return 0;
}
