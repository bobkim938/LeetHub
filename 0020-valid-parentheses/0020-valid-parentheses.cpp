class Solution {
public:
    bool isValid(string s) {
        stack <char> tmp;
        if(s.length()%2 != 0) return false;
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == '(' || s[i] == '{' || s[i] =='[') {
                tmp.push(s[i]);
            }
            else {
                if(!tmp.empty() && s[i] == ')' && tmp.top() == '(') tmp.pop();
                else if(!tmp.empty() && s[i] == ']' && tmp.top() == '[') tmp.pop();
                else if(!tmp.empty() && s[i] == '}' && tmp.top() == '{') tmp.pop();
                else return false;
            }
        } 
        if(tmp.empty()) return true;
        return false;
    }
};