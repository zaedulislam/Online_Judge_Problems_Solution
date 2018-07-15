// LeetCode 537. Complex Number Multiplication.cpp

class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        
        int I, len, posPlus = -1, a_real, a_complex, b_real, b_complex, ab_real, ab_rc, ab_cr, ab_cc, complex;
        bool plus, minus;
        string str, ans;
        
        
        /// For Real part of a
        len = a.length();
        for(I = 0; I < len; I++)
        {
            if(a[I] == '+')
            {
                posPlus = I;
                break;
            }
        }
        
        if(posPlus == -1)
            a_real = 0;
        else
        {
            str = "";
            minus = false;
            for(I = 0; I < posPlus; I++)
            {
                if(a[I] == '-')
                    minus = true;
                else
                    str += a[I];
            }
            
            a_real = 0;
            len = str.length();
            for(I = 0; I < len; I++)
            {
                a_real *= 10;
                a_real += str[I] - '0';
            }
            
            if(minus)
                a_real *= (-1);                
        }
        
        /// For Complex part of a
        len = a.length();
        str = "";
        minus = false;
        for(I = posPlus + 1; I < len; I++)
        {
            if(a[I] == '-')
                minus = true;
            else if(a[I] != 'i')
                str += a[I];
        }
        
        a_complex = 0;
        len = str.length();
        for(I = 0; I < len; I++)
        {
            a_complex *= 10;
            a_complex += str[I] - '0';
        }

        if(minus)
            a_complex *= (-1);
        
 
        /// For Real part of b
        posPlus = -1;
        len = b.length();
        for(I = 0; I < len; I++)
        {
            if(b[I] == '+')
            {
                posPlus = I;
                break;
            }
        }
        
        if(posPlus == -1)
            b_real = 0;
        else
        {
            str = "";
            minus = false;
            for(I = 0; I < posPlus; I++)
            {
                if(b[I] == '-')
                    minus = true;
                else
                    str += b[I];
            }
            
            b_real = 0;
            len = str.length();
            for(I = 0; I < len; I++)
            {
                b_real *= 10;
                b_real += str[I] - '0';
            }
            
            if(minus)
                b_real *= (-1);                
        }
        
        
        /// For Complex part of b
        len = b.length();
        str = "";
        minus = false;
        for(I = posPlus + 1; I < len; I++)
        {
            if(b[I] == '-')
                minus = true;
            else if(b[I] != 'i')
                str += b[I];
        }
        
        b_complex = 0;
        len = str.length();
        for(I = 0; I < len; I++)
        {
            b_complex *= 10;
            b_complex += str[I] - '0';
        }

        if(minus)
            b_complex *= (-1);

        
        ab_real = a_real * b_real;
        ab_rc = a_real * b_complex;
        ab_cr = a_complex * b_real;
        ab_cc = a_complex * b_complex;
        
        
        if(ab_cc != 0)
        {
            ab_cc *= (-1);
            ab_real += ab_cc;
        }
        
        ans = "";
        if(ab_real < 0)
        {
            ans += '-';
            ab_real *= (-1);
        }
        
        if(ab_real == 0)
            ans += '0';
        else
        {
            str = to_string(ab_real);
            ans += str;
        }
        
        ans += '+';
        complex = ab_rc + ab_cr;
        
        
        if(complex < 0)
        {
            ans += '-';   
            complex *= (-1);
        }
        
        if(complex == 0)
            ans += '0';
        else
        {
            str = to_string(complex);
            ans += str;
        }
        
        ans += 'i';
        
        return ans;
        
    }
};