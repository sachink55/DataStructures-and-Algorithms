//leetcode-69 : Sqrt(x)

class Solution {
public:
    int mySqrt(int x) {
       int s = 0;
       int e = x;
       int ans = -1;
       
       while(s<=e){
            long long mid = s+(e-s)/2;
            if(mid*mid == x)
                return mid; //mid hi ans hai tab
            else if(mid * mid < x){
                ans = mid;  //ans ko store karo
                s = mid+1;  //right me jao
            }
            else
                e = mid-1;  //left me jao
       }
       return ans;
    }
};