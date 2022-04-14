#include <string>

namespace eulerlib {
	namespace problems {
		class IProblem {
			public:
				~virtual IProblem() {}
				virtual string GetProblemDescription() = 0;
				virtual string GetAnswer() = 0;
				virtual void SolveProblem() = 0;
		};
	}
}
