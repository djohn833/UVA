#include <bitset>
#include <cstdio>
#include <iostream>
using namespace std;

const int MAX_PRIME = 316 + 1;
const int NUM_PRIMES = 66;

bitset<MAX_PRIME / 2 + 1> is_prime;
int primes[NUM_PRIMES] = { 2 };

void sieve()
{
	is_prime.set();

	for (int i = 3; i * i <= MAX_PRIME; i += 2)
		if (is_prime[i / 2])
			for (int j = i * i; j <= MAX_PRIME; j += 2 * i)
				is_prime[j / 2] = false;

	for (int i = 1, j = 3; j <= MAX_PRIME; j += 2)
		if (is_prime[j / 2])
			primes[i++] = j;
}

int sq(int n) { return n * n; }

int num_cases, caseno;
int n;

int main()
{
	sieve();

	cin >> num_cases;

	for (caseno = 1; caseno <= num_cases; caseno++) {
		cin >> n;

		bool pos = true;

		for (int i = 0; i < NUM_PRIMES && sq(primes[i]) <= n; i++) {
			while (n % primes[i] == 0) {
				n /= primes[i];
				if (primes[i] % 4 == 1)
					pos = !pos;
			}
		}

		if (n > 1 && n % 4 == 1)
			pos = !pos;

		printf("%c\n", pos ? '+' : '-');
	}

	return 0;
}

