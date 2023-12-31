#ifndef __QUESTION_TF_HEADER__
#define __QUESTION_TF_HEADER__

#include <string>
#include "../header/Question.hpp"
#include "../header/QuestionMCQ.hpp"
#include "../header/QuestionOutput.hpp"

class QuestionTF : public QuestionMCQ {
private:
    unsigned AnswerCount = 0;
public:
    QuestionTF(unsigned ID, unsigned Points, std::string InputQuestion);
    ~QuestionTF();
    void AddPossibleAnswer(std::string PossibleAnswerInput);
    void EditPossibleAnswer();
};

#endif