class Solution {
public:
    bool isMatch(char top, char current){
        if(top == '(' && current == ')'
        || top == '{' && current == '}'
        || top == '[' && current == ']'){
            return true;
        }

        return false;
    }


    bool isValid(string s) {
        int expressionLength = s.length();
        int top = -1;

        for(auto ch: s){
            if(ch == '(' || ch == '{' || ch == '['){
                ++top;
                s[top] = ch;
            } else{
                if(top < 0){
                    return false;
                }

                if(isMatch(s[top], ch)){
                    top--;
                } else{
                    return false;
                }
            }
        }

        return top == -1;
    }
};
