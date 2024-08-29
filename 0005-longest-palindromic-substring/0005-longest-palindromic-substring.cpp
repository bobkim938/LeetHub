class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.length();
        bool isPalindrome = false;
        int palindromeLength = 1;
        string result;
        for(int i = 0; i < len; i++) {
            for(int j = i; j < len; j++) {
                if(s[i] == s[j]) {
                    int x = i;
                    int y = j;
                    while(y - x > 0) {
                        if(s[++x] != s[--y]) {
                            isPalindrome = false;
                            break;
                        }
                        else {
                            isPalindrome = true;
                        }
                    }
                    if(isPalindrome && (j - i + 1) > palindromeLength) {
                        palindromeLength = j - i + 1;
                        result = s.substr(i, palindromeLength);
                        isPalindrome = false;
                    }
                }
            }
        }
        if(palindromeLength == 1) {
            return s.substr(0, 1);
        }
        return result;
    }
};