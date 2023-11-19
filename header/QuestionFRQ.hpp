#ifndef __QUESTION_FRQ_HEADER__
#define __QUESTION_FRQ_HEADER__

#include <iostream>
#include <string>
#include "../header/Question.hpp"
#include "../header/QuestionOutput.hpp"

class QuestionFRQ : public Question{
private:
    std::string PossibleAnswer = "";
public:
    QuestionFRQ(unsigned ID, unsigned PossiblePoints, std::string MyQuestion);
    ~QuestionFRQ();
    void AddPossibleAnswer(std::string InputAnswer);
    void EditPossibleAnswer();
    unsigned ScoreQuestion(std::string StudentAnswer);
    void PrintQuestion() const;
};

#endif