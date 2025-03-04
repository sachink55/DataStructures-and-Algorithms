//Divide Using Binary Search

//Q2. Divide two numbers & give integer output 

//divisor * quotient <= dividend

int getQuotient(int dividend, int divisor ){
    int s = 0; int e = dividend;
    int mid = s + (e-s)/2; int ans = -1;

    while(s <= e){
        if(mid * divisor == dividend){
            return mid;
        }
        else if(mid * divisor < dividend){
            ans = mid; //ans ko store karo
            s = mid + 1; //right me jao
        }
        else{
            e = mid-1; //left me jao
        }

        mid = s+(e-s)/2;
    }
    return ans;
}