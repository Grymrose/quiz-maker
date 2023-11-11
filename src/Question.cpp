#include "Question.hpp"

Question::Question() {}

Question::~Question() {}

void Question::AddOption(const std::string& option, bool isCorrect = false) {}

void Question::RemoveOption(const std::string& option) {}

void Question::EditOptions(const std::string& oldOption, const std::string& newOption, bool newCorrectStatus) {}

void Question::SetCorrectAnswer(const std::string& answer) {}

void Question::SetQuestionType(QuestionType type) {}