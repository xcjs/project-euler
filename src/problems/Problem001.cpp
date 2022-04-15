#include <string>

using namespace std;

namespace euler
{
    namespace problems
    {
        class Problem001 : public IProblem
        {
            public:
                bool IsProblemSolved()
                {
                    return _isProblemSolved;
                }

                uint32_t GetProblemNumber()
                {
                    return 1;
                }

                string GetProblemDescription(){
                    return
                        "Project Euler #1 - Multiples of 3 or 5"
                        "\n\n"
                        "If we list all the natural numbers below 10 that are "
                        "multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of "
                        "these multiples is 23. Find the sum of all the "
                        "multiples of 3 or 5 below 1000.";
                }

                void SolveProblem()
                {
                    const unsigned int limit = 1000;
                    unsigned int i = 0;
                    unsigned int sum = 0;

                    while (i < limit)
                    {
                        if (i % 3 == 0 || i % 5 == 0)
                            sum += i;

                        i++;
                    }

                    _computedAnswer = sum;
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
                uint32_t _correctAnswer = 233168;
        };
    }
}
