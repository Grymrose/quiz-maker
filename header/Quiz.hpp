#ifndef __QUIZ_HEADER__
#define __QUIZ_HEADER__
#include "../header/Question.hpp"
#include "../header/Instructor.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <memory>

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
                     
    void AddQuestion(std::shared_ptr<Question> question);
    
};

#endif