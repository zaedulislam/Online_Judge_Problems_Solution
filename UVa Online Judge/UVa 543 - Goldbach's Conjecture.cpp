// UVa 543 - Goldbach's Conjecture.cpp
#include <iostream>
#include <cmath>
using namespace std;

// prime[i] = 0, if i is prime
// prime[i] = 1, if i is not a prime

int prime[1000000]; // Declared globally,thus automatically assigned initially 0 to every element of the array.

void primeGenerate()
{
	int I, K, sqrtN = int(sqrt((double)1000000));
	//memset(prime, 1, sizeof(prime));
	prime[0] = prime[1] = 1;    // Since, 0 isn't prime either composite

	for (I = 2; I <= sqrtN; I++) // Have to check primes up to (sqrt(N))
	{
		if (prime[I] == 0){
			/*so, index is a prime, so, discard all the multiples.
			 K = I * I, because its the first number to be colored.*/
			for (K = I * I; K <= 1000000; K += I)
				prime[K] = 1;
		}
	}
}

int main()
{
	primeGenerate();
	int even_integer = -1, I , range;
	while (even_integer != 0)
	{
		cin >> even_integer;
		if (even_integer == 0)
			break;
		bool verified = false;
		range = even_integer / 2;

		for (I = 3; I <= range; I++)
		{
			if (!(prime[I]) && !(prime[even_integer - I])){
				verified = true;
				break;
			}
		}
		if (verified == true)
			cout << even_integer << " = " << I << " + " << even_integer - I << endl;
		else
			cout << "Goldbach's conjecture is wrong."<< endl;
	}
	return 0;
}

