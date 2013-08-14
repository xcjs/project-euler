#include <iostream>
#include <cmath>

/*
	stdint.h is included for standard width integers. In some 64 bit 
	environments, the long type is 8 bytes long, but in almost all 32
	bit environments, the long type is 4 bytes long.

	Using standard int widths eases cross-platform compatibility.

	It is worth noting that in GCC, passing -mx32 will use 32 bit 
	pointers for int and long data types. Passing -m32 will generate
	32 bit code. 
*/
#include <stdint.h>	// Included for standardized integer widths. For GCC, use -mx32 to use 

using namespace std;

/*
	Project Euler #3 - Largest prime factor

	The prime factors of 13195 are 5, 7, 13 and 29.

	What is the largest prime factor of the number 600851475143 ?
*/
	
uint64_t getNextPrime(uint64_t);
bool isPrime(uint64_t);

int main()
{
	const uint64_t composite = 600851475143;
	uint64_t squareRoot = sqrt((double) composite);

	uint64_t prime = 2;
	uint64_t largestPrime;

	uint64_t quotient = composite;

	while (prime <= squareRoot)
	{
		if(quotient % prime == 0)
		{
			quotient /= prime;

			if(isPrime(quotient))
			{
				largestPrime = quotient;
				break;
			}
		}
		else
			prime = getNextPrime(prime);			
	}

	cout << largestPrime << endl;

	return 0;
}

uint64_t getNextPrime(uint64_t num)
{
	int origNum = num;

	if(num % 2 == 0 || num == 1)
	{
		num += 1;

		if(!isPrime(num))
			num = getNextPrime(num);
	}
	else
	{
		while(num == origNum || !isPrime(num))
		{
			num += 2;
		}
	}

	return num;
}

bool isPrime(uint64_t num)
{
	// 1 is an exceptional case - it is an odd number that is only divisible by 
	// one and itself that is not prime.
	if (num == 1) return false;
	// 2 is an exceptional case - it is an even number divided by 1 and itself,
	// so it is a prime number.
	if (num == 2) return true;

	bool prime = true;
	uint64_t i = 2;

	if(num % 2 != 0)
	{
		while(i <= sqrt((double)num))
		{			
			if(num % i == 0)
				prime = false;

			if(i == 2)
				i++;
			else
				i += 2;
		} 
	}
	else
		prime = false;

	return prime;
}
