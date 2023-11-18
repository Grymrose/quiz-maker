#include "../header/QuestionOutput.hpp"

void QuestionOutput::PrintQuestion(unsigned points, const std::string& question) {
    std::cout << "(" << points << " Points) " << question << "\n";
}

void QuestionOutput::PrintPossibleAnswers(const std::string& output) {
    std::cout << output << "\n";
}

void QuestionOutput::PrintTFSpecific(const std::string& specificOutput) {
    std::cout << "TF-specific: " << specificOutput << "\n";
}

void QuestionOutput::PrintMCQSpecific(const std::string& specificOutput) {
    std::cout << "MCQ-specific: " << specificOutput << "\n";
}