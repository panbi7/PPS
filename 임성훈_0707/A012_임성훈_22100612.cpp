class Solution {
public:
    int countPrimes(int n) {
        if (n <= 1) return 0;
        
        // Create a boolean array "is_prime" and initialize all entries it as true.
        std::vector<bool> is_prime(n, true);
        is_prime[0] = is_prime[1] = false; // 0 and 1 are not prime numbers
        
        // Use Sieve of Eratosthenes to mark non-prime numbers.
        for (int i = 2; i * i < n; ++i) {
            if (is_prime[i]) {
                for (int j = i * i; j < n; j += i) {
                    is_prime[j] = false;
                }
            }
        }
        
        // Count primes
        int prime_count = 0;
        for (int i = 2; i < n; ++i) {
            if (is_prime[i]) {
                prime_count++;
            }
        }
        
        return prime_count;
    }
};