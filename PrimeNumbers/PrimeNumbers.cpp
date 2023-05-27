
#include <iostream>
#include <cmath>

using namespace std;

bool PD_prime(long long number);
bool Mersenne_prime(int p);
bool Mersenne_Lucas_Lehmer_prime(unsigned int p);
int main()
{
    int countPrimes = 0;
    for (int i = 4000000; i < 5000001; i++)
    {
        if (PD_prime(i))
        {
            countPrimes += 1;
        }
    }
   
    cout << "Miedzy 4m a 5m mamy:" << countPrimes << " liczb pierwszych" << endl;
    cout << "i              m           PD          Mersenne" << endl;
   
    for (int i = 1; i < 32; i++)
    {
        long long m = pow(2LL, i) - 1;
        
       
        
        if (PD_prime(i) && Mersenne_prime(i))
        {

            cout << i << "        " << m << "       Yes" << "          Yes " << endl;
        }
        else if (PD_prime(i))
        {
            cout << i << "        " << m << "        Yes" << "           No " << endl;
        }
        else if (Mersenne_prime(i))
        {
            cout << i << "        " << m << "        No" << "        Yes " << endl;
        }
    }
    
}

bool PD_prime(long long number) {
    if (number <= 1) return false; // 1 is not prime
    if (number <= 3) return true; // 2 and 3 is prime
    if (number % 2 == 0 || number % 3 == 0) return false; // if can be divided by 2 or 3 it isnt prime
    long long i = 5;
    while (i * i <= number)
    {
        if (number % i == 0 || number % (i + 2) == 0)
        {
            return false;
        }
        i += 6;
        // 6 because every prime number >3 is equal to either 6k+1 or 6k-1, where k is natural number
        // it gives us numbers from 5 like 5,7,11,13 and so on...
        //
    }
    return true;
}

bool Mersenne_prime(int p) // works only for 32 bit numbers
{
    long long m = pow(2LL, p) - 1; // (2^p)-1 (LL means type of number ( long long))
    if (m <= 1) return false; // 1 is not prime
    for (int i = 2; i <= sqrt(m); i++)
    {
        if (m % i == 0)
        {
            return false;
        }
    }
    return true;
}

bool Mersenne_Lucas_Lehmer_prime(unsigned int p)
{
    if (p < 2)
    {
        return false;
    }
    unsigned long long s = 4;
    unsigned long long m = (1ULL << p) - 1;
    
    for (unsigned int i = 3; i <= p; i++)
    {
        s = ((s * s) - 2) % m;
    }

    return (s == 0 ? true : false);
}