#include <string>

using namespace std;

namespace euler
{
    namespace problems
    {
        class IProblem
        {
            public:
                virtual ~IProblem() = default;
                virtual bool IsProblemSolved() = 0;
                virtual uint32_t GetProblemNumber() = 0;
                virtual string GetProblemDescription() = 0;
                virtual void SolveProblem() = 0;
                virtual string GetComputedAnswer() = 0;
                virtual string GetCorrectAnswer() = 0;
        };
    }
}
