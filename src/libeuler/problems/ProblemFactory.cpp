#include <iostream>

#include "ProblemFactory.h"

namespace libeuler {
	namespace problems {
		void ProblemFactory::PrepareProblem(int problemNumber) {
			std::cout << "PrepareProblem() has been called with " << problemNumber << std::endl;
		}
	}
}
