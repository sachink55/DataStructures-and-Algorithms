
long long int mod = 1e9 + 7;

//TC: O(log(n))
//SC: O(1)

int fastExponentiation(int x, int n){
    long long int ans = 1;
    while (n > 0){
        if (n & 1){ // n is odd.
            ans = (ans * x) % mod;
        }
        // n is even.
        x = (x * x) % mod;
        n >>= 1;    // n = n / 2;
    }
    return ans % mod;
}

//TC: O(n)
//SC: O(1)
int slowExponentiation(int a, int b){
    int ans = 1;
    while (b--){
        ans *= a;
    }
    return ans;
}

int main()
{
    int a = 5;
    int b = 4;

    cout << slowExponentiation(a, b) << endl;
    cout << fastExponentiation(a, b) << endl;
    return 0;
}