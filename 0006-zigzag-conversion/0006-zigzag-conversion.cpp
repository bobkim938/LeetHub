class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1 || numRows >= s.length()) {
            return s;
        }
        string result;
        int zigzag_cnt = 0;
        bool ascending = true;
        for(int i = 0; i < numRows; i++) {
            for(int j = 0; j < s.length(); j++) {
                if(zigzag_cnt == i) {
                    result.push_back(s[j]);
                }
                if(zigzag_cnt == numRows - 1) {
                    ascending = false;
                }
                else if(zigzag_cnt == 0) {
                    ascending = true;
                }
                if(ascending) {
                    zigzag_cnt++;
                }
                else {
                    zigzag_cnt--;
                }
            }
            zigzag_cnt = 0;
        }
        return result;
    }
};