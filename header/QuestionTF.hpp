#ifndef __QUESTION_TF_HEADER__
#define __QUESTION_TF_HEADER__

#include <iostream>
#include <string>
#include "../header/Question.hpp"
#include "../header/QuestionMCQ.hpp"

class QuestionTF : public QuestionMCQ {
private:
    unsigned AnswerCount = 0;
public:
    QuestionTF(unsigned ID, unsigned Points, std::string MyQuestion);
    ~QuestionTF();
    void AddPossibleAnswer(std::string PossibleAnswerInput);
    void EditPossibleAnswer();
}

#endif