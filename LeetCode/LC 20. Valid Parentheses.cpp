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
        stack<char> stck;

        for(auto ch: s){
            if(ch == '(' || ch == '{' || ch == '['){
                stck.push(ch);
            } else{
                if(stck.empty()){
                    return false;
                }

                char top = stck.top();
                if(isMatch(top, ch)){
                    stck.pop();
                } else{
                    return false;
                }
            }
        }

        return stck.empty();
    }
};
