#include <iostream>
#include <vector>

std::vector<int> rec(int NumberOfRowsLeft) {
	if (NumberOfRowsLeft == 1) {
		std::vector<int> array = { 1 };
		std::cout << "[1]\n";
		return array;
	}
	std::vector<int> LastCall = rec(NumberOfRowsLeft - 1);
	std::vector<int> CurrentCall;
	CurrentCall.push_back(LastCall[LastCall.size() - 1]);
	for (int currentRow = 0; currentRow < NumberOfRowsLeft - 1; currentRow++) {
		CurrentCall.push_back(CurrentCall[currentRow] + LastCall[currentRow]);
	}
	std::cout << "[";
	for (int i = 0; i < CurrentCall.size(); i++) {
		std::cout << CurrentCall[i];
		if (i != CurrentCall.size() - 1) {
			std::cout << ", ";
		}
	}
	std::cout << "]\n";
	return CurrentCall;
}

int main() {
	int numberOfRows = 7;
	std::cout << "Aitken's array of " << numberOfRows << ":\n\n";
	rec(numberOfRows);
	return 0;
}
