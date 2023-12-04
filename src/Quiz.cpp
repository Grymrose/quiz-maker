#include "../header/Quiz.hpp"
#include <iostream>
Quiz::Quiz() {
    QuizID = 0;
    Title = "";
    Availability = false;
    Attempts = 1; 
}

Quiz::~Quiz() {
    
}

void Quiz::setAvailability(bool availability) {
    Availability = availability;
}

void Quiz::setAttempts(int attempts) {
    Attempts = attempts;
}

void Quiz::AddQuestion(std::shared_ptr<Question> question) {
    Questions.push_back(question);
}