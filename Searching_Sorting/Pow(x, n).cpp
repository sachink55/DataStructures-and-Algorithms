//leetcdoe-50 : Pow(x, n)

//Approach-1 : Brute Force
//TC : O(n)
//SC : O(1)
class Solution {
public:
    double myPow(double x, int n) {
        int nn = abs(n);
        double ans = 1.0;
        while(nn--){
            ans *= x;
        }
        return n>0 ? ans : (1/ans);
    }
};


//Approach-2 : Binary Exponentiation
//TC : O(logn)
//SC : O(l)

class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1.0;
        long long nn = n;
        if(n<0) nn *= -1;

        while(nn){
            //exponent nn is odd
            if(nn%2==1){
                ans = ans *x;
                nn--;
            } 
            else{
                //exponent nn is even
                x *= x;
                nn /= 2;
            }
        }
        return n>0 ? ans : (1/ans);
    }
};