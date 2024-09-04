class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int min_word_count = get_shortestString(strs);
        bool isComPrefix = true;
        int wordCnt = 0;
        for(int i = 0; i < min_word_count; i++) {
            for(int j = 0; j < strs.size() - 1; j++) {
                if(strs.at(j)[i] != strs.at(j + 1)[i]) {
                    isComPrefix = false;
                    break;
                }
            }
            if(isComPrefix) wordCnt++;
            else break;
        }
        return wordCnt==0 ? "" :strs.at(0).substr(0, wordCnt);
    }

    int get_shortestString(vector<string>& strs) {
        int shortest = strs.at(0).size();
        for(int i = 1; i < strs.size(); i++) {
            if(strs.at(i).size() < shortest) {
                shortest = strs.at(i).size();
            }
        }
        return shortest;
    }
};