#include "../header/Quiz.hpp"
Quiz::Quiz() {
    QuizID = 0;
    Title = "";
    instructor = nullptr;
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