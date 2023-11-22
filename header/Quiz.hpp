#ifndef __QUIZ_HEADER__
#define __QUIZ_HEADER__

#include <iostream>
#include <string>
#include <vector>

class Quiz{
private:
    int QuizID;
    string Title;
    vector <Question> Questions;
    Instructor* instructor;
    bool Availability;
    int Attempts;

public:
    Quiz();
    ~Quiz();
    
    void setAvailability(bool availability);

    void setAttempts(int attempts);
                     
    void AddQuestion(Question question);
    
}