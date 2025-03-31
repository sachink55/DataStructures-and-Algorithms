//Product of Primes - gfg

class Solution{
public:
    long long mod = 1e9+7;
    
    vector<bool> Sieve(int n){
        vector<bool> sieve(n + 1, true);
        sieve[0] = sieve[1] = false;
    
        for (int i = 2; i * i <= n; i++){
            if (sieve[i]){
                for (int j = i * i; j <= n; j += i){
                    sieve[j] = false;
                }
            }
        }
        
        return sieve;
    }

    vector<long long> segSieve(long long L, long long R){
        vector<bool> sieve = Sieve(sqrt(R));
        vector<long long> prime;
    
        for (int i = 0; i < sieve.size(); i++){
            if (sieve[i]) prime.push_back(i);
        }
    
        vector<bool> isPrime(R - L + 1, true);

        if (L == 1) isPrime[0] = false; 
        
        for(long long p : prime){
            long long smallestMul = max(p * p, (L + p - 1) / p * p);
    
            for(long long j = smallestMul; j <= R; j += p){
                isPrime[j - L] = false;
            }
        }
        
        vector<long long> ans;
        for(long long i = L; i <= R; i++){
            if(isPrime[i - L]){
                ans.push_back(i);
            }
        }
        return ans;
    }
    
    long long primeProduct(long long L, long long R){
        vector<long long> primes = segSieve(L, R);
        long long ans = 1;
        
        for(long long p : primes){
            ans = (ans * p) % mod;
        }
        
        return ans;
    }
};
