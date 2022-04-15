#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>

#include "problems.h"

using namespace std;

using namespace euler::problems;

int main()
{
	vector<IProblem*> problems;

	problems.push_back(new Problem001());
	problems.push_back(new Problem002());
	problems.push_back(new Problem003());
	problems.push_back(new Problem004());

	for_each(problems.begin(), problems.end(), [](IProblem* problem)
		{
			cout << problem->GetProblemDescription() << endl;
			problem->SolveProblem();

			string computedAnswer = problem->GetComputedAnswer();
			string correctAnswer = problem->GetCorrectAnswer();

			cout << endl << "Computed answer: " + computedAnswer << endl;
			cout << "Correct answer:  " + correctAnswer << endl << endl;

			assert(correctAnswer == computedAnswer);
			delete problem;
		});

	return 0;
}
