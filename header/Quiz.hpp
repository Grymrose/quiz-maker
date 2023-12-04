#ifndef __QUIZ_HEADER__
#define __QUIZ_HEADER__
#include "../header/Question.hpp"
#include <iostream>
#include <string>
#include <vector>

class Quiz{
private:
    int QuizID;
    std::string Title;
    std::vector<std::shared_ptr<Question>> Questions;
    Instructor* instructor;
    bool Availability;
    int Attempts;

public:
    Quiz();
    ~Quiz();
    
    void setAvailability(bool availability);

    void setAttempts(int attempts);
                     
    void AddQuestion(Question question);
    
};

#endif