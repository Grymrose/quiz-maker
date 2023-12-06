#include "../header/Quiz.hpp"

// Constructor implementation
Quiz::Quiz(int quizID, const std::string& title, bool availability, int attempts)
    : quizID(quizID), title(title), availability(availability), attempts(attempts) {}

// Setter methods implementation
void Quiz::setAvailability(bool availability) {
    this->availability = availability;
}

void Quiz::setAttempts(int attempts) {
    this->attempts = attempts;
}

// Add a question to the quiz
void Quiz::AddQuestion(Question* question) {
    questions.push_back(question);
}

// Getter method for questions
const std::vector<Question*>& Quiz::GetQuestions() const {
    return questions;
}

// Getter methods for other properties
int Quiz::GetQuizID() const {
    return quizID;
}

const std::string& Quiz::GetTitle() const {
    return title;
}

bool Quiz::IsAvailable() const {
    return availability;
}

int Quiz::GetAttempts() const {
    return attempts;
}
