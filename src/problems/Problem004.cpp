
#include <sstream>
#include <string>

using namespace std;

namespace euler
{
    namespace problems
    {
        class Problem004 : public IProblem
        {
        public:
            bool IsProblemSolved()
            {
                return _isProblemSolved;
            }

            uint32_t GetProblemNumber()
            {
                return 4;
            }

            string GetProblemDescription()
            {
                return
                    "Project Euler #4 - Largest Palindrome Product"
                    "\n\n"
                    "A palindromic number reads the same both ways. The "
                    "largest palindrome made from the product of two 2-digit "
                    "numbers is 9009 = 91 × 99."
                    "\n\n"
                    "Find the largest palindrome made from the product of two "
                    "3-digit numbers.";
            }

            void SolveProblem()
            {
                // Arithmetic Variables ---------------------------------------------------/

                const uint32_t ceiling = 999;
                uint32_t factor1 = ceiling;
                uint32_t factor2 = ceiling;

                uint32_t product = 0;

                const uint32_t lowerBound = 100;

                uint32_t result = 0;

                // String Manipulation / Palindrome Variables -----------------------------/

                ostringstream converter;
                string ordered;
                string reversed;

                // Begin Processing -------------------------------------------------------/

                while (factor1 >= lowerBound && factor2 >= lowerBound)
                {
                    product = factor1 * factor2;

                    converter << product;

                    ordered = converter.str();

                    // Reset the ostringstream.
                    converter.clear();
                    converter.str("");

                    reverse(ordered.begin(), ordered.end());
                    reversed = ordered;
                    reverse(ordered.begin(), ordered.end());

                    if (ordered == reversed && product > result)
                    {
                        result = product;
                    }

                    // New loop preparation.
                    if (factor1 == ceiling && factor2 == ceiling)
                    {
                        factor2--;
                    }
                    else
                    {
                        if (factor1 == factor2)
                        {
                            factor1 = ceiling;
                            factor2--;
                        }
                        else
                        {
                            factor1--;
                        }
                    }
                }

                _computedAnswer = result;
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
            uint32_t _computedAnswer;
            uint32_t _correctAnswer = 906609;
        };
    }
}
