class Solution {
public:
    bool isValid(string expression) {
        stack<char> stck;
        int expressionLength = expression.length();

        for (int I = 0; I < expressionLength; I++){
            if (expression[I] == '(' || expression[I] == '{' || expression[I] == '[') {
                stck.push(expression[I]);
            }
            else {
                if (stck.empty()) {
                    return false;
                }

                if (stck.top() == '(' && expression[I] == ')') {
                    stck.pop();
                }
                else if (stck.top() == '{' && expression[I] == '}') {
                    stck.pop();
                }
                else if (stck.top() == '[' && expression[I] == ']') {
                    stck.pop();
                }
                else {
                    return false;
                }	
            }
        }

        return stck.empty() ? true : false;
    }
};
