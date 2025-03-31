// Sieve of Eratosthenes - 

//Simple Sieve
//TC: O(Nlog(logN))
//SC: O(N)

vector<bool> Sieve(int n)
{
    // create a sieve array telling isPrime till 'n'
    vector<bool> sieve(n + 1, true);
    sieve[0] = sieve[1] = false;

    /*for (int i = 2; i <= n; i++)*/
    for (int i = 2; i * i <= n; i++) // Optimisation 2: (Outer loop):
                                     // if i becomes > sqrt(N), then the
                                     // inner loop does not work.
    {
        if (sieve[i] == true)
        {
            // mark all multiples of i as non-prime.
            /*int j = i * 2;*/
            int j = i * i; // Optimisation 1 (inner loop):
                           // first unmarked number would be i*i
                           // as, other have been marked by 2 to (i - 1).
            while (j <= n)
            {
                sieve[j] = false;
                j += i;
            }
        }
    }
    return sieve;
}



// Segmented Sieve

//TYPE-1: If n is large, then we can use segmented sieve to find primes.
//TYPE-2: We've a large range [L, R] and we need to find primes in that range.

//TC: O(sqrt(R) * log(log(sqrt(R))) + (R - L + 1) * log(log(sqrt(R)))) => O(Rlog(log(R)))
//SC: O(sqrt(R) + (R - L + 1)) => O(R)

vector<bool> Sieve(int n){
    vector<bool> sieve(n + 1, true);
    sieve[0] = sieve[1] = false;

    for (int i = 2; i * i <= n; i++){
        if (sieve[i] == true){
            int j = i * i; 
            while (j <= n){
                sieve[j] = false;
                j += i;
            }
        }
    }
    return sieve;
}

void segSieve(int L, int R){
    vector<bool> sieve = Sieve(sqrt(R));
    vector<long long> prime;

    for (int i = 0; i < sieve.size(); i++){
        if (sieve[i]) prime.push_back(i);
    }

    vector<bool> isPrime(R - L + 1, true);
    if (L == 1) isPrime[0] = false; 

    for(long long p : prime){
        // long long smallestMul = (L / p) * p;
        // if(smallestMul < L){
        //     smallestMul += p;
        // }
        long long smallestMul = max(p * p, (L + p - 1) / p * p);

        for(long long j = smallestMul; j <= R; j += p){
            isPrime[j - L] = false;
        }
    }

    for(long long i=L; i<=R; i++){
        if(isPrime[i-L]){
            cout << i << " ";
        }
    }
}
