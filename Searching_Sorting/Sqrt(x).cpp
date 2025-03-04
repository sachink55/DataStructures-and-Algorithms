//leetcode-69 : Sqrt(x)

class Solution {
public:
    int mySqrt(int x) {
       int s = 0;
       int e = x;
       long long mid = s+(e-s)/2;
       int ans = -1;
       while(s<=e){
           if(mid*mid == x)
                return mid; //mid hi ans hai tab
            else if(mid * mid < x){
                ans = mid;  //ans ko store karo
                s = mid+1;  //right me jao
            }
            else
                e = mid-1;  //left me jao

            mid = s+(e-s)/2;
       }
       return ans;
    }
};