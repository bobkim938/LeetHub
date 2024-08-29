class Solution {
public:
    int reverse(int x) {
        bool isNegative = x < 0 ? 1 : 0;
        string temp = to_string(x);
        string result;
        int size = temp.length();
        for(int i = size - 1; i >= 0; i--) {
            result.push_back(temp[i]);
        }
        try {
            int reversed = isNegative ? stoi(result) * -1 : stoi(result);
            return reversed;
        } catch (out_of_range& e) {
            return 0;
        }
    }
};