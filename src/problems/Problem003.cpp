
#include <cmath>
#include <string>

using namespace std;

namespace euler
{
    namespace problems
    {
        class Problem003 : public IProblem
        {
        public:
            bool IsProblemSolved()
            {
                return _isProblemSolved;
            }

            uint32_t GetProblemNumber()
            {
                return 3;
            }

            string GetProblemDescription()
            {
                return
                    "Project Euler #3 - Largest Prime Factor"
                    "\n\n"
                    "The prime factors of 13195 are 5, 7, 13 and 29."
                    "\n\n"
                    "What is the largest prime factor of the number "
                    "600851475143?";
            }

            void SolveProblem()
            {
                const uint64_t composite = 600851475143;
                uint64_t squareRoot = sqrt((double)composite);

                uint64_t prime = 2;
                uint64_t largestPrime = 0;

                uint64_t quotient = composite;

                while (prime <= squareRoot)
                {
                    if (quotient % prime == 0)
                    {
                        quotient /= prime;

                        if (isPrime(quotient))
                        {
                            largestPrime = quotient;
                            break;
                        }
                    }
                    else
                        prime = getNextPrime(prime);
                }

                _computedAnswer = largestPrime;
                _isProblemSolved = true;
            }

            string GetComputedAnswer()
            {
                return to_string(_computedAnswer);
            }

            string GetCorrectAnswer()
            {
                return to_string(_correctAnswer);
            }

        private:
            bool _isProblemSolved = false;
            uint64_t _computedAnswer;
            uint64_t _correctAnswer = 6857;

            uint64_t getNextPrime(uint64_t num)
            {
                uint64_t origNum = num;

                if (num % 2 == 0 || num == 1)
                {
                    num += 1;

                    if (!isPrime(num))
                        num = getNextPrime(num);
                }
                else
                {
                    while (num == origNum || !isPrime(num))
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
                if (num == 1)
                    return false;
                // 2 is an exceptional case - it is an even number divided by 1 and itself,
                // so it is a prime number.
                if (num == 2)
                    return true;

                bool prime = true;
                uint64_t i = 2;

                if (num % 2 != 0)
                {
                    while (i <= sqrt((double)num))
                    {
                        if (num % i == 0)
                            prime = false;

                        if (i == 2)
                            i++;
                        else
                            i += 2;
                    }
                }
                else
                    prime = false;

                return prime;
            }
        };
    }
}
