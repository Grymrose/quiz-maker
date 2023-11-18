#ifndef __QUESTION_MCQ_HEADER__
#define __QUESTION_MCQ_HEADER__

#include <iostream>
#include <string>
#include "../header/Question.hpp"

class QuestionMCQ : public Question{
protected:
    struct PossibleAnswers{
        std::string PossibleAnswer = "";
        bool Correctness = false;
        PossibleAnswers * Next = nullptr;
        PossibleAnswers(std::string PossibleAnswer) : PossibleAnswer(PossibleAnswer) {}
    };
    PossibleAnswers * MyPossibleAnswers = nullptr;
    std::string GenerateAnswerString();
public:
    QuestionMCQ(unsigned ID, unsigned Points, std::string MyQuestion);
    ~QuestionMCQ();
    void AddPossibleAnswer(std::string PossibleAnswerInput);
    void EditPossibleAnswer();
    unsigned ScoreQuestion(std::string StudentAnswer);
    void PrintQuestion(std::ostream & Out) const;
    void PrintPossibleAnswers(std::ostream & Out) const;
};

#endif