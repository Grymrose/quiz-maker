#include "../header/QuestionOutput.hpp"

void QuestionOutput::PrintQuestion(unsigned points, const std::string& question) {
    std::cout << "(" << points << " Points) " << question << std::endl;
}

void QuestionOutput::PrintPossibleAnswer(char letter, const std::string& possibleAnswer) {
    std::cout << letter << ": " << possibleAnswer << std::endl;       
}

char QuestionOutput::GetUserInputChar(const std::string& prompt) {
    std::cout << prompt;
    char input;
    std::cin >> input;
    while (std::cin.fail() || !isalpha(input)) {
        std::cin.clear();
        std::cin.ignore();
        std::cout << "Bad entry/not found. Input as a single, capital, and alphabetical input: ";
		std::cin >> input;
    }
    return input;
}

std::string QuestionOutput::GetUserInputString(const std::string& prompt) {
    std::cout << prompt;
    std::string input;
    std::cin >> input;
    return input;
}

bool QuestionOutput::GetCorrectnessFromUser() {
    std::string input = QuestionOutput::GetUserInputString("Correctness state (1 for true, 0 for false, \"SKIP\" to keep original): ");
    while (true) {
        if (input == "1") {
            return true;
        } else if (input == "0") {
            return false;
        } else if (input != "SKIP" && input != "skip") {
			std::cout << "Bad entry. Only use 0, 1, or \"SKIP\"!" << std::endl;
		}
        input = QuestionOutput::GetUserInputString("Correctness state (1 for true, 0 for false, \"SKIP\" to keep original): ");
    }
    std::cout << std::endl << std::endl;
}