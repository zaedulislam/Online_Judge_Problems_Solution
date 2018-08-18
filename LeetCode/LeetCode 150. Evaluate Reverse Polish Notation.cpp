// LeetCode 150. Evaluate Reverse Polish Notation.cpp

class Solution {
public:
    
    bool IsOperator(string str)
    {
        return (str == "+" || str == "-" || str == "*" || str == "/") ? true : false;
    }
    
    
    
    int StringToInt(string str)
    {
        int I, pos = 0, n, len = str.length();
        
        bool minus = false;
        
        if(str[0] == '-')
        {
            pos = 1;
            minus = true;
        }
            
        n = 0;
        for(I = pos; I < len; I++)
        {
            n *= 10;
            n += (str[I] - '0');
        }
        
        if(minus)
            n *= (-1);
        
        return n;
        
    }
    
    
    
    int evalRPN(vector<string>& tokens) {
        
        stack<int> S;
        
        int res = 0;
        for(int I = 0; I < tokens.size(); I++)
        {
            string str = tokens[I];
            
            if(IsOperator(str))
            {
                int operand2 = S.top();
                S.pop();
                int operand1 = S.top();
                S.pop();
                
                if(str == "+")
                    res = (operand1 + operand2);
                else if(str == "-")
                    res = (operand1 - operand2);
                else if(str == "*")
                    res = (operand1 * operand2);
                else
                    res = (operand1 / operand2);
                
                S.push(res);
            }
            else
            {
                int n = StringToInt(str);
                S.push(n);
            }
        }
        
        
        if(!S.empty())
        {
            res = S.top();
            S.pop();
        }
        
        return res;
        
    }
};