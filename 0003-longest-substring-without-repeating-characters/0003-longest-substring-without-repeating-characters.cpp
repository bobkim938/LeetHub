class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int cnt = 0;
        int ans = 0;
        int j = 0;
        unordered_set<char> charSet; 

        for (int i = 0; i < s.length(); i++) {
            while (charSet.count(s[i]) > 0) {
                charSet.erase(s[j]);
                j++;
                cnt--;
            }

            charSet.insert(s[i]);
            cnt++;
            ans = max(ans, cnt);
        }

        return ans;
    }
};