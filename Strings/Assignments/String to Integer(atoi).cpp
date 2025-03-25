//leetcode-8 : String to Integer (atoi)

class Solution {
public:
    int myAtoi(string s) {
        int num = 0, i= 0, sign = 1;//(+ve)

        //ignoring leading whitespaces
        while(i < s.size() && s[i] == ' '){
            i++;
        }

        //check sign - break after found the first sign
        while(i < s.size() && (s[i] == '+' || s[i] == '-')){
            sign = (s[i] == '+')?1:-1;
            i++;
            break;
        }

        //INT_MAX(2^31-1) = 2147483647 and INT_MIN(-2^31) = 2147483648
        //num in dono ke bahar nahi hona chahiye
        while(i < s.size() && isdigit(s[i])){
            //check overflow
            if(num > INT_MAX/10 || (num == INT_MAX/10) && s[i] > '7'){
                //num = 214748365, num*10 + x > INT_MAX
                //num = 214748364, num*10 + 8 > INT_MAX
                  
                return (sign==-1) ? INT_MIN:INT_MAX;
            }

            num = num*10 + (s[i]-'0');
            ++i;
        }
        return (sign==-1) ? -num : num;
    }
};