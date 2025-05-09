class Solution {
    public:
        vector<string> letterCombinations(string digits) {
            vector<string> letter = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}; 
            vector<string> output;
            vector<int> index(digits.size(), 0);
            int n = digits.size(); // length of the digits
            if(n == 1) {
                for(int i = 0; i < letter[digits[0] - '0' - 2].size(); i++) {
                    output.push_back(string(1, letter[digits[0] - '0' - 2][i]));
                }
                return output;
            }
            int cntrl = 0;
            while(!digits.empty()) {
                string tmp = "";
                cntrl = 0;
                for(int i = 0; i < n; i++) {
                    tmp += letter[digits[i] - '0' - 2][index[cntrl++]]; 
                }
                index[--cntrl]++; 
                if(index[cntrl] == letter[digits[n - 1] - '0' - 2].size()) {
                    for(int j = n-1; j > 0; j--) {
                        if(index[j] == letter[digits[j] - '0' - 2].size()) {
                            index[j] = 0;
                            index[j-1]++;
                        }
                    }
                }
                output.push_back(tmp);
                if(index[0] == letter[digits[0]-'0'-2].size()) break;
            }
            return output;
        }
};