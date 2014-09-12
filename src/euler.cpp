#include <iostream>
#include <cstdlib>

#include "libeuler/problems/ProblemFactory.h"

void solveProblem(int problemNum);

int main(int argc, char* argv[]) {

	int problemNum = 0;

	if(argc > 1) {
		problemNum = atoi(argv[1]);

		if(problemNum != 0) {
			solveProblem(problemNum);
		}
		else {
			std::cout << "I don't believe Project Euler has a problem of that number." << std::endl;
		}
	}
	else {
		std::cout << "Please provide the number of a Project Euler problem that you would like me to solve." << std::endl;
	}

	return 0;
}

void solveProblem(int problemNum) {
	libeuler::problems::ProblemFactory::PrepareProblem(problemNum);
}
